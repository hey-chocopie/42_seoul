FROM	alpine:3.12

LABEL	maintainer="hoylee@student.42seoul.kr"
RUN		echo "http://dl-2.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories
RUN     apk update && apk add --no-cache nginx openssl telegraf 

COPY ft_server.sh default.conf telegraf.conf ./
COPY telegraf.conf /etc/telegraf/
COPY ./healthy.sh /tmp/healthy.sh
EXPOSE 80 443

ENTRYPOINT sh ft_server.sh
