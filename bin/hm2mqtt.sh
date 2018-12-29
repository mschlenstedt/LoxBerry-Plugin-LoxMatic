#!/bin/bash

if [ "$UID" -ne 0 ]; then
	echo "This script has to be run as root."
	exit
fi

# Kill existing HM2MQTT
if pgrep -x  > /dev/null 2>&1 ; then
	killall 
	sleep 1
fi

# Create a new entry for the logfile (for logmanager)
. $LBHOMEDIR/libs/bashlib/loxberry_log.sh
PACKAGE=loxmatic
NAME=hm2mqtt
FILENAME=REPLACELBPLOGDIR/hm2mqtt.log
APPEND=1
LOGSTART "HM2MQTT daemon started."
LOGOK "HM2MQTT daemon started."
LOGEND

# Loglevel
DEBUG=$(jq -r '.Debug' REPLACELBPCONFIGDIR/loxmatic.json)
if [ "$DEBUG" = "true" ] || [ "$DEBUG" = "1" ]; then
	LEVEL="0"
else
	LEVEL="2"
fi

# Start HM2MQTT
REPLACELBPDATADIR/hm2mqtt/index.js /dev/null 2>&1
