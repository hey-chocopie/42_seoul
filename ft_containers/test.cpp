#include <memory>
#include <iostream>
#include <string>
int main()
{
//    std::allocator<int> a1;   // default allocator for ints
//    int* a = a1.allocate(1);  // space for one int
////	char	*str = (char*)malloc(sizeof(char) * 10);
//    a1.construct(a, 7);       // construct the int
//    std::cout << a[0] << '\n';
//	a1.destroy(a);
//    a1.deallocate(a, 1);      // deallocate space for one int

	 std::allocator<std::string> a2;
     std::string* s = a2.allocate(2); // space for 2 strings

    a2.construct(s, "foo");
    a2.construct(s + 1, "bar");
//	이들은 개체가 생성되거나 파괴될 때 명시적으로 개체의 생성자와 소멸자를 호출하는 함수들이고, destroy()의 경우 명시적으로 소멸자를 호출하는 것이 전부이다.
    std::cout << s[0] << ' ' << s[1] << '\n';

//    a2.destroy(s);
//    a2.destroy(s + 1);
    a2.deallocate(s, 2); // 추측이지만 destroy는 생성자 소멸자 개념떄문에 있는듯.
	return 0;
}
