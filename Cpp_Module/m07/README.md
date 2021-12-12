# C++ - Module 07
>c++ Templates


# Exercise 00: A few functions
### 한줄평 : 함수 템플릿의 기본형에 대해 공부했다. typename 을 통해 모든 종류의 자료형을 손쉽게 받을수 있다. 


```
Turn-in directory : ex00/
Files to turn in : whatever.hpp, main.cpp and a Makefile
Allowed functions : None
```

Write the following function templates:
• swap: Swaps the values of two arguments. Does not return anything.
• min: Compares the two arguments and returns the smallest one. If the two arguments are equal, then it returns the second one.
• max: Compares the two arguments and returns the biggest one. If the two arguments are equal, then it returns the second one.
다음을 따라서 함수 템플릿을 작성하세요!
swap: 두개의 매게변수를 바꾸는 함수, 리턴은 없다.
min : 두개의 매게변수를 비교하고 작은걸 리턴함. 만약 두개의 함수가 같으면, 그땐 두번째거 리턴!
max : 두개의 매게변수 비교하고, 더 큰거 리턴. 만약 같으면 그때 두번째거 리턴

Templates must be defined in header files. You must turn in a main.cpp containing tests
for your program. This file can and will be changed during evaluation. These functions
can be called with any type of argument, with the condition that the two arguments have
the same type and supports all comparison operators. Provide enough code to compile an executable that proves that everything works as intended.

템플릿은 헤더파일에 있어야합니다. 너는 너의 프로그램을 테스트하는 내용을 main.cpp에 포함합니다. 이 파일은 평가하는동안 평가하는 동안 바뀔수 있다.  이 함수는 어떠한 타입의 메게변수로도 불릴수 있다.  두개의 매게변수는 동일한 타입이고  모든 비교 연산자를 지원합니다. 
컴파일이 실행되고 모든 일들이 잘 돌아가도록 충분한 코드를 제공하세요!

# Exercise 01: Iter
### 한줄평 : 함수형 템플릿를 사용할때 매게인자가 변수뿐 아니라 함수일때 사용법도 익혔고, 다양한 자료형의 매게인자가 들어왔을때 처리하는 방법도 배웠다. 
 
```
Turn-in directory : ex01/
Files to turn in : iter.hpp, main.cpp and a Makefile
Allowed functions : None
```

Write a function template iter that take 3 parameters and returns nothing.

3개의 매게변수를 가지고 아무것도 아무것도 리턴하지 않는 함수템플릿을 작성하세요.

The first parameter is the address of an array, the second one is the length of the array and the third one is a function called for each element of the array.
첫번째 파라메터는 array의 주소입니다. 두 번째는 배열의 길이입니다. 그리고 세번째는 서로다른 원소 대해 부르는 함수 입니다.

Wrap your work in an executable that proves that your function template iter works with any type of array and/or with an instantiated function template as a third parameter.
함수 템플릿 iter가 모든 유형의 배열 및/또는 인스턴스화된 함수 템플릿을 세 번째 매개변수로 사용할 수 있음을 증명하는 실행 파일로 작업을 래핑합니다.





# Exercise 02: Array
# 한줄평 : 클래스 템플릿을 써보는 과제였다. 이 과제는 단순히 하나의 템플릿 타입만 받아서 동작하는 과제엿는데, 간단하지 않았다 일반적으로 클래스를 cpp와 hpp형태로 나누어 컴파일 했는데, 템플릿 클래스는 함수를 파일을 분리하면 컴파일 과정에서 클래스를 정의하지 못해 컴파일 에러가 난다. 그리고 템플릿 클래스 밖에서 맴버함수를 정의할때 범위지정자를 지정할때도 어떤형태의 클래스인지 까지 같이 정의해두어야한다. 클래스 템플릿 사용하기는 어렵지만 재대로 배운뒤에는 유용할거 같다.

Write a class template Array that contains elements of type T and that allows the
following behavior:

• Construction with no parameter: creates an empty array.

• Construction with an unsigned int n as a parameter: creates an array of n elements, initialized by default. (Tip: try to compile int * a = new int();, then
display *a.)

• Construction by copy and assignment operator. In both cases, modifying one of
the two arrays after copy/assignment won’t affect anything in the other array.

• You MUST use the operator new[] for your allocation. You must not do preventive
allocation. Your code must never access non allocated memory.

• Elements are accessible through the operator[].

• When accessing an element with the operator[], if this element is out of the limits,
a std::exception is thrown.

• A member function size that returns the number of elements in the array. This member function takes no parameter and does not modify the current instance in any way

type T원소를 포함하고 허용하는 클래스 템플릿 Array를 작성하십시오 : 



매게변수가 없는 구성 : 빈 배열을 만듭니다.

"unsigned int n" 매게변수를 가지는 구성 : n으로 초기화되는 배열을 만듭니다. ( 팁 : int * a = new int(); 를 컴파일 하려고 시도한 다음 표시 *a)

 목사 및 할당 operator 구성. 두 케이스, 두 경우 모두 복사 / 할당 후 두 개의 배열중 하나를 수정해도 다른 배열은 아무것도 영향을 받지 않습니다.
 
 operator new[]를 만들어야합니다. 할당을 해서는 안됩니다. 할당되지 않은 메모리에 액세스 해서는 안됩니다. 
 
 요소는 operator[]를 통해 액세스 할수 잇습니다. 
 
 • operator[]를 사용하여 요소에 액세스할 때 이 요소가 제한을 벗어나면 std::exception이 발생합니다.
 
 멤버함수 size는 array 요소의 개수를 반환합니다. 
 
 이 멤버 함수는 매개변수를 사용하지 않으며 어떤 식으로든 현재 인스턴스를 수정하지 않습니다.


 The following code:

 ```
 int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}
 ```

Should output the following if you did well:
 ```
 a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
 ```



