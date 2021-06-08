#!/bin/sh
pgrep vsftpd
v=$?
pgrep telegraf
t=$?

if [ $v -ne 0 -o $t -ne 0 ];
then
  exit 1
else
  exit 0
fi
