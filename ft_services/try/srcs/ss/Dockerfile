#FROM alpine:latest
FROM alpine:3.12

MAINTAINER djeon <djeon@student.42seoul.kr>

RUN apk update && apk add openssl nginx
#	&& apk add curl\
#	&& apk add vim\
#	&& apk add php-fpm\
#	&& apk add php-curl\
#	&& apk add wget
#RUN apk update && apk add nginx
#RUN adduser -D -g 'www' www
#RUN mkdir /www
#RUN chown -R www:www /var/lib/nginx
#RUN chown -R www:www /www

COPY default.conf .
COPY run.sh .
COPY index.html .
#COPY test.sh .
#COPY config.inc.php .
#COPY wp-config.php .

#RUN mkdir -p /run/nginx
#RUN mv server /etc/nginx/nginx.conf.orig
EXPOSE 22 80 443

ENTRYPOINT sh run.sh
