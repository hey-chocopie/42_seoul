# ft_printf
### 1. 개요
* c라이브러리에 있는 printf를 구현해봅시다.
* **가변인자**를 어떻게 사용하는지 배우게 될 것입니다.
* 스텐다드 라이브러리의 이해를 넓힐 수 있습니다.

### 2. 목표
* printf와 똑같은 함수를 구현하는게 목표입니다.
* c에 대한 이해와, 로직의 중요성을 몸소 체험 합니다.

### 3. 결과물
* libprintf.a

### 4. 사용법
* libprintf.a를 c언어 컴파일 할 때 같이 빌드하면, ft_printf를 사용할 수 있습니다.

1. make
2. 메인문이 있는 파일을 작성하고, ft_printf.a를 포함해서 빌드하세요
<pre><code>int ft_printf(const char *, …);</pre></code>

<pre><code>ft_printf("%c %s %p %d %i %u %x %X %", 'a', "hoylee" ,&i, 35, 35, -35, 123, 123); </pre></code>
>printf 처럼 ft_printf를 사용하시면 됩니다.

### 5. 설명
* 다음 conversions(변환)들이 매니지합니다. : c, s, p, d, i, u, x, X, %
* printf에서 사용할수 있는 플래그들을 모두 적용시킵니다. : [-] [0] [ . ] [ * ] , [모든 컨버전스와 사용하는 최소 필드 너비]도..

Program name : libftprintf.a
Makeﬁle : all, clean, fclean, re, bonus
External functs : malloc, free, write, va_start, va_arg, va_copy, va_end

### 6. 광고
* 블로그 정리는 하지 않았습니다~