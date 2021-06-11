# libft
### 1. 개요
* 앞으로 42과제를 하며 사용할 c라이브러리를 만들겁니다.
* c에서 제공하는 함수들도 있고 그렇지 않은 함수들도 있습니다.
* 자신이 만든 함수는 확장성이 좋습니다. 앞으로도 사용할 함수들입니다. 잘 만들어 두면 좋습니다.

### 2. 목표
Part 1 - Libc functions
함수들의 프로토타입은 OS X의 BSD libc를 기준으로 작성되었습니다.

#### 1. ft_memset
>메모리 초기화

##### Prototype Declaration
```
void    *ft_memset(void *b, int c, size_t len);
```

##### DESCRIPTION
b문자열에 len 길이만큼 c값으로 입력합니다.

##### RETURN VALUES
b의 첫번째 주소값을 반환합니다.

#### 2. ft_bzero
> byte zero

##### Prototype Declaration
```
void    bzero(void *s, size_t n);
```
##### DESCRIPTION
문자열 s에 n만큼 0을 씁니다.

##### RETURN VALUES
없음

#### 3. ft_memcpy
>memory copy

##### Prototype Declaration
```
void    *ft_memcpy(void *dst, const void *src, size_t n);
```

##### DESCRIPTION
n바이트 만큼 dst에 src를 복사합니다. src와 dst의 메모리 영역이 겹쳐서는 안됩니다. 메모리 영역이 겹치면, memcpy 대신 memmove를 사용해야합니다.

##### RETURN VALUES
메모리 영역 dst의 포인터를 반환


#### 3. memccpy
##### Prototype Declaration
```
void    *memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
```

##### DESCRIPTION
n바이트 만큼 src에서 dst로 복사합니다. c가 나타날 때까지만 복사합니다.(첫번째 c도 복사함). src와 dst의 메모리 영역이 겹쳐서는 안됩니다.

##### RETURN VALUES
src와 c가 같아 끝나게 되면 dst + 복사한 인덱스 + 1의 주소값을 반환합니다.
c와 같은 문자가 없면 0을 반환합니다.

#### 2. ft_atoi
>ascii to int

##### Prototype Declaration
```
int     atoi(const char *str);
```

##### DESCRIPTION
ft_atoi는 문자열 str을 int로 바꿔줍니다.

##### RETURN VALUES
정수값을 반환해 줍니다.

#### 3. bzero
##### Prototype Declaration
##### DESCRIPTION
##### RETURN VALUES

### 3. 결과물

### 4. 사용법

### 5. 설명

### 6. 클라이언트 설명

### 7. 광고