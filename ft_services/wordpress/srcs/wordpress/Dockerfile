FROM alpine:3.12

COPY ft_wordpress.sh default.conf ./
#wp-config.php 
ADD https://wordpress.org/latest.tar.gz .

RUN mkdir -p /www
RUN	mkdir -p /run/nginx

RUN tar -xvf latest.tar.gz && \
	mv wordpress /www
	# && \
#	mv wp-config.php /www/ && \
#	rm -f latest.tar.gz

RUN apk update && \
	apk add --no-cache nginx php7 php7-fpm php7-opcache php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session

RUN mv ./default.conf /etc/nginx/conf.d/default.conf
RUN echo "HELLOW" >> www/wordpress/index.html

EXPOSE 5050

ENTRYPOINT sh ft_wordpress.sh
