# Exercise 00: Aaaaand... OPEN!
### 한줄평 : ex01, ex02, ex03을 만들기위해 필요한 자료들을 만들었습니다!

```
Turn-in directory : ex00/
Files to turn in : Makefile ClapTrap.cpp ClapTrap.hpp main.cpp
Forbidden functions : None
```

Here you have to make a class! How original!
The class will be called ClapTrap, and will have the following private attributes,
initialized to the specified values:

	• Name (Parameter of constructor)
	• Hitpoints (10)
	• Energy points (10)
	• Attack damage (0)
You will also give it a few public functions to make it more life-like:

	• void attack(std::string const & target)
• void takeDamage(unsigned int amount)
• void beRepaired(unsigned int amount)

	In all of these functions, you have to display something to describe what happens.
For example, the attack function may display something along the lines of:

ClapTrap <name> attacks <target>, causing <damage> points of damage!

The constructor and destructor must also display something, so people can see they
have been called.
You will provide a main function, with enough tests to demonstrate that your code is
functional.

# Exercise 01: Serena, my love!
### 한줄평 : 자식 클래스 ScavTrap이 부모클래스 ClapTrap를 상속받았음. 이 때 부모클래스와 자식클래스 모두 해당되는 매게함수가 있다면? 인스턴스를 생성할때 사용한 클래스의 매게함수가 불러와짐. 자식 클래스의 인스턴스를 소멸시키면, 자식클래스의 소멸자와 부모클래스의 소멸자 모두 불러옴. 그러기 싫으면 부모 클래스의 소멸자를 virtual로 선언할 것. 

```
Turn-in directory : ex01/
Files to turn in : Same as previous exercise + ScavTrap.cpp ScavTrap.hpp
Forbidden functions : None
```

Because we can’t ever have enough Claptraps, now you will make another one.
The class will be named ScavTrap, and will inherit from ClapTrap, the constructor,
destructor, and attacks have to use different outputs. After all, a Claptrap has to have
some measure of individuality.
The ScavTrap class will have its construction and destruction messages. Also, proper
construction/destruction chaining must be present (When you build a ScavTrap, you
must start by building a ClapTrap... Destruction is in reverse order), and the tests have
to show it.

ScavTrap will use the attributes of Claptrap (You need to change Claptrap accordingly)! And must initialize them to:
• Name (Parameter of constructor)
• Hitpoints (100)
• Energy points (50)
• attack damage (20)

ScavTrap will also have a new specific function: void guardGate(); this function
will display a message on the standard outputs to anounce that ScavTrap have enterred
in Gate keeper mode.

Extend your main function to test everything.


# Exercise 02: Repetitive work
# 한줄평 : ex01이랑 거의 비슷함. ex03의 다이아몬드 상속을 해볼려고 구현함. 

```
Turn-in directory : ex02/
Files to turn in : Same as previous exercise + FragTrap.cpp FragTrap.hpp
Forbidden functions : None
```

Making Claptraps is probably starting to get on your nerves.
Now, you will make a FragTrap class that inherits from ClapTrap.

• Name (Parameter of constructor)
• Hitpoints (100)
• Energy points (100)
• attack damage (30)

The FragTrap class will have its construction and destruction messages. Also, proper
construction/destruction chaining must be present (When you build a FragTrap, you
must start by building a ClapTrap... Destruction is in reverse order), and the tests have to show it.

The specific function for FragTrap will be void highFivesGuys(void) and will display a positive high fives request on the standard output.

Extend your main function to test everything.

# Exercise 03: Now it’s weird!
### 한줄평 : 다중상속에서 중요한 다이아몬드 상속을 배운다. ClapTrap은 중복해서 상속하게 되는데, 이를 virtual로 처리해 유동적으로 상속받는 방법을 배울수 있어서 좋았다. 생성한 클래스를 재활용하는 걸 확실하게 익힌거 같다. 


```
Turn-in directory : ex03/
Files to turn in : Same as previous exercise + DiamondTrap.cpp DiamondTrap.hpp
Forbidden functions : None
```

Now, you will create a monster by making a Claptrap that’s half Fragtrap, half Fragtrap.
It will be named DiamondTrap, and it will inherit from both the FragTrap AND the
ScavTrap.

Very risky and horrible act the DiamondTrap class will declare a private attribute
called name like the one inside ClapTrap.

Its attributes and functions will be chosen from either of its parent classes:

• Name (Parameter of constructor)
• Claptrap::Name (Parameter of constructor + "_clap_name")
• Hitpoints (Fragtrap)
• Energy points (Scavtrap)
• Attack damage (Fragtrap)
• attack (Scavtrap)

It will have the special functions of both.
As usual, your main will be extended to test the new class.
Of course, the Claptrap part of the Diamondtrap will be created once, and only once...
Yes, there’s a trick.


