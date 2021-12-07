C++ - Module 04
Subtype polymorphism, abstract classes, interfaces

# Exercise 00: Polymorphism
### 한줄평 : 이번장에서는 부모클래스로 생성한 인스턴스에, 자식클래스 동적할당한 인스턴스를 넣어보았다. 이전장에서는 부모 클래스의 매게함수를 그냥 생성햇는데, 자식클래스와 중복되는 매게함수는 virtual로 정의해서 사용했다. 그러니, 부모클래스에 자식클래스를 담아도 중복되는 함수는 자식클래스로 생성되었다. 이론적으로 다 이해하지 못한거 같다. 업케스팅과 다운케스팅을 공부해보자. 


```
Turn-in directory : ex00/
Files to turn in : Makefile, main.cpp, Every other files you need
Forbidden functions : None
```

For every exercise, your main must test everything.
Constructors and destructors of each class must have specifics output.
Create a simple and complete base class Animal.
The animal class got one protected attribute:
• std::string type;
Create a class Dog that inherits from Animal.
Create a class Cat that inherits from Animal.
(for the animal class the type can be left empty or put at any value).
Every class should put their name in the Type field for example:
The Dog class type must be initialized as "Dog".
Every animal must be able to use the method makeSound().
This method will display an appropriate message on the standard outputs based on the
class.

```
int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

...
}
```

This should output the specific makeSound of the Dog and cat class, not the animal
one.
To be sure you will create a WrongCat class that inherits a WrongAnimal class that will
output the WrongAnimal makeSound() when test under the same conditions.



# Exercise 01: I don’t want to set the world on fire
### 한줄평 : 이중포인터를 통해 한번에 여러개의 객체를 생성하는걸 배웠고, 업다운캐스팅간 생성자와 소멸자간 순서를 알게되었다. 처음 봤을땐 과제의 의도를 잘 몰랐는데, 해당 과제에서 업케스팅이 나왔고 업케스팅을 공부해보니, 업케스팅의 코드재활용 용의 점을 확실히 배울수 있어서 좋았다. 


```
Turn-in directory : ex01/
Files to turn in : Makefile, main.cpp, plus the needed files for your tests
Forbidden functions : None
```

You’ll reuse the Ex00 classes.
Create one class called Brain.
Brain will contain an array of 100 std::string called ideas
Now, Dog and cat will have a private Brain* attribute.

>Not every animal got a brain!

Upon construction Dog and Cat will initialize their Brain* with a new Brain();
Upon destruction Dog and Cat will delete their Brain.
Your main will create and fill an Array of Animal half of it will be Dog and the other
half will be Cat.
Before exit, your main will loop over this array and delete every Animal.
You must delete directly Cat and Dog as an Animal.
A copy of a Cat or Dog must be "deep".
Your test should show that copies are deep!
Constructors and destructors of each class must have specifics output.
The appropriate destructors must be called.

```
int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;
}
```


