# ft_server
### 1. 개요
* "docker"기술을 사용하여 완전한 웹 서버를 설치합니다.
* docker에 대해 배울수 있습니다. 

### 2. 목표
* 도커를 이용합니다.(docker hub는 사용할수 없습이가.)
* Wordpress, phpMyAdmin 및 SQL 데이터베이스를 하나의 컨테이너에 설치합니다.
* 웹 서버는 동시에 여러 서비스를 실행할 수 있어야합니다. (WordPress 웹 사이트, phpMyAdmin 및 MySQL 동시에 작동)
* SQL 데이터베이스가 WordPress 및 phpMyAdmin과 함께 작동하는지 확인해야합니다.

### 3. 결과물
사진

### 4. 사용법
1. ft_server 이미지파일 만들기
<pre><code>docker build -t ft_server 42_subject/ft_server</pre></code>

2. 컨테이너 만들기
<pre><code>docker run -it -p 80:80 -p 443:443 ft_server</pre></code>

3. 접속
[http://locathost:80](http://locathost:80)
[http://locathost:433](http://locathost:433)

### 5. 설명
* 도커로 LEMP 스택을 구현했습니다.
* Linux / (E)Nginx / MySQL / PHP

### 6. 광고
[ft_server 추가적 설명](https://velog.io/@hey-chocopie/%EB%8F%84%EC%BB%A4-%EC%82%AC%EC%9A%A9%EB%B2%95-%EB%8D%B0%EB%B9%84%EC%95%88-os%EC%84%A4%EC%B9%98-nginx-%EC%84%A4%EC%B9%98-php-fmp-wordpress-myphpadin-myriaDB-%EC%98%AC%EB%A0%A4%EB%B3%B4%EA%B8%B0ftserver-%EA%B3%BC%EC%A0%9C%ED%92%80%EC%9D%B4)