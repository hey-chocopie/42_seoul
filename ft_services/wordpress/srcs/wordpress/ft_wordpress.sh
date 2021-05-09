#!/bin/bash

rc-service lighttpd start && rc-update add lighttpd default
#apk add wget php5-mysql mysql mysql-client php5-zlib
/etc/init.d/lighttpd restart
/bin/sh
