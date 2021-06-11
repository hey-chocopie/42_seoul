# push_swap
### 개요
* 문제를 해결함에 있어 정렬은 많은 곳에서 사용됩니다.
* 이 과제를 통해 정렬에 대한 이해를 넓힐 수 있습니다.
* **제한된 지침**으로 스택데이터를 정렬하며, 적은수의 작업으로 성공해야 합니다.(제한된 지침은 밑에 정리해두었습니다.)
* 알고리즘 유형을 선택하고 적합한 솔루션으로 해결해야 합니다.

### 목표
* 두 개의 스택으로 퀵 소트 정렬을 구현합니다.
* 퀵 소트를 구현할떄 최소한의 방법으로 구현해보세요!

### 결과물
* push_swap (실행파일)
* checker (실행파일)

### 설명
* 42-push_swap 폴더 : push_swap (실행파일)을 테스트 하기위한 자료들입니다. [42Paris rizky님이 만드신 테스트 케이스 입니다.](https://profile.intra.42.fr/users/rnugroho)
* f_checker 폴더 : checker(실행파일)를 만드는 파일들을 모아두었습니다.
* get_next_line : get_next_line 함수는 파일 디스크립션 데이터를, 개행에 마다 끊어서 읽어와 줍니다.(eof가 발생하면 0을 에러가 발생하면 -1 을 반환해줍니다.)
* libft : 제가 만든 c라이브러리 입니다. 연결리스트를 만들거나, 문자열을 정수로 바꾸기 등등 push_swap을 만들 때 필요한 함수들을 사용했습니다.
* push_swap_tester 폴더 : push_swap에 테스트를 위한 폴더입니다. [42seoul 의 카뎃인 minckim님이 만들어주셨습니다.](https://githubmemory.com/repo/minckim42/push_swap_tester)
* 나머지 .c 파일들은 push_swap (실행파일)을 만들기 위한 파일들입니다.
* 메인문은 push_swap.c파일에 있습니다.

### 제한된 지침
>![image](https://user-images.githubusercontent.com/52343427/121637209-01f27600-cac4-11eb-8235-1f1acc3b0f75.png)

### 사용방법
# push_swap (실행파일)
* push_swap폴더에서 make를 하면 push_swap(실행파일)과 checker 를 만들 수 있습니다.
* <pre><code>./push_swap 정렬되지 않은 정수들</pre></code> 를 넣으면 정수들을 정렬할 수 있는 제약된 지침들이 나옵니다.
* 예제1 : <pre><code>./push_swap 3 1 2</pre></code>
![image](https://user-images.githubusercontent.com/52343427/121637241-0cad0b00-cac4-11eb-930e-813d75e464ee.png)

> 3 1 2 를 오름차순으로 정리하기 하기위해 효율 적인 방법은 ra입니다. 3은 배열 맨 뒤로 가고, 1과 2는 앞으로 옵니다. ./push_swap 3 1 2 을 실행하면 ra가 나오는걸 확인할 수 있습니다.

* 예제2 : <pre><code>./push_swap 4 2 5 1 3</pre></code>
> ra->pb->ra->pb->sb->pa->pa 를 통해 4 2 5 1 3을 오름차순으로 정렬했습니다.
확인해보고 싶다면 제약된 사항들과 비교해보면 따라해보세요!
![image](https://user-images.githubusercontent.com/52343427/121637249-10409200-cac4-11eb-85b4-ad3dfce06043.png)

# checker (실행파일)
* 위에서 보았듯이 정렬이 잘 되었는지 일일이 체크하기는 힘듭니다.
* checker(실행파일)이 정상적으로 정렬이 되었는지 대신해서 확인해 줄겁니다.
* 예제 : <pre><code>./checker 3 1 2</pre></code>
> 체커를 실행하면 표준입력을 대기합니다. ra를 입력하고 ctrl + d(EOF)를 입력하세요. 정상적으로 정렬이 되어 ok가 나옵니다. 정렬이 되어있지 않은 상태에서 ctrl + d (EOF)를 발생 시키면 ko를 출력합니다.
> sa, sa, ss, pa, pb, ra, rb, rr, rra, rrb, rrr을 입력할 수 있습니다. 제한된 지침외에 다른 지침을 입력하면 "Error"을 출력합니다.
![image](https://user-images.githubusercontent.com/52343427/121637263-15054600-cac4-11eb-9905-58bf2ae66e12.png)

* 예제2 : <pre><code>ARG="1 3 2" ; ./push_swap $ARG | ./checker $ARG</pre></code>

>push_swap 실행파일에서 나오는 값들을 바로 체커로 넣었습니다. push_swap에서 나오는 값으로 바로 정렬이 이루어지면 ok를 출력합니다. 
![image](https://user-images.githubusercontent.com/52343427/121638871-a4abf400-cac6-11eb-8a40-cc40a262d89b.png)

# 테스터기 이용한 확인
### push_swap_tester 폴더
```
export ARG=$(./random_numbers 5 -500 100)
../push_swap $ARG | ../checker $ARG
../push_swap $ARG | wc -l
echo $ARG
```
>![image](https://user-images.githubusercontent.com/52343427/121638877-a70e4e00-cac6-11eb-8e28-b4f2c9005e21.png)

* ./random_numbers 에서 첫번쨰 인자는 몇개의 정수를 넣을건지 이고, -500~100개 사이에 수중에 랜덤으로 뽑으라 입니다.

### 42-push_swap 폴더
./test.sh를 이용해 push_swap(실행파일)이 정상 작동하는지 확인할 수 있습니다. 
>![image](https://user-images.githubusercontent.com/52343427/121638905-b2fa1000-cac6-11eb-9075-e0c2c7bb88d6.png)


