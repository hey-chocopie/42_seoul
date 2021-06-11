# libasm
### 0. 주의
**이 파일은 64비트, intel, 맥 운영체제, 카탈리나 os에서 작성하였습니다. 심볼릭 언어 특성상 다른 컴퓨터 아키텍처에서는 작동하지 않을 수 있습니다.**

### 1. 개요
* 저레벨 언어인 어셈블리어를 다루며, 컴퓨터 동작을 조금 더 깊게 이해할 수 있습니다.
* symbolic machine code 를 접해볼 수 있습니다.

### 2. 목표
* ft_strlen (man 3 strlen)
* ft_strcpy (man 3 strcpy)
* ft_strcmp (man 3 strcmp)
* ft_write (man 2 write)
* ft_read (man 2 read)
* ft_strdup (man 3 strdup, you can call to malloc)
* 위 함수들을 assembly language로 구현해 봅시다!

### 3. 결과물
* libasm.a

### 4. 사용법
* c언어를 컴파일 할 때 libasm.a파일을 추가하면 ft_strlen, ft_strcpy, ft_strcmp, ft_write, ft_read, ft_strdup 함수들을 사용할 수 있습니다.

1. <pre><code>brew install nasm</pre></code>

2. <pre><code>make</pre></code>
를 진행해주세요. 

3. 생성된 libasm.a파일을 c언어 컴파일을 할때 같이 빌드하면 ft_strlen, ft_strcpy, ft_write,ft_read, ft_strdup 을 사용할 수 있습니다.

```
size_t      ft_strlen(const char *s);
char        *ft_stpcpy(char * dst, const char * src);
int         strcmp(const char *s1, const char *s2);
ssize_t     write(int fildes, const void *buf, size_t nbyte);
ssize_t     read(int fildes, void *buf, size_t nbyte);
char *      strdup(const char *s1);
```

### 5. 설명
**man 과 같습니다. 위에 man번호도 명시해 두었습니다.**
* ft_strlen
: 입력되는 매개변수에서 null이 올떄까지 카운트하고 반환합니다.
* ft_strcpy
: strcpy는 dst메게변수에 src를 복사합니다. 
* ft_strcmp
: 매게변수로 들어온 두개의 문자열을 비교하여 문자열이 같다면 0, 다르면 음수 혹은 양수를 반환하는 함수이다.
* ft_write
: write ()는 buf주소의 값들을 nbyte만큼 쓰기를 시도합니다. 쓰는 위치는 filedes에서 참조하는 객체에 의해 가리키는 버퍼입니다, 
: 리턴값은 성공하면 write한 글자수를 리턴하고, 실패하면 -1 을 리턴합니다.
* ft_read
: n바이트만큼 fildes에서 읽어옵니다.
: 읽어온 데이터는 buf에 저장됩니다.
: 성공하면, 읽어온 글자수를 리턴값으로 반환하고 실패하면 -1을 리턴합니다.
: write와 마찬가지로, errno변수에, 에러넘버를 반환합니다.
* ft_strdup
: 입력으로 넣어주는, 문자열과 똑같은 문자열을 할당해서, 첫 주소값을 반환해준다.
: 리턴값은 매개변수 첫번쨰

### 6. 광고
[어셈블리어에 대해 정리해 두었습니다. 감사합니다](https://velog.io/@hey-chocopie/Libasm-2.-%EC%96%B4%EC%85%88%EB%B8%94%EB%A6%AC%EC%96%B4%EB%9E%80-%EA%B0%9C%EB%85%90-%EB%B0%8F-%ED%8A%B9%EC%A7%95-%EC%A0%95%EB%A6%AC-%EB%AA%85%EB%A0%B9%EC%96%B4-%EC%A0%95%EB%A6%AC)