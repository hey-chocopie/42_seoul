FROM alpine:3.12

COPY wp-config.php . 
COPY wordpress_run.sh .

ADD https://wordpress.org/latest.tar.gz .

RUN mkdir -p /www

RUN tar -xvf latest.tar.gz && \
	mv wordpress /www && \
	mv wp-config.php /www/ && \
	rm -f latest.tar.gz

RUN apk update && \
	apk add --no-cache php7 php7-fpm php7-opcache php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session

EXPOSE 5050

ENTRYPOINT sh wordpress_run.sh
