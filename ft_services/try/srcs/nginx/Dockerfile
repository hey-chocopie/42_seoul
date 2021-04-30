FROM alpine:3.12.0
# FROM alpine:latest
#apk 업데이트하고 패키지설치 nginx, openssl, openssh-server -no-cache 옵션으로 캐쉬파일 제거
#apd add nginx해도됨
RUN     apk update && apk add --no-cache nginx openssl
RUN     mkdir -p /var/run/nginx
RUN	openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gam/CN=localhost" -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt
# 인증서 옮기고 권한설정
RUN	chmod 600 /etc/ssl/certs/nginx-selfsigned.crt /etc/ssl/private/nginx-selfsigned.key
RUN echo "Hello world" >> /var/www/index.html
COPY ./default.conf /etc/nginx/conf.d/
EXPOSE 80 443
CMD nginx -g "daemon off;"
