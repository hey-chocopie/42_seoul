FROM	debian:buster

LABEL	maintainer="hoylee@student.42seoul.kr"

RUN	apt-get update && apt-get install -y \
	nginx \
	openssl \
	vim \
	php-fpm \
	mariadb-server \
	php-mysql \
	php-mbstring \
	wget 

COPY	./srcs/ft_server.sh ./
COPY	./srcs/default ./tmp
COPY	./srcs/wp-config.php ./tmp
COPY	./srcs/config.inc.php ./tmp

EXPOSE 80 443

CMD bash ft_server.sh
