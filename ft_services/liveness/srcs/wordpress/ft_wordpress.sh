#!/bin/sh

#/usr/bin/supervisord -c /etc/supervisord.conf

#usr/sbin/php-fpm7
/usr/sbin/php-fpm7 -F & nginx -g 'daemon off;' & sleep infinity
#nginx -g "daemon off;"
#/bin/sh
