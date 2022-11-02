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

echo "<INFO> Preparing OCCU..."
mkdir -v /etc/config
rm -rv /etc/config/firmware
rm -rv /firmware
ln -sv $PDATA/occu/firmware /etc/config/firmware
ln -sv $PDATA/occu/firmware /firmware
rm -rv /etc/config/InterfacesList.xml
ln -sv $PCONFIG/InterfacesList.xml /etc/config/InterfacesList.xml
rm -rv /var/status
ln -sv /tmp /var/status
rm -rv /opt/HMServer
rm -rv /opt/HmIP
ln -sv $PDATA/HMserver/HMServer /opt/HMServer
ln -sv $PDATA/HMserver/HmIP /opt/HmIP

echo "<INFO> Configuring rsyslogd for RFD..."
rm -v /etc/rsyslog.d/40-$PDIR-rfd.conf
ln -sv $PCONFIG/rsyslog-rfd.conf /etc/rsyslog.d/40-$PDIR-rfd.conf 
rm -v /etc/rsyslog.d/40-$PDIR-multimacd.conf
ln -sv $PCONFIG/rsyslog-multimacd.conf /etc/rsyslog.d/40-$PDIR-multimacd.conf 
systemctl restart rsyslog.service

echo "<INFO> Configuring serial interface..."
if cat /boot/config.txt | grep -qe "^core_freq="; then
	echo "<INFO> Removing core_freq= from /boot/config.txt"
	/bin/sed -i 's|^core_freq=|#core_freq=|g' /boot/config.txt
else
	echo "<INFO> core_freq= not found in /boot/config.txt. That's OK."
fi

if cat /boot/config.txt | grep -qe "^init_uart_clock="; then
	echo "<INFO> Removing init_uart_clock= from /boot/config.txt"
	/bin/sed -i 's|^init_uart_clock=|#init_uart_clock=|g' /boot/config.txt
else
	echo "<INFO> init_uart_clock= not found in /boot/config.txt. That's OK."
fi

if ! cat /boot/config.txt | grep -qe "^enable_uart="; then
	echo "<INFO> Adding enable_uart=1 to /boot/config.txt"
	echo "" >> /boot/config.txt
	echo "enable_uart=1" >> /boot/config.txt
else
	echo "<INFO> Replacing enable_uart with enable_uart=1 in /boot/config.txt"
	/bin/sed -i 's#enable_uart=\(.*\)#enable_uart=1#g' /boot/config.txt
	/bin/sed -i 's#enable_uart="\(.*\)"#enable_uart=1#g' /boot/config.txt
fi

if ! cat /boot/config.txt | grep -qe "^dtoverlay=pi3-disable-bt" && ! cat /boot/config.txt | grep -qe "^dtoverlay=pi3-miniuart-bt"; then
	echo "<INFO> Adding dtoverlay=pi3-miniuart-bt to /boot/config.txt"
	echo "" >> /boot/config.txt
	echo "dtoverlay=pi3-miniuart-bt" >> /boot/config.txt
else
	echo "<INFO> dtoverlay=pi3-miniuart-bt or dtoverlay=pi3-disable-bt already set in /boot/config.txt"
fi


if cat /boot/config.txt | grep -qe "^#dtparam=i2c_arm="; then
	echo "<INFO> Adding dtparam=i2c_arm=on to /boot/config.txt"
	/bin/sed -i 's|^#dtparam=i2c_arm=\(.*\)|dtparam=i2c_arm=on|g' /boot/config.txt
elif cat /boot/config.txt | grep -qe "^dtparam=i2c_arm=off"; then
	echo "<INFO> Adding dtparam=i2c_arm=on to /boot/config.txt"
	/bin/sed -i 's|^dtparam=i2c_arm=\(.*\)|dtparam=i2c_arm=on|g' /boot/config.txt
elif cat /boot/config.txt | grep -qe "^dtparam=i2c_arm="; then
	echo "<INFO> Adding dtparam=i2c_arm=on to /boot/config.txt"
	/bin/sed -i 's|^dtparam=i2c_arm=\(.*\)|dtparam=i2c_arm=on|g' /boot/config.txt
elif ! cat /boot/config.txt | grep -qe "dtparam=i2c_arm"; then
	echo "<INFO> Adding dtparam=i2c_arm=on to /boot/config.txt"
	echo "" >> /boot/config.txt
	echo "dtparam=i2c_arm=on" >> /boot/config.txt
else
	echo "<INFO> dtparam=i2c_arm=on already set in /boot/config.txt"
fi

echo "<INFO> Disabling serial console in /boot/cmdline.txt"
/bin/sed -i /boot/cmdline.txt -e "s/console=ttyAMA0,[0-9]\+ //"
/bin/sed -i /boot/cmdline.txt -e "s/console=serial0,[0-9]\+ //"

if cat /boot/config.txt | grep -qe "^#dtoverlay=pivccu-raspberrypi"; then
	echo "<INFO> Adding dtoverlay=pivccu-raspberrypi to /boot/config.txt"
	/bin/sed -i 's|^#dtoverlay=pivccu-raspberrypi.*|dtoverlay=pivccu-raspberrypi|g' /boot/config.txt
elif ! cat /boot/config.txt | grep -qe "dtoverlay=pivccu-raspberrypi"; then
	echo "<INFO> dtoverlay=pivccu-raspberrypi to /boot/config.txt"
	echo "" >> /boot/config.txt
	echo "dtoverlay=pivccu-raspberrypi" >> /boot/config.txt
else
	echo "<INFO> dtoverlay=pivccu-raspberrypi already set in /boot/config.txt"
fi

echo "<INFO> Installing Kernel Modules"
if [[ -e $PDATA/kernel/$(uname -r) ]]; then
	mkdir -v -p /lib/modules/$(uname -r)/extra
	cp -v $PDATA/kernel/$(uname -r)/* /lib/modules/$(uname -r)/extra
	depmod -a
	cp -v $PDATA/kernel/pivccu-raspberrypi.dtbo /boot/overlays
else 
	echo "<ERROR> Do not have any kernel modules for $(uname -r). The Plugin will not work without kernel modules."
fi

exit 0
