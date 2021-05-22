#!/bin/sh
pgrep influxd
i=$?
pgrep telegraf
t=$?

if [ $i -ne 0 -o $t -ne 0 ];
then
  exit 1
else
  exit 0
fi
