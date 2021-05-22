#!/bin/sh
pgrep nginx
n=$?
pgrep php-fpm
p=$?
pgrep telegraf
t=$?

if [ $n -ne 0 -o $p -ne 0 -o $t -ne 0 ];
then
  exit 1
else
  exit 0
fi
