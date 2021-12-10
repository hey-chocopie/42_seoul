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

# Exercise 02: abstract class
### 한줄평: 추상 클래스에 대해 접해보았다. 추상클래스는 부모 클래스에 하나라도 순수가상함수가 있으면 추상클래스다. 추상클래스는 혼자서 정의할수 없다. 이유는 순수가상함수라서 함수 정의가 안되어있기 때문에 추상클래스로 인스턴스화 할려고 할때 에러가 발생한다. 

```
Turn-in directory : ex02/
Files to turn in : Makefile, main.cpp, plus any needed files
Forbidden functions : None
```

A general Animal doesn’t make sense after all.
For example, it makes no sound!
To avoid any future mistakes, the default animal class should not be instantiable.
Fix the Animal class so nobody instantiates it by mistakes.

The rest should work as before.

# Exercise 03: Interface & recap
### 한줄평 : 순수가상함수를 만들고, 자식클래스를 이용해 사용하는 방법을 배웠다. m04는 전체적으로 비슷한 내용이였다. 업 캐스팅 이용해서 하나의 부모클래스로 여러개의 자식클래스를 사용할수 있었다.  

```
Turn-in directory : ex03/
Files to turn in : Makefile, main.cpp, plus any needed files
Forbidden functions : None
```

There’s no interface in C++98 (not even in C++20) but it’s common to call pure abstract
class Interface. So for this last exercise let’s try interfaces and recap everything!
Complete the definition of the following AMateria class, and implement the necessary member functions.

```
class AMateria
{
protected:
[...]
public:
AMateria(std::string const & type);
[...]
std::string const & getType() const; //Returns the materia type
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};
```

Create the concrete Materias Ice and Cure . Their type will be their name in
lowercase ("ice" for Ice, etc...).
Their clone() method will, of course, return a new instance of the real Materia’s
type.

Regarding the use(ICharacter&) method, it’ll display:
• Ice: "* shoots an ice bolt at NAME *"
• Cure: "* heals NAME’s wounds *"
(Of course, replace NAME by the name of the Character given as parameter.)

> While assigning a Materia to another, copying the type doesn’t make
sense...

Create the Character class, which will implement the following interface:

```
class ICharacter
{
public:
virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;
};
```

The Character possesses an inventory of 4 Materia at most, empty at the start. He’ll
equip the Materia in slots 0 to 3, in this order.
In case we try to equip a Materia in a full inventory, or use/unequip a nonexistent
Materia, don’t do a thing.
The unequip method must NOT delete Materia!
The use(int, ICharacter&) method will have to use the Materia at the idx slot,
and pass target as parameter to the AMateria::use method.


> Of course, you’ll have to be able to support ANY AMateria in a
Character’s inventory.

Your Character must have a constructor taking its name as a parameter. Copy or
assignation of a Character must be deep, of course. The old Materia of a Character
must be deleted. Same upon the destruction of a Character .

Create the MateriaSource class, which will have to implement the following interface:

```
class IMateriaSource
{
public:
virtual ~IMateriaSource() {}
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
};
```

learnMateria must copy the Materia passed as a parameter, and store it in memory
to be cloned later. Much in the same way as for Character , the Source can know at
most 4 Materia, which are not necessarily unique.
createMateria(std::string const &) will return a new Materia, which will be a
copy of the Materia (previously learned by the Source) which type equals the parameter.
Returns 0 if the type is unknown.
In a nutshell, your Source must be able to learn "templates" of Materia and re-create
them on demand. You’ll then be able to create a Materia without knowing its "real" type,
just a string identifying it.
