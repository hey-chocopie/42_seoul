# ft_services
### 1. 개요
* ft_services는 쿠버네티스(Kubernetes, k8s)를 활용하여 하나의 서비스를 배포해볼 수 있는 과제입니다.
쿠버네티스란?
: 다양한 컨테이너 운영환경 중 가장 널리 사용되는 솔루션입니다.
컨테이너 운영환경이란?
: 개발자로 하여금 컨테이너 운영을 간편하게 할 수 있도록 등장한 기술입니다.
* 시스템 관리 및 네트워킹 을 배울 수 있습니다.

### 2. 목표
![image](https://user-images.githubusercontent.com/52343427/121640871-724fc600-cac9-11eb-88f0-859c6b750e77.png)

> 쿠버네티스 클러스터내에서 위와같은 형식으로 서비스가 동작하게 구현하세요.

>동그라미는 유저가 접근할 수 있는 것들이고, 네모는 유저는 불가, 관리자만 접근 가능합니다.

### 3. 결과물
![image](https://user-images.githubusercontent.com/52343427/121645708-7848a580-cacf-11eb-82dc-fdd868030122.png)

![image](https://user-images.githubusercontent.com/52343427/121645721-7d0d5980-cacf-11eb-9de8-10f4b82bd91a.png)
### 4. 사용법
> 개발 환경 구축
```
brew install minikube
brew install docker
brew install virtualbox
```

1. 실행
<pre><code>./setup.sh</pre></code>
> 쉘 파일을 실행하면, 서비스를 띄울수 있습니다.

2. 확인
<pre><code>kubetlc get all</pre></code>
> 쿠버네티스에서 실행중인 오브젝트 정보들을 모두 볼수 있습니다. pod정보와 services를 볼수 있습니다. externIP 뒤에 파드의 port를 붙여 웹브라우저에 실행하면 요청에 대한 데이터를 반환해 줍니다.

3. 데쉬보드
<pre><code>minikube dashboard</pre></code>
>데쉬보드를 통해 실행 중인 클라이언트에 접속 할 수 있습니다.

### 5. 설명
* setup.sh : 
```
main()
{
	introduce
	minikube_setup
	make_images
	yaml_services
}
```
1. introduce : 만든이 정보가 담겨있습니다.
2. minikube_setup : 쿠버네티스 실행을 하고 세팅합니다.
3. make_images : nginx, wordpress, phpmyadmin, mysql, ftps, grafana, influxDB 이미지 파일을 만듭니다.
4. yaml_services : 쿠버네티스에 적용할 오브젝트를 생성합니다.

### 6. 클라이언트 설명
* 로드벨런서란? : 서버에 가해지는 부하를 분산해주는 장치 또는 기술을 통칭합니다

* nginx란? : 웹 서버에 10,000개의 클라이언트의 접속을 동시에 다룰수 있는 기술적인 문제(apachedml c10k problem)를 해결하기 위해 만든 Event-driven구조의 http, Reverser Proxy, IMAP/POP PROXY server를 제공하는 오픈 소스 프로그램.

* wordpress란? : 워드프레스란 PHP로 작성된 온라인 오픈 소스 웹사이트 저작 도구입니다.

* ftps란? : file transfer protocol security

*  mysql란? : 오픈 소스 데이터베이스이며, MySQL AB사가 개발하여 배포/판매하고 있는 데이터베이스(DataBase)이다.

* influxDB란? :  시계열 형태, 실시간으로 클라이언트의 정보를 가지고 와서 저장하는 역활, 이 또한 db의 한 종류이다.

* Grafana란? : Grafana를 사용하면 저장된 위치에 상관없이 메트릭 을 쿼리, 시각화, 경고 및 이해할 수 있습니다

### 7. 광고
[더 자세한 내용이 궁금하시면 참고해주세요](https://velog.io/@hey-chocopie/ftservices-2.-%EC%BF%A0%EB%B2%84%EB%84%A4%ED%8B%B0%EC%8A%A4-%EC%95%8C%EC%95%84%EB%B3%B4%EA%B8%B0)
