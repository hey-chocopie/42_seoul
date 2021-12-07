# 개념정리
* CPP Module 00 : https://velog.io/@hey-chocopie/cpp-%EA%B0%9C%EB%85%90%EA%B3%B5%EB%B6%80
* CPP Module 01 : https://velog.io/@hey-chocopie/cpp-module-01
* CPP Module 02 : https://velog.io/@hey-chocopie/cpp-module-02
* CPP Module 03 : https://velog.io/@hey-chocopie/cpp-module-03
* CPP Module 04 : https://velog.io/@hey-chocopie/C-Module-04
* CPP Module 05 : https://velog.io/@hey-chocopie/cpp-module-05
* CPP Module 06 : https://velog.io/@hey-chocopie/C-Module-06
* CPP Module 07 : https://velog.io/@hey-chocopie/C-Module-07-unl0fq2z
* CPP Module 08 : https://velog.io/@hey-chocopie/C-Module-08

# 한줄평
### CPP Module 00
ex00 : 처음 진행하는 cpp과제였습니다. for문이 과제에서 처음으로 허용되었습니다. std에 포함된  string, tolower, cout, endl등 편리한 기능들을 사용해 볼 수 있어서 좋았습니다.
ex01 : 클래스에 static변수를 이용해 공통되는 클래스를 사용하는 객체들은 하나의 static 변수를 공유하며 사용하는 방법을 배웠습니다. 클래스를 이용해 매게함수 사용 및 변수 private, public 권한 지정자 사용법을 익혔습니다. 
ex02 : 과제에서 주어지는 tests.cpp를 보며, iterator  사용법, vector 초기화 방법, begin, end등 유용한 cpp 기능들을 접해볼수 있었습니다.
### CPP Module 01
ex00 : 인스턴스를 생생할때, 힙으로도 생성해보고 스택으로도 생성해보며 생성자와 소멸자의 심행 순서를 파악하는 과제였습니다.
ex01 : 한번에 여러개의 인스턴스를 만들수 있습니다 .이번 과제에서 직접 여러 인스턴스를 생성해보고 소멸자도 확인해봤습니다.
ex02 : 참조와 변수의 주소, 차이점을 확인하는 과제였습니다. 결론적으로 참조나, 포인터 주소를 주는것과 똑같이 작동합니다. 대신 포인트 주소를 쓰면, 새로운 변수를 만들고, 거기에다가 주소를 저장해야겠죠?!, 그 차이입니다!
ex03 : 생성자 사용시, 초기화 리스트가 있다는걸 알게되었고 초기화 리스트의사용법고 사용해하는 곳들을 알게되었다.

ex04 : ostream, ofstream에 대해 배움니다.
ex05 : 매개함수를 만들어보고 출력해봤고, if문 없이 조건처리 하는 방법을 알아봤다.
ex06 : switch case문을 통해, 출력이나 조건들을 손쉽게 관리하는 방법을 익혔다. 잘 사용하면 좋으니까 적극이용할것!

### CPP Module 02
ex00 : 부동소수점과 고정소수점 개념을 공부했고, 복사 연산자와 =operator을 사용해 보았다.
ex01 : 
ex02 : operator 연산자를 사용해 보았고, 고정소수점 비교연산자와 산술연산자 모두 사용해 보았다. 고정 소수점을 곱하거나 나눌경우 << 8을 raw_bit에 해준 상태이기 떄문에, raw_bit끼리 곱하거나 나눈후 추가적인 처리를 해주어야한다! 다른 operator들은 비슷했지만, "<<"을 사용할때는 ostream을 사용해야해서 operator<< 은 전역변수로 선언하고 사용했다.

### CPP Module 03
ex00 : 앞서 했던 과제와 비슷했습니다. 아마  ex01, ex02, ex03을 만들기위해 필요한 자료들을 만든거 같습니다!
ex01 : 자식 클래스 ScavTrap이 부모클래스 ClapTrap를 상속받았음. 이 때 부모클래스와 자식클래스 모두 해당되는 매게함수가 있다면? 인스턴스를 생성할때 사용한 클래스의 매게함수가 불러와짐. 자식 클래스의 인스턴스를 소멸시키면, 자식클래스의 소멸자와 부모클래스의 소멸자 모두 불러옴. 그러기 싫으면 부모 클래스의 소멸자를 virtual로 선언할 것.
ex02 : ex01이랑 거의 비슷함. ex03의 다이아몬드 상속을 해볼려고 구현함.
ex03 :다중상속에서 중요한 다이아몬드 상속을 배운다. ClapTrap은 중복해서 상속하게 되는데, 이를 virtual로 처리해 유동적으로 상속받는 방법을 배울수 있어서 좋았다. 생성한 클래스를 재활용하는 걸 확실하게 익힌거 같다.

### CPP Module 04
ex00 : 이번장에서는 부모클래스로 생성한 인스턴스에, 자식클래스 동적할당한 인스턴스를 넣어보았다. 이전장에서는 부모 클래스의 매게함수를 그냥 생성햇는데, 자식클래스와 중복되는 매게함수는 virtual로 정의해서 사용했다. 그러니, 부모클래스에 자식클래스를 담아도 중복되는 함수는 자식클래스로 생성되었다. 이론적으로 다 이해하지 못한거 같다. 업케스팅과 다운케스팅을 공부해보자.
ex01 : 이중포인터를 통해 한번에 여러개의 객체를 생성하는걸 배웠고, 업다운캐스팅간 생성자와 소멸자간 순서를 알게되었다. 처음 봤을땐 과제의 의도를 잘 몰랐는데, 해당 과제에서 업케스팅이 나왔고 업케스팅을 공부해보니, 업케스팅의 코드재활용 용의 점을 확실히 배울수 있어서 좋았다.
ex02 : 
ex03 :

### CPP Module 05
 작성중

### CPP Module 06
 작성중

### CPP Module 07
 작성중

### CPP Module 08
 작성중


# 배우는 내용
* CPP Module 00 : Namespace, class, member functions, stdio stream, initialization lists, static, const, and lots of basic stuf
* CPP Module 01 : Memory allocation, references, pointers to members, switch
* CPP Module 02 : Ad-hoc polymorphism, operators overload and orthodox canonical classes
* CPP Module 03 : Inheritance
* CPP Module 04 : Subtype polymorphism, abstract classes, interfaces
* CPP Module 05 : Repetition and Exceptions
* CPP Module 06 : C++ Casts
* CPP Module 07 : c++ Templates
* CPP Module 08 : Templated containers, iterators, algorithms

# CPP_Module 기본규칙
* Any function implemented in a header (except in the case of templates), and any unprotected header, means 0 to the exercise.
* Every output goes to the standard output, and will be ended by a newline, unless
specified otherwise.
* The imposed filenames must be followed to the letter, as well as class names, function names and method names.
* Remember: You are coding in C++ now, not in C anymore. Therefore:
* The following functions are FORBIDDEN, and their use will be punished by a 0, no questions asked: *alloc, *printf and free.
* You are allowed to use basically everything in the standard library. HOWEVER, it would be smart to try and use the C++-ish versions of the functions you are used to in C, instead of just keeping to what you know, this is a new language after all. And NO, you are not allowed to use the STL until you actually are supposed to (that is, until module 08). That means no vectors/lists/maps/etc... or anything that requires an include <algorithm> until then.
* Actually, the use of any explicitly forbidden function or mechanic will be punished by a 0, no questions asked.
* Also note that unless otherwise stated, the C++ keywords "using namespace" and "friend" are forbidden. Their use will be punished by a -42, no questions asked.
* Files associated with a class will always be ClassName.hpp and ClassName.cpp, unless specified otherwise.
* Turn-in directories are ex00/, ex01/, . . . , exn/.
* You must read the examples thoroughly. They can contain requirements that are not obvious in the exercise’s description. If something seems ambiguous, you don’t understand C++ enough.
* Since you are allowed to use the C++ tools you learned about since the beginning, you are not allowed to use any external library. And before you ask, that also means no C++11 and derivates, nor Boost or anything your awesomely skilled friend told you C++ can’t exist without.
* You may be required to turn in an important number of classes. This can seem tedious, unless you’re able to script your favorite text editor.
* Read each exercise FULLY before starting it! Really, do it.
* The compiler to use is clang++.
* Your code has to be compiled with the following flags : -Wall -Wextra -Werror.
* Each of your includes must be able to be included independently from others.
Includes must contains every other includes they are depending on, obviously.
* In case you’re wondering, no coding style is enforced during in C++. You can use
any style you like, no restrictions. But remember that a code your peer-evaluator
can’t read is a code she or he can’t grade.
* Important stuff now : You will NOT be graded by a program, unless explictly stated in the subject. Therefore, you are afforded a certain amount of freedom in how you choose to do the exercises. However, be mindful of the constraints of each exercise, and DO NOT be lazy, you would miss a LOT of what they have to offer !
* It’s not a problem to have some extraneous files in what you turn in, you may choose to separate your code in more files than what’s asked of you. Feel free, as long as the result is not graded by a program.
* Even if the subject of an exercise is short, it’s worth spending some time on it to be absolutely sure you understand what’s expected of you, and that you did it in the best possible way.
* By Odin, by Thor! Use your brain!!!
