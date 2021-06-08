FROM alpine:3.12

RUN	echo "http://dl-2.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories
RUN apk update && apk add curl influxdb libc6-compat telegraf \
	&& rm -rf /var/cache/apk/*

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.17.0_linux_amd64.tar.gz \
	&& tar -xf telegraf-1.17.0_linux_amd64.tar.gz --strip-components=2 -C / \
	&& rm telegraf-1.17.0_linux_amd64.tar.gz
COPY telegraf.conf /etc/telegraf/

COPY start.sh /
COPY ./healthy.sh /tmp/healthy.sh
EXPOSE 8086

ENTRYPOINT  sh start.sh
