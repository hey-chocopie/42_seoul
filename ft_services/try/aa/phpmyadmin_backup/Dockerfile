FROM alpine:3.12

COPY config.inc.php phpmyadmin_run.sh .

RUN apk update && apk add wget
RUN mkdir -p /www

EXPOSE 5000

ENTRYPOINT sh phpmyadmin_run.sh
