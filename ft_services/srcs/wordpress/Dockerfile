FROM alpine:3.12
RUN apk update && apk upgrade && \
	apk add --no-cache nginx php7 php7-fpm php7-opcache php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session
COPY ft_wordpress.sh default.conf wp-config.php ./

RUN adduser -D -g 'www' www && mkdir -p /www \
	&& chown -R www:www /var/lib/nginx && chown -R www:www /www

RUN	mkdir -p /run/nginx

ADD https://wordpress.org/latest.tar.gz .
RUN tar -xvf latest.tar.gz && \
	mv wordpress /www && \
	mv wp-config.php /www/ && \
	rm -f latest.tar.gz

ADD https://dl.influxdata.com/telegraf/releases/telegraf-1.6.3-static_linux_amd64.tar.gz ./
RUN tar -C . -xzf telegraf-1.6.3-static_linux_amd64.tar.gz && \
        chmod +x telegraf/* && \
        cp telegraf/telegraf /usr/bin/ && \
        rm -rf *.tar.gz* telegraf/ 
        
COPY telegraf.conf /etc/telegraf/
COPY ./healthy.sh /tmp/healthy.sh
RUN mv ./default.conf /etc/nginx/conf.d/default.conf

EXPOSE 5050

ENTRYPOINT sh ft_wordpress.sh

