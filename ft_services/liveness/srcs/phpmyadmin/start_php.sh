#!/bin/sh

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=AITEAM/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key
telegraf & nginx -g 'daemon off;' & /usr/sbin/php-fpm7 --nodaemonize & sleep infinity
#/usr/bin/supervisord -c /etc/supervisord.conf
