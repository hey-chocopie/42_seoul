#!/bin/sh

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=AITEAM/CN=localhost" -keyout /etc/vsftpd/ftps.key -out /etc/vsftpd/ftps.crt
chmod 600 etc/vsftpd/ftps.crt etc/vsftpd/ftps.key
supervisord -c /etc/supervisord.conf
