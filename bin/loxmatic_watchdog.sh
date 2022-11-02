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
	if [ ! -e /sys/class/leds/rpi_rf_mod:green/trigger ]; then
		echo oneshot > /sys/class/leds/rpi_rf_mod:green/trigger
		echo oneshot > /sys/class/leds/rpi_rf_mod:red/trigger
		echo oneshot > /sys/class/leds/rpi_rf_mod:blue/trigger
	fi
}
trap cleanup EXIT

# Create a new entry for the logfile (for logmanager)
. $LBHOMEDIR/libs/bashlib/loxberry_log.sh
PACKAGE=$PLUGINNAME
NAME=watchdog
LOGDIR=$LBPLOG/$PLUGINNAME
LOGSTART "WATCHDOG daemon started."
LOGOK "WATCHDOG daemon started."

RFDENABLED=$(jq -r '.EnableRFD' $LBPCONFIG/$PLUGINNAME/loxmatic.json)
HMIPSERVERENABLED=$(jq -r '.EnableHMIPSERVER' $LBPCONFIG/$PLUGINNAME/loxmatic.json)
HM2MQTTENABLED=$(jq -r '.EnableHM2MQTT' $LBPCONFIG/$PLUGINNAME/loxmatic.json)
LEDSENABLED=$(jq -r '.EnableLEDS' $LBPCONFIG/$PLUGINNAME/loxmatic.json)

COUNTER=0
ERROR=0
SENDERR=0
SENDOK=0
LEDS=1

if [[ "$LEDSENABLED" = "false" ]] || [[ "$LEDSENABLED" = "0" ]] || [[ -z "$LEDSENABLED" ]] || [[ "$LEDSENABLED" = "null" ]];  then
	LOGINF "LEDs are disabled."
	LEDS=0
fi

if [ ! -e /sys/class/leds/rpi_rf_mod:green/trigger ]; then
	LOGINF "Either the led kernel driver isn't loaded or your module is not supported."
fi

while true
do

	#echo $COUNTER

	if [[ "$RFDENABLED" = "true" ]] || [[ "$RFDENABLED" = "1" ]] || [[ "$HMIPSERVERENABLED" = "true" ]] || [[ "$HMIPSERVERENABLED" = "1" ]];  then
		if ! pgrep -f bin/multimacd > /dev/null 2>&1 ; then
			ERROR=1
			SENDOK=0
			if [ "$SENDERR" -eq "0" ]; then
				LOGERR "MULTIMACD is not running."
			fi
		fi
	fi

	if [[ "$RFDENABLED" = "true" ]] || [[ "$RFDENABLED" = "1" ]];  then
		if ! pgrep -f bin/rfd > /dev/null 2>&1 ; then
			ERROR=1
			SENDOK=0
			if [ "$SENDERR" -eq "0" ]; then
				LOGERR "RFD is not running."
			fi
		fi
	fi
	if [[ "$HMIPSERVERENABLED" = "true" ]] || [[ "$HMIPSERVERENABLED" = "1" ]];  then
		if ! pgrep -f HMIPServer.jar > /dev/null 2>&1 ; then
			ERROR=1
			SENDOK=0
			if [ "$SENDERR" -eq "0" ]; then
				LOGERR "HMIPServer is not running."
			fi
		fi
	fi
	if [[ "$HM2MQTTENABLED" = "true" ]] || [[ "$HM2MQTTENABLED" = "1" ]];  then
		if ! pgrep -f hm2mqtt/index.js > /dev/null 2>&1 ; then
			ERROR=1
			SENDOK=0
			if [ "$SENDERR" -eq "0" ]; then
				LOGERR "HM2MQTT is not running."
			fi
		fi
	fi

	if [ "$ERROR" -gt "0" ]
	then
		if [ "$LEDS" -eq "1" ]; then
			echo heartbeat > /sys/class/leds/rpi_rf_mod:red/trigger
		fi
		SENDERR=1
		if [ "$COUNTER" -gt "300" ]; then
			LOGERR "Due to previous errors try to restart services."
			sudo $LBHOME/system/daemons/plugins/$PLUGINNAME short >/dev/null 2>&1 &
			COUNTER=0
		fi
	else
		echo oneshot > /sys/class/leds/rpi_rf_mod:red/trigger
		SENDERR=0
		if [ "$SENDOK" -eq "0" ]; then
			LOGOK "All services are running (again)."
			SENDOK=1
		fi
		if [ "$COUNTER" -gt "29" ]; then
			if [ "$LEDS" -eq "1" ]; then
				echo oneshot > /sys/class/leds/rpi_rf_mod:green/trigger
				echo 1 > /sys/class/leds/rpi_rf_mod:green/shot
			fi
			COUNTER=0
		fi
	fi

	let COUNTER++
	ERROR=0
	sleep 1

done
