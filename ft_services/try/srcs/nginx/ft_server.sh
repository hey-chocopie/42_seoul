#!/bin/bash

mkdir -p /run/nginx

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=AITEAM/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key


#mv nginx.conf /etc/nginx
cp -rp ./default.conf /etc/nginx/conf.d
mv index.html /var/www/localhost/htdocs

nginx -g "daemon off;"
#bash
#/bin/sh
