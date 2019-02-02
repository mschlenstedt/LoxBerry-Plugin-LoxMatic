#!/bin/bash

if [ "$UID" -ne 0 ]; then
	echo "This script has to be run as root."
	exit
fi

PLUGINNAME=REPLACELBPPLUGINDIR

export HM_HOME=$LBPDATA/$PLUGINNAME/occu/arm-gnueabihf/packages-eQ-3/LinuxBasis
export LD_LIBRARY_PATH=$LBPDATA/$PLUGINNAME/occu/arm-gnueabihf/packages-eQ-3/LinuxBasis/lib/:$LBPDATA/$PLUGINNAME/occu/arm-gnueabihf/packages-eQ-3/RFD/lib

# Kill existing RFD
if pgrep -f bin/rfd > /dev/null 2>&1 ; then
	pkill -f bin/rfd
	sleep 0.1
	pkill -9 -f bin/rfd
fi

# Kill existing multimacd
if pgrep -f bin/multimacd > /dev/null 2>&1 ; then
	pkill -f bin/multimacd
	sleep 0.1
	pkill -9 -f bin/multimacd
fi

# Kill existing HM2MQTT
if pgrep -f hm2mqtt/index.js > /dev/null 2>&1 ; then
        pkill -f hm2mqtt/index.js
        sleep 0.1
        pkill -9 -f hm2mqtt/index.js
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
