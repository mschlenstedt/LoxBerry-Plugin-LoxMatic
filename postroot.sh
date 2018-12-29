#!/bin/bash

# To use important variables from command line use the following code:
COMMAND=$0    # Zero argument is shell command
PTEMPDIR=$1   # First argument is temp folder during install
PSHNAME=$2    # Second argument is Plugin-Name for scipts etc.
PDIR=$3       # Third argument is Plugin installation folder
PVERSION=$4   # Forth argument is Plugin version
#LBHOMEDIR=$5 # Comes from /etc/environment now. Fifth argument is
              # Base folder of LoxBerry
PTEMPPATH=$6  # Sixth argument is full temp path during install (see also $1)

# Combine them with /etc/environment
PCGI=$LBPCGI/$PDIR
PHTML=$LBPHTML/$PDIR
PTEMPL=$LBPTEMPL/$PDIR
PDATA=$LBPDATA/$PDIR
PLOG=$LBPLOG/$PDIR # Note! This is stored on a Ramdisk now!
PCONFIG=$LBPCONFIG/$PDIR
PSBIN=$LBPSBIN/$PDIR
PBIN=$LBPBIN/$PDIR

echo "<INFO> Installation as root user started."

echo "<INFO> Stopping any running instance of RFD..."
killall rfd

echo "<INFO> Preparing OCCU..."
mkdir -v /etc/config
ln -sv $PDATA/occu/firmware /etc/config/firmware
rm -rv /var/status
ln -sv /tmp /var/status

echo "<INFO> Configuring rsyslogd for RFD..."
rm -v /etc/rsyslog.d/40-$PDIR.conf
ln -sv $PCONFIG/rsyslog.conf /etc/rsyslog.d/40-$PDIR.conf 
systemctl restart rsyslog.service

echo "<INFO> Configuring serial interface..."
if ! cat /boot/config.txt | grep -qe "^core_freq="; then
	echo "<INFO> Adding core_freq=250 to /boot/config.txt"
	echo "core_freq=250" >> /boot/config.txt
else
	echo "<INFO> Replacing core_freq with core_freq=250 at /boot/config.txt"
	/bin/sed -i 's#core_freq=\(.*\)#core_freq=250#g' /boot/config.txt
	/bin/sed -i 's#core_freq="\(.*\)"#core_freq=250#g' /boot/config.txt
fi

if ! cat /boot/config.txt | grep -qe "^init_uart_clock="; then
	echo "<INFO> Adding init_uart_clock=48000000 to /boot/config.txt"
	echo "init_uart_clock=48000000" >> /boot/config.txt
else
	echo "<INFO> Replacing init_uart_clock with init_uart_clock=48000000 at /boot/config.txt"
	/bin/sed -i 's#init_uart_clock=\(.*\)#init_uart_clock=48000000#g' /boot/config.txt
	/bin/sed -i 's#init_uart_clock="\(.*\)"#init_uart_clock=48000000#g' /boot/config.txt
fi

if ! cat /boot/config.txt | grep -qe "^enable_uart="; then
	echo "<INFO> Adding enable_uart=1 to /boot/config.txt"
	echo "enable_uart=1" >> /boot/config.txt
else
	echo "<INFO> Replacing enable_uart with enable_uart=1 at /boot/config.txt"
	/bin/sed -i 's#enable_uart=\(.*\)#enable_uart=1#g' /boot/config.txt
	/bin/sed -i 's#enable_uart="\(.*\)"#enable_uart=1#g' /boot/config.txt
fi

if ! cat /boot/config.txt | grep -qe "^dtoverlay=pi3-disable-bt" && ! cat /boot/config.txt | grep -qe "^dtoverlay=pi3-miniuart-bt"; then
	echo "<INFO> Adding dtoverlay=pi3-miniuart-bt to /boot/config.txt"
	echo "dtoverlay=pi3-miniuart-bt" >> /boot/config.txt
else
	echo "<INFO> dtoverlay=pi3-miniuart-bt or dtoverlay=pi3-disable-bt already set in /boot/config.txt"
fi

exit 0
