FROM	alpine:3.12

LABEL	maintainer="hoylee@student.42seoul.kr"

RUN     apk update && apk add --no-cache nginx openssl

COPY index.html ft_server.sh default.conf ./

EXPOSE 80 443

ENTRYPOINT sh ft_server.sh
