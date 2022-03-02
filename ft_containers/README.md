# 1. 프로젝트 소개.🚛
소개 : 활용하기 쉬운 Container(vector, map, stack)를 구현합니다.
기간 : 2022.01.01 ~ 2022.02.15
요약 : C++ standard(표준,std) 의 Container(vector, map, stack)를 구현합니다. 
		기존 std::vector를 ft::vector형태로 됩니다. 
		제공된는 ft::vector는 include파일의 vector.hpp를 추가하면 사용할 수 있습니다.
		또한 제공되는 Makefile을 통해, ft::vector 가 정상적으로 작동하는지 확인할 수 있습니다.

# 2. 구현 목록
<img width="644" alt="스크린샷 02-27 오전 4 07 07" src="https://user-images.githubusercontent.com/52343427/156289932-a3d9ceb2-c00a-4451-8b1d-a717a9710554.png">

		
# 3. 프로젝트 구조
### 기본구조
```
.
├── Makefile
├── READMD.md
├── include
│   ├── binary_search_tree.hpp
│   ├── map.hpp
│   ├── map_iter.hpp
│   ├── pair.hpp
│   ├── stack.hpp
│   ├── utility.hpp
│   ├── vector.hpp
│   └── vector_iter.hpp
└── test_srcs
    ├── define.hpp
    ├── map_test.cpp
    ├── stack_test.cpp
    └── vector_test.cpp
```
2 directories, 14 files
* include 안의 vector.hpp파일을 헤더로 추가하면 ft::vector을 사용할수 있습니다. 
* map, stack, pair 또한 동일하게 사용 가능합니다.
* test_srcs는 make시 ft::vector, ft::map, ft::stack 가 std의 컨테이너와 동일하게 동작하는지 비교합니다. 

### make 후 구조
```
.
├── Makefile
├── README.md
├── diff
│   ├── diff_map
│   ├── diff_stack
│   └── diff_vector
├── include
│   ├── binary_search_tree.hpp
│   ├── map.hpp
│   ├── map_iter.hpp
│   ├── pair.hpp
│   ├── stack.hpp
│   ├── utility.hpp
│   ├── vector.hpp
│   └── vector_iter.hpp
├── objs
│   ├── ft_map.o
│   ├── ft_stack.o
│   ├── ft_vector.o
│   ├── std_map.o
│   ├── std_stack.o
│   └── std_vector.o
├── out
│   ├── ft_map.out
│   ├── ft_stack.out
│   ├── ft_vector.out
│   ├── std_map.out
│   ├── std_stack.out
│   └── std_vector.out
└── test_srcs
    ├── define.hpp
    ├── map_test.cpp
    ├── stack_test.cpp
    └── vector_test.cpp
```
5 directories, 29 files
* make 후 objs, out, diff 폴더가 추가됩니다.
* out 폴더의 ./out/ft_vector.out를 실행시켜 보면 test_src의 출력값을 확인할 수 있습니다.
* diff 파일에는 std와 ft의 vector, map, stack을 비교하며, 실행되는 값이 다른게 있다면 저장해서 보여줍니다.

# 4. 프로젝트 실행

```
git clone https://github.com/hey-chocopie/42_seoul.git
```
1. 깃 클론 진행

```
cd ft_containers
```

2. ft_containers 로 이동

```
make
./out/ft_vector.out

//or

cat diff/diff_vector
```
make 후 vector test 케이스 출력
또는
std::vector의 출력값과 ft::vector출력 비교값 출력.

![화면-기록-2022-03-02-오후-12 43 51](https://user-images.githubusercontent.com/52343427/156292124-ab367ca2-cb01-4367-b362-e87969c24596.gif)

```
이제 당신은 container를 활용할 수 있습니다.
```
