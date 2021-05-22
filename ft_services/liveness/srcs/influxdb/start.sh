#!/bin/sh
telegraf & influxd run -config /etc/influxdb.conf
#supervisord -c /etc/supervisord.conf
