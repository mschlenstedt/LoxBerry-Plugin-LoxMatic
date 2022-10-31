#!/bin/bash

PLUGINNAME=REPLACELBPPLUGINDIR

if [ "$UID" -ne 0 ]; then
	echo "This script has to be run as root."
	exit
fi

# Source HM environment
[[ -r $LBPCONFIG/$PLUGINNAME/hm_env ]] && . $LBPCONFIG/$PLUGINNAME/hm_env

# Kill existing HMServer
if pgrep -f HMIPServer.jar > /dev/null 2>&1 ; then
	pkill -f HMIPServer.jar
	sleep 0.1
	pkill -9 -f HMIPServer.jar
fi

# Create a new entry for the logfile (for logmanager)
. $LBHOMEDIR/libs/bashlib/loxberry_log.sh
PACKAGE=$PLUGINNAME
NAME=hmserver
FILENAME=$LBPLOG/$PLUGINNAME/hmserver.log
APPEND=1
LOGSTART "HMServer started."
LOGOK "HMServer started."
cat $LBPCONFIG/$PLUGINNAME/hm_env >> $LBPLOG/$PLUGINNAME/hmserver.log
# skip this startup if not in normal mode
if [[ "${HM_MODE}" != "NORMAL" ]]; then
	LOGERR "HM environment was not started successfully"
	LOGEND
	exit 1
fi
if [[ ! -n "${HM_HMIP_DEV}" ]]; then
	LOGERR "No HMIP device configured."
	LOGEND
	exit 1
fi
LOGEND

# if no uart is used to connect to the rf module (e.g. HmIP-RFUSB)
# we have to set the device node
if [[ "${HM_HMIP_DEVNODE}" != "${HM_HOST_GPIO_UART}" ]]; then
	HM_SERVER_PORT=${HM_HMIP_DEVNODE}
else
	HM_SERVER_PORT=/dev/mmd_hmip
fi

# make sure the Adapter Port setting is correct
# when generating /var/etc/crRFD.conf
sed -i -e "s|^Adapter\.1\.Port=/dev/.*$|Adapter.1.Port=${HM_SERVER_PORT}|" $LBPCONFIG/$PLUGINNAME/crRFD.conf 

HM_SERVER=/opt/HMServer/HMIPServer.jar
HM_SERVER_ARGS="$LBPCONFIG/$PLUGINNAME/crRFD.conf $LBPCONFIG/$PLUGINNAME/HMServer.conf"

DEBUG=$(jq -r '.Debug' $LBPCONFIG/$PLUGINNAME/loxmatic.json)
if [ "$DEBUG" = "true" ] || [ "$DEBUG" = "1" ]; then
	java -Xmx128m -Dos.arch=arm -Dlog4j.configuration=file://$LBPCONFIG/$PLUGINNAME/log4j.xml -Dfile.encoding=ISO-8859-1 -Dgnu.io.rxtx.SerialPorts=${HM_SERVER_PORT} -jar ${HM_SERVER} ${HM_SERVER_ARGS} >> $LBPLOG/$PLUGINNAME/hmserver.log &
else
	java -Xmx128m -Dos.arch=arm -Dlog4j.configuration=file://$LBPCONFIG/$PLUGINNAME/log4j.xml -Dfile.encoding=ISO-8859-1 -Dgnu.io.rxtx.SerialPorts=${HM_SERVER_PORT} -jar ${HM_SERVER} ${HM_SERVER_ARGS} > /dev/null &
fi
