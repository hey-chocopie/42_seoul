# libft
## 1. 개요
* 앞으로 42과제를 하며 사용할 c라이브러리를 만들겁니다.
* c에서 제공하는 함수들도 있고 그렇지 않은 함수들도 있습니다.
* 자신이 만든 함수는 확장성이 좋습니다. 앞으로도 사용할 함수들입니다. 잘 만들어 두면 좋습니다.

## 2. 목표
Part 1 - Libc functions
함수들의 프로토타입은 OS X의 BSD libc를 기준으로 작성되었습니다.

## 3.설명
### 1. ft_memset
>메모리 초기화

##### Prototype Declaration
```
void    *ft_memset(void *b, int c, size_t len);
```

##### DESCRIPTION
b문자열에 len 길이만큼 c값으로 입력합니다.

##### RETURN VALUES
b의 첫번째 주소값을 반환합니다.

### 2. ft_bzero
> byte zero

##### Prototype Declaration
```
void    bzero(void *s, size_t n);
```
##### DESCRIPTION
문자열 s에 n만큼 0을 씁니다.

##### RETURN VALUES
없음

### 3. ft_memcpy
>memory copy

##### Prototype Declaration
```
void    *ft_memcpy(void *dst, const void *src, size_t n);
```

##### DESCRIPTION
n바이트 만큼 dst에 src를 복사합니다. src와 dst의 메모리 영역이 겹쳐서는 안됩니다. 메모리 영역이 겹치면, memcpy 대신 memmove를 사용해야합니다.

##### RETURN VALUES
메모리 영역 dst의 포인터를 반환


### 4. memccpy
##### Prototype Declaration
```
void    *memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
```

##### DESCRIPTION
n바이트 만큼 src에서 dst로 복사합니다. c가 나타날 때까지만 복사합니다.(첫번째 c도 복사함). src와 dst의 메모리 영역이 겹쳐서는 안됩니다.

##### RETURN VALUES
src와 c가 같아 끝나게 되면 dst + 복사한 인덱스 + 1의 주소값을 반환합니다.
c와 같은 문자가 없면 0을 반환합니다.

### 5. memmove
>memory move

##### Prototype Declaration
```
void    *ft_memmove(void *dst, const void *src, size_t len);
```

##### DESCRIPTION
메모리 영역 src의 len bytes만큼을 dst로 복사합니다. memcpy와 동일하나, src와 dst의 메모리 영역이 겹칠 때 사용합니다.

##### RETURN VALUES
메모리 영역 dst


### 6. ft_memcmp
##### Prototype Declaration
```
int    ft_memcmp(const void *s1, const void *s2, size_t n);
```

##### DESCRIPTION
s1과 s2를 n바이트 만큼 비교합니다. 


##### RETURN VALUES
n 바이트만큼 같거나 길이가 0이면 0반환
나머지는 두값의 차를 반환합니다.

### 7. strlen
##### Prototype Declaration
```
size_t    ft_strlen(const char *s);
```

##### DESCRIPTION
문자열 s의 길이를 구합니다.

##### RETURN VALUES
문자열 s의 길이를 반환합니다.


### 8. ft_strlcpy
##### Prototype Declaration
```
size_t    ft_strlcpy(char *dst, const char *src, size_t dstsize);
```

##### DESCRIPTION
dst에 src를 복사합니다. dstsize만큼

##### RETURN VALUES
src의 길이

### 9. ft_strlcat
##### Prototype Declaration
```
size_t
     strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
```

##### DESCRIPTION
dst의 마지막 주소부터 dstsize만큼 src를 복사합니다. 문자열 끝에는 0을 넣어야하므로 잘 조절하세요

##### RETURN VALUES


### 10. ft_strchr
##### Prototype Declaration
```
char    *ft_strchr(const char *s, int c);
```

##### DESCRIPTION
s문자열중 처음 c와 같은 문자가 있는곳 주소를 반환합니다.

##### RETURN VALUES
c를 만난 주소를 반환하거나 없으면 0을 반환합니다.


### 11. ft_strrchr
##### Prototype Declaration
```
char *
     strrchr(const char *s, int c);
```

##### DESCRIPTION
s문자열 중에서 마지막으로 c가 발생하는 주소를 반환합니다.

##### RETURN VALUES
c를 만난 주소가 없으면 0을 반환합니다.

### 12. strnstr


##### Prototype Declaration
```
char    *strnstr(const char *haystack, const char *needle, size_t len);
```

##### DESCRIPTION
문자열 haystack에서 needle을 찾아주는데, len길이까지만 찾아 줍니다.

##### RETURN VALUES
haystack 에서 찾은 문자열의 포인터

### 13. ft_strncmp

##### Prototype Declaration
```
int    ft_strncmp(const char *s1, const char *s2, size_t n);
```

##### DESCRIPTION
s1, s2 문자들을 n바이트 까지 사전순서식으로 비교해줍니다.

##### RETURN VALUES
같은 인덱스의 문자가 다르면 s1[i]-s2[i] 깂을 반환하고 모두 같으면 0 을 반환합니다.



### 14. ft_atoi
>ascii to int

##### Prototype Declaration
```
int     atoi(const char *str);
```

##### DESCRIPTION
ft_atoi는 문자열 str을 int로 바꿔줍니다.

##### RETURN VALUES
정수값을 반환해 줍니다.
### 15. ft_atoi


##### Prototype Declaration
```
int     isalpha(int c);
```

##### DESCRIPTION
알파벳 소문자나 대문자면 true, 아니면 false를 반홥합니다.

##### RETURN VALUES
영어 알파벳 1
아니면 0

### 16. isdigit


##### Prototype Declaration
```
int     isdigit(int c);
```

##### DESCRIPTION
c가 숫자 문자인지 아닌지 확인합니다.
EOF(-1)를 처리해주기 위해 int로 받습니다.

##### RETURN VALUES
숫자면 1
숫자 아니면 0

### 17. ft_isalnum


##### Prototype Declaration
```
int    ft_isalnum(int c);
```

##### DESCRIPTION
c가 숫자 또는 알파벳인지 확인합니다.
eof(-1)처리를 위해 int로 받습니다
##### RETURN VALUES
알파벳이나 숫자면 1 알파벳이나 숫자가 아니면 0

### 18. isascii


##### Prototype Declaration
```
int     isascii(int c);
```

##### DESCRIPTION
아스키 코드 문자인지 확인합니다. (0~0177)

##### RETURN VALUES
ASCII 문자면 1 ASCII 문자가 아니면 0

### 19. isprint


##### Prototype Declaration
```
int     isprint(int c);
```

##### DESCRIPTION
프린트 가능한 문자인지 확인합니다.
EOF(-1)를 처리해주기 위해 int로 받습니다.

##### RETURN VALUES
프린트 가능한 문자 1
아니면 0

### 20. ft_toupper


##### Prototype Declaration
```
int    ft_toupper(int c);
```

##### DESCRIPTION
c가 소문자면 대문자로 바꿔줍니다.
EOF(-1)를 처리해주기 위해 int로 받습니다.

##### RETURN VALUES
대문자로 변환된 문자

### 21. ft_tolower
##### Prototype Declaration
```
int    ft_tolower(int c);
```

##### DESCRIPTION
c가 대문자면 소문자로 바꿔줍니다.
EOF(-1)를 처리해주기 위해 int로 받습니다.

##### RETURN VALUES
소문자로 변환된 문자

### 22. ft_calloc
##### Prototype Declaration
```
void    *ft_calloc(size_t count, size_t size);
```

##### DESCRIPTION
0으로 초기화된 연속적인 메모리공간(count x size)을 할당해줍니다.

##### RETURN VALUES
할당 성공시 할당된 공간의 포인터
할당 실패시 NULL 포인터

### 23. strdup
##### Prototype Declaration
```
char    *strdup(const char *s1);
```

##### DESCRIPTION
문자열 s1을 복제해줍니다.

##### RETURN VALUES
복제한 문자열의 포인터
만약 메모리 할당에 실패하면 0을 반환하고 errono넘버 ENOMEM을 설정합니다.


# part 2
**작성중 시간날떄 해야지..**
### ft_substr
### ft_strjoin
### ft_strtrim
### ft_split
### ft_itoa
### ft_strmapi
### ft_putchar_fd
### ft_putstr_fd
### ft_putendl_fd
### ft_putnbr_fd

# bonus
**작성중**
### ft_lstnew
### ft_lstadd_front
### ft_lstsize
### ft_lstlast
### ft_lstadd_back
### ft_lstdelone
### ft_lstclear
### ft_lstiter
### ft_lstmap




### 3. 결과물
libft.a

### 4. 사용법
1. libft.a 만들기
<pre><code>make</pre></code>

2. 메인문 컴파일 할 떄 libft.a를 추가하시면 ft_함수들을 사용할 수 있습니다.

### 5. 설명

### 6. 클라이언트 설명

### 7. 광고