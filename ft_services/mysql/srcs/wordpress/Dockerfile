FROM alpine:3.12
RUN apk update && apk upgrade && \
	apk add --no-cache nginx supervisor php7 php7-fpm php7-opcache php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session
COPY ft_wordpress.sh default.conf ./
#wp-config.php 
COPY supervisor.conf /etc/supervisord.conf
RUN	mkdir -p /run/nginx


RUN adduser -D -g 'www' www && mkdir -p /www \
	&& chown -R www:www /var/lib/nginx && chown -R www:www /www
ADD https://wordpress.org/latest.tar.gz .
RUN tar -xvf latest.tar.gz && \
	mv wordpress /www
	# && \
#	mv wp-config.php /www/ && \
#	rm -f latest.tar.gz






RUN mv ./default.conf /etc/nginx/conf.d/default.conf

EXPOSE 5050

ENTRYPOINT sh ft_wordpress.sh
