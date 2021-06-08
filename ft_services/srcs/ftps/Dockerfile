FROM alpine:3.12

RUN	echo "http://dl-2.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories
RUN apk update && apk add vsftpd openssl telegraf \
	&&	mkdir -p /var/ftp \
	&& rm -rf /var/cache/apk/*

COPY ./telegraf.conf /etc/telegraf/

RUN adduser -D -g 'hoylee' hoylee
RUN echo "hoylee:password" | chpasswd

COPY ./start.sh /
COPY ./vsftpd.conf /etc/vsftpd/
COPY ./healthy.sh /tmp/healthy.sh
EXPOSE 21 21000

CMD sh start.sh
