#!/bin/sh
pgrep grafana
g=$?
pgrep telegraf
t=$?

if [ $g -ne 0 -o $t -ne 0 ];
then
  exit 1
else
  exit 0
fi
