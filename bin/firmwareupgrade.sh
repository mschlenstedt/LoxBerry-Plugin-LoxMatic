#!/bin/bash

if [ "$UID" -ne 0 ]; then
	echo "This script has to be run as root."
	exit
fi

PLUGINNAME=REPLACELBPPLUGINDIR

export HM_HOME=$LBPDATA/$PLUGINNAME/occu/arm-gnueabihf/packages-eQ-3/LinuxBasis
export LD_LIBRARY_PATH=$LBPDATA/$PLUGINNAME/occu/arm-gnueabihf/packages-eQ-3/LinuxBasis/lib/:$LBPDATA/$PLUGINNAME/occu/arm-gnueabihf/packages-eQ-3/RFD/lib

# Kill existing RFD
if pgrep -f packages-eQ-3/RFD/bin/rfd > /dev/null 2>&1 ; then
	pkill -f packages-eQ-3/RFD/bin/rfd
	sleep 1
	pkill -9 -f packages-eQ-3/RFD/bin/rfd
fi

# Create a new entry for the logfile (for logmanager)
. $LBHOMEDIR/libs/bashlib/loxberry_log.sh
PACKAGE=loxmatic
NAME=firmware
LOGDIR=$LBPLOG/$PLUGINNAME
STDERR=1
LOGSTART "Firmware upgrade started."
LOGINF "Starting Firmware Upgrade."

# Start Firmware Upgrade
$HM_HOME/bin/eq3configcmd update-coprocessor -p /dev/ttyAMA0 -l 1 -c -t HM-MOD-UART -d $LBPDATA/$PLUGINNAME/occu/firmware/HM-MOD-UART -u >> ${FILENAME} 2>&1

LOGEND
