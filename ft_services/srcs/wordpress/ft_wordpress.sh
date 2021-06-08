#!/bin/sh

telegraf & /usr/sbin/php-fpm7 -F & nginx -g 'daemon off;'
