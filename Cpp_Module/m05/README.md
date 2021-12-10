# C++ - Module 05

>Repetition and 예외처리 에 대해 배웁니다. 

# Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!
### 예외처리로 사용되는 try catch문과 예외에서 사용되는 std::exception 클래스를 배울수 있었다. operator가 전역변수로도 사용되고 클래스의 매게함수로도 사용되는데 두개의 차이를 배웠다. 

```
Turn-in directory : ex00/
Files to turn in : Makefile Bureaucrat.hpp Bureaucrat.cpp main.cpp
Forbidden functions : None
```

Please note that exception classes do not need to be in orthodox canonical form.
Every other class needs to be written in that way.
Today, we’re going to create an artificial nightmare of offices, corridors, forms, and
waiting in line. Sounds fun? No? Too bad.
First, we start by the smallest cog in the vast bureaucratic machine: the Bureaucrat.
It must have a constant name, and a grade, that ranges from 1 (highest possible) to
150 (lowest possible). Any attempt to create a Bureaucrat with an invalid grade must
throw an exception, which will be either a Bureaucrat::GradeTooHighException or a
Bureaucrat::GradeTooLowException.
You will provide getters for both these attributes (getName and getGrade), and two
functions to increment or decrement the grade. Both these functions will throw the same
exceptions as before if the grade gets too high or too low. Remember, grade 1 is highest,
150 is lowest, so incrementing a grade 3 gives you a grade 2...
The exceptions you throw must be catchable by a block like:

```
try
{
/* do some stuff with bureaucrats */
}
catch (std::exception & e)
{
/* handle exception */
}v
```

You will provide an overload of the << operator to ostream that outputs something
like <name>, bureaucrat grade <grade>.
Of course, you will provide a main function to prove you did all this well.


# Exercise 01: Form up, maggots!
### 한줄평 : Form라는 클래스의 매게함수(beSigned) 중 메게인자로 Bureaucrat객체를 넘겨주는 방법을 배웠다. 그외에는 지금까지 했던거랑 특별하게 다른점은 없었다. 

```
Turn-in directory : ex01/
Files to turn in : Same as before + Form.cpp Form.hpp
Forbidden functions : None
```

Now that we have bureaucrats, better give them something to do with their time.
What better occupation than a stack of forms to fill out?
Make a Form class. It has a name, a boolean indicating whether it is signed (at
the beginning, it’s not), a grade required to sign it, and a grade required to execute it.
The name and grades are constant, and all these attributes are private (not protected).
The grades are subject to the same constraints as in the Bureaucrat, and exceptions
will be thrown if any of them are out of bounds, Form::GradeTooHighException and
Form::GradeTooLowException.
SaOBOBme as before, make getters for all attributes, and an overload of the << operator
to ostream that completely describes the state of the form.
You will also add a beSigned function that takes a Bureaucrat, and makes the form
signed if the bureaucrat’s grade is high enough. Always remember, grade 1 is better than
grade 2. If the grade is too low, throw a Form::GradeTooLowException.
Also add a signForm function to the Bureaucrat. If the signing is successful, it will
print something like "<bureaucrat> signs <form>", otherwise it will print something
like "<bureaucrat> cannot sign <form> because <reason>".
Add whatever’s needed to test this to your main.


# Exercise 02: No, you need form 28B, not 28C...
### 한줄평 : 클래스간 교차참조에 대해 배웠다. Bureaucrat클래스 에서도 ShrubberyCreationForm을 호출했고 ShrubberyCreationForm 클래스에서도 Bureaucrat 생성을 할려고하는데 서로서로 정의가 안된상태이니 컴파일 에러가 났다. 그래서 class Bureaucrat, class ShrubberyCreationForm 나중에 정의 하겠다고 암시해주고 클래스들을 정의했다.  또한 업케스팅 시 소멸자 호출에 대해서도 공부했다. 업케스팅시 자식 소멸자는 실행이 안되었고, 이를 해결하기 위해 virtual을 이용해 해결했다. virtual을 하면 객체에 virtual table이라는 공간이 생긴다는걸 공했다.  

```
Turn-in directory : ex02/
Files to turn in : Same as before + ShrubberyCreationForm.[hpp,cpp]
RobotomyRequestForm.[hpp,cpp] PresidentialPardonForm.[hpp,cpp]
Forbidden functions : None
```

Now that you have basic forms, you will make a few forms that actually do something.
Create a few concrete forms:
• ShrubberyCreationForm (Required grades: sign 145, exec 137). Action: Create
a file called <target>_shrubbery, and write ASCII trees inside it, in the current
directory.
• RobotomyRequestForm (Required grades: sign 72, exec 45). Action: Makes some
drilling noises, and tell us that <target> has been robotomized successfully 50% of
the time. Otherwise, tell us it’s a failure.
• PresidentialPardonForm (Required grades: sign 25, exec 5). Action: Tells us
<target> has been pardoned by Zafod Beeblebrox.
All of these will have to take only one parameter in their constructor, which will
represent the target of the form. For example, "home" if you want to plant shrubbery at
home. Remember the form’s attributes need to remain private, and in the base class.
Now you need to add a method execute(Bureaucrat const & executor) const to
the base form, and implement a method executing the form’s action in all the concrete
forms. You have to check that the form is signed, and that the bureaucrat attempting to
execute the form has a high enough grade, else you will throw an appropriate exception.
Whether you want to make these checks in every concrete class or make the check-in the
base class then calling another method to execute the action is up to you, but one way
is prettier than the other one. In any event, the base form must be an abstract class.
Finish this by adding an executeForm(Form const & form) function to the bureaucrat. It must attempt to execute the form, and if it’s a success, print something like
<bureaucrat> executes <form>. If not, print an explicit error message.
Add whatever you need to your main to test that everything works.


# Exercise 03: At least this beats coffee-making
### 한줄평 : 지난시간에 했던, 업케스팅 다운케스팅을 사용해보는 과제였다. 업케스팅의 장점은 부모 클래스 하나로 여러 자식들의 자료형을 리턴으로 받을수 있다. 하나의 함수를 재활용할수 있다.!!
```
At least this beats coffee-making
Turn-in directory : ex03/
Files to turn in : Same as before + Intern.hpp Intern.cpp
Forbidden functions : None
```

Because filling out forms is annoying enough, it would just be cruel to ask our bureaucrats to write them entirely by themselves. No, we’ll just have an intern do that.
You’re going to create the Intern class. The intern has no name, no grade, no defining characteristics whatsoever, we only care that it does its job.
The intern has one important thing, the makeForm function. It takes two strings, the
first representing the name of a form, and the second one being the target for the form. It
will return, as a pointer to Form, a pointer to whichever concrete form class is represented
by the first parameter, initialized with the second parameter. It will print something like
"Intern creates <form>" to the standard output. If it’s using a worse method, like
if/elseif/elseif/else branchings, or some other ugly stuff like this, it will not be accepted
during the evaluation. If the requested form is not known, print an explicit error message.
For example, this would create a RobotomyRequestForm targeted on "Bender":

```
{
Intern someRandomIntern;
Form* rrf;
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
```

Your main must, of course, test all of this.
