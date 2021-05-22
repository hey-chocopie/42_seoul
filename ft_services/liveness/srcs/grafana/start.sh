#!/bin/sh
telegraf & grafana-server & sleep infinity
#supervisord -c /etc/supervisord.conf
