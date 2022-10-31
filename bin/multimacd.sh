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

# Kill existing multimacd
if pgrep -f bin/multimacd > /dev/null 2>&1 ; then
	pkill -f bin/multimacd
	sleep 0.1
	pkill -9 -f bin/multimacd
fi

# Create a new entry for the logfile (for logmanager)
. $LBHOMEDIR/libs/bashlib/loxberry_log.sh
PACKAGE=$PLUGINNAME
NAME=multimacd
FILENAME=$LBPLOG/$PLUGINNAME/multimacd.log
APPEND=1
LOGSTART "multimac daemon started."
LOGOK "multimac daemon started."
cat $LBPCONFIG/$PLUGINNAME/hm_env >> $LBPLOG/$PLUGINNAME/multimacd.log
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
sed -i "s|^Coprocessor Device Path = .*$|Coprocessor Device Path = ${HM_HOST_GPIO_UART}|" $LBPCONFIG/$PLUGINNAME/multimacd.conf

# Start multimacd
$HM_HOME/bin/multimacd -d -l $LEVEL -f $LBPCONFIG/$PLUGINNAME/multimacd.conf > /dev/null 2>&1
