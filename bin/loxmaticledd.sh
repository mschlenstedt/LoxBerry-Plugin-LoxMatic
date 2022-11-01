#!/bin/bash

PLUGINNAME=REPLACELBPPLUGINDIR

if [ "$UID" -ne 0 ]; then
	echo "This script has to be run as root."
	exit
fi

# Function when exiting
function cleanup {
	LOGEND
	# Turn off all leds
	echo oneshot > /sys/class/leds/rpi_rf_mod:green/trigger
	echo oneshot > /sys/class/leds/rpi_rf_mod:red/trigger
	echo oneshot > /sys/class/leds/rpi_rf_mod:blue/trigger
}
trap cleanup EXIT

# Create a new entry for the logfile (for logmanager)
. $LBHOMEDIR/libs/bashlib/loxberry_log.sh
PACKAGE=$PLUGINNAME
NAME=loxmaticledd
LOGDIR=$LBPLOG/$PLUGINNAME
LOGSTART "LOXMATICLEDD daemon started."
LOGOK "LOXMATICLEDD daemon started."

RFDENABLED=$(jq -r '.EnableRFD' $LBPCONFIG/$PLUGINNAME/loxmatic.json)
HMIPSERVERENABLED=$(jq -r '.EnableHMIPSERVER' $LBPCONFIG/$PLUGINNAME/loxmatic.json)
HM2MQTTENABLED=$(jq -r '.EnableHM2MQTT' $LBPCONFIG/$PLUGINNAME/loxmatic.json)
LEDSENABLED=$(jq -r '.EnableLEDS' $LBPCONFIG/$PLUGINNAME/loxmatic.json)

COUNTER=0
ERROR=0

if [[ "$LEDSENABLED" = "false" ]] || [[ "$LEDSENABLED" = "0" ]] || [[ -z "$LEDSENABLED" ]] || [[ "$LEDSENABLED" = "null" ]];  then
	LOGINF "LOXMATICLEDD is disabled."
	exit
fi

if [ ! -e /sys/class/leds/rpi_rf_mod:green/trigger ]; then
	LOGERR "Either the led kernel driver isn't loaded or your module is not supported."
	exit
fi

while true
do

	if [[ "$RFDENABLED" = "true" ]] || [[ "$RFDENABLED" = "1" ]] || [[ "$HMIPSERVERENABLED" = "true" ]] || [[ "$HMIPSERVERENABLED" = "1" ]];  then
		if ! pgrep -f bin/multimacd > /dev/null 2>&1 ; then
			ERROR=1
		fi
	fi

	if [[ "$RFDENABLED" = "true" ]] || [[ "$RFDENABLED" = "1" ]];  then
		if ! pgrep -f bin/rfd > /dev/null 2>&1 ; then
			LOGERR "RFD is not running."
			ERROR=1
		fi
	fi
	if [[ "$HMIPSERVERENABLED" = "true" ]] || [[ "$HMIPSERVERENABLED" = "1" ]];  then
		if ! pgrep -f HMIPServer.jar > /dev/null 2>&1 ; then
			ERROR=1
		fi
	fi
	if [[ "$HM2MQTTENABLED" = "true" ]] || [[ "$HM2MQTTENABLED" = "1" ]];  then
		if ! pgrep -f hm2mqtt/index.js > /dev/null 2>&1 ; then
			ERROR=1
		fi
	fi

	if [ "$ERROR" -gt "0" ]
	then
		echo heartbeat > /sys/class/leds/rpi_rf_mod:red/trigger
	else
		echo oneshot > /sys/class/leds/rpi_rf_mod:red/trigger
		if [ "$COUNTER" -gt "29" ]; then
			echo oneshot > /sys/class/leds/rpi_rf_mod:green/trigger
			echo 1 > /sys/class/leds/rpi_rf_mod:green/shot
			COUNTER=0
		fi
	fi

	let COUNTER++
	ERROR=0
	sleep 1

done
