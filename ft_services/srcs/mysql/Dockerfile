FROM alpine:3.12

RUN apk update && apk upgrade \
    && apk add mariadb mariadb-client curl \
    && apk add openrc \
    && rm -rf /var/cache/apk/*

ADD https://dl.influxdata.com/telegraf/releases/telegraf-1.6.3-static_linux_amd64.tar.gz ./
RUN tar -C . -xzf telegraf-1.6.3-static_linux_amd64.tar.gz && \
        chmod +x telegraf/* && \
        cp telegraf/telegraf /usr/bin/ && \
        rm -rf *.tar.gz* telegraf/ 
COPY telegraf.conf /etc/telegraf/

COPY my.cnf /etc/
COPY start_mariadb.sh .
COPY hoylee_db.sql .
COPY create_db .
COPY ./healthy.sh /tmp/healthy.sh
VOLUME ["/var/lib/mysql"]

EXPOSE 3306

ENTRYPOINT sh start_mariadb.sh
