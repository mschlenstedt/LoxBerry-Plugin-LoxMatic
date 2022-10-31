#!/bin/bash

PLUGINNAME=REPLACELBPPLUGINDIR

if [ "$UID" -ne 0 ]; then
	echo "This script has to be run as root."
	exit
fi

# Source HM environment
[[ -r $LBPCONFIG/$PLUGINNAME/hm_env ]] && . $LBPCONFIG/$PLUGINNAME/hm_env

export HM_HOME=$LBPDATA/$PLUGINNAME/occu/arm-gnueabihf/packages-eQ-3/RFD
export LD_LIBRARY_PATH=$HM_HOME/lib

# Kill existing RFD
if pgrep -f bin/rfd > /dev/null 2>&1 ; then
	pkill -f bin/rfd
	sleep 0.1
	pkill -9 -f bin/rfd
fi

# Create a new entry for the logfile (for logmanager)
. $LBHOMEDIR/libs/bashlib/loxberry_log.sh
PACKAGE=$PLUGINNAME
NAME=rfd
FILENAME=$LBPLOG/$PLUGINNAME/rfd.log
APPEND=1
LOGSTART "RFD daemon started."
LOGOK "RFD daemon started."
cat $LBPCONFIG/$PLUGINNAME/hm_env >> $LBPLOG/$PLUGINNAME/rfd.log
# skip this startup if not in normal mode
if [[ "${HM_MODE}" != "NORMAL" ]]; then
	LOGERR "HM environment was not started successfully"
	LOGEND
	exit 1
fi
LOGEND

# Loglevel
DEBUG=$(jq -r '.Debug' $LBPCONFIG/$PLUGINNAME/loxmatic.json)
if [ "$DEBUG" = "true" ] || [ "$DEBUG" = "1" ]; then
	LEVEL="0"
else
	LEVEL="2"
fi

# Patch config
# only modify if real rf module found
if [[ "${HM_HMRF_DEV}" == "HM-MOD-RPI-PCB" ]] ||
   [[ "${HM_HMRF_DEV}" == "RPI-RF-MOD" ]]; then
	# make sure [Interface 0] is uncommented
	sed -i -e '/^#\[Interface 0\]/,/^#\s*$/ s/^#//' $LBPCONFIG/$PLUGINNAME/rfd.conf

	# patch some settings to match what this hardware expects.
	sed -i 's|^Type = .*$|Type = CCU2|' $LBPCONFIG/$PLUGINNAME/rfd.conf
	sed -i 's|^ComPortFile = /dev/.*$|ComPortFile = /dev/mmd_bidcos|' $LBPCONFIG/$PLUGINNAME/rfd.conf
	sed -i 's|^#*AccessFile = /dev/.*$|AccessFile = /dev/null|' $LBPCONFIG/$PLUGINNAME/rfd.conf
	sed -i 's|^#*ResetFile = /dev/.*$|ResetFile = /dev/null|' $LBPCONFIG/$PLUGINNAME/rfd.conf
	if ! grep -q "Improved Coprocessor Initialization" $LBPCONFIG/$PLUGINNAME/rfd.conf ; then
		sed -i 's/\[Interface 0\]/Improved\ Coprocessor\ Initialization\ =\ true\n\n&/' $LBPCONFIG/$PLUGINNAME/rfd.conf
	fi
else
	# otherwise disable the whole [Interface 0] part
	sed -i -e '/^\[Interface 0\]/,/^\s*$/ s/^/#/' $LBPCONFIG/$PLUGINNAME/rfd.conf
fi

# Start RFD
$HM_HOME/bin/rfd -d -l $LEVEL -f $LBPCONFIG/$PLUGINNAME/rfd.conf > /dev/null 2>&1
