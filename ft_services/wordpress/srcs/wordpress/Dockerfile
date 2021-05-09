FROM	alpine:3.12

LABEL	maintainer="hoylee@student.42seoul.kr"
COPY	ft_wordpress.sh ./
RUN     apk update && \
		apk add --no-cache lighttpd openrc wget php7-common php7-session php7-iconv php7-json php7-gd php7-curl \
		php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc \
		php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom

RUN		sed -i 's/\#   include \"mod\_fastcgi\.conf\"/include \"mod\_fastcgi\.conf\"/' /etc/lighttpd/lighttpd.conf
ENTRYPOINT sh ft_wordpress.sh
#RUN		rc-service lighttpd start && rc-update add lighttpd default
#RUN		rc-service lighttpd start
#RUN		rc-update add lighttpd default
#RUN		apk add wget php5-mysql mysql mysql-client php5-zlib
#RUN		/etc/init.d/lighttpd restart
