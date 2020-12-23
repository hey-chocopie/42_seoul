======== ft_printf =========

# 1. 프로젝트 진행 날짜
    : 2020-08-01 ~ 2020-08-20(토)
# 2. 프로젝트 목표
    >printf의 작동원리가 궁금하여서 printf와 똑같이 작성하는 ft_printf 함수 작성

# 3. 코드작성시 유의사항
> • The prototype of ft_printf should be int ft_printf(const char *, ...);

> • You have to recode the libc’s printf function

> • It must not do the buffer management like the real printf

>• It will manage the following conversions: cspdiuxX%

>• It will manage any combination of the following flags: ’-0.*’ and minimum field
width with all conversions

>• It will be compared with the real printf

>• You must use the command ar to create your librairy, using the command libtool
is forbidden.

# 4. 컴파일 설명.
* 간단한 테스트.
>1. <pre><code>gcc *.c</pre></code>
>2. ./a.out
>3. main.c 파일에 간단한 테스트들을 올려놓았습니다. 
   
 * 세부 테스트.
>1. printf 내부 폴더에서 make
>2. ~/printf/42TESTERS-PRINTF/ 폴더에서 ./runtest.sh 하면 테스트를 확인할수 있으며 srcs폴더에서 테스트 케이스를 확인할수 있습니다. 
>3. ~/printf/printf_lover_v2/ 폴더에서 
>4. ./printf_lover.sh 테스트 케이스를 확인할 수 있습니다.

=======ft_libft=================
# 프로젝트날짜
    :2020-07-01 ~ 2020-07-20 
# 2. 프로젝트 목표
    > c언어 라이브러리에 포함된 함수 동작을 이해하기위해 제작.
# 3. 코드작성시 유의사항. 
1. for 문 없이 짜보기.
2. man (함수이름) 에나오는 함수와 똑같이 만들것.

# 4. 컴파일
 * 프로젝트가 끝난뒤라 main과 테스트.c파일들을 지웠습니다. 
 * 만약 테스트를 해보고 싶다면, main을 만든뒤 기존의 라이브러리함수들과 대조되게 작성하여 확인해보시면 됩니다!