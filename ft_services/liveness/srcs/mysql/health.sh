#!/bin/sh
pgrep mysql
m=$?
pgrep telegraf
t=$?

if [ $m -ne 0 -o $t -ne 0 ];
then
  exit 1
else
  exit 0
fi
