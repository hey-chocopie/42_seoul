FROM alpine:3.12

RUN apk update && apk add libc6-compat supervisor \
	&& rm -rf /var/cache/apk/*

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.17.0_linux_amd64.tar.gz \
	&& tar -xf telegraf-1.17.0_linux_amd64.tar.gz --strip-components=2 -C / \
	&& rm telegraf-1.17.0_linux_amd64.tar.gz

RUN wget https://dl.grafana.com/enterprise/release/grafana-enterprise-7.3.6.linux-amd64.tar.gz \
	&& tar -xf grafana-enterprise-7.3.6.linux-amd64.tar.gz --strip-components=1 -C / \
	&& rm grafana-enterprise-7.3.6.linux-amd64.tar.gz 

COPY grafana.db /data/grafana.db
COPY telegraf.conf /etc/telegraf/telegraf.conf
COPY start.sh /
COPY ./healthy.sh /tmp/healthy.sh
EXPOSE 3000
ENTRYPOINT	sh /start.sh
