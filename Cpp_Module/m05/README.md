# C++ - Module 05

>Repetition and 예외처리 에 대해 배웁니다. 

# Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!
### 예외처리로 사용되는 try catch문과 예외에서 사용되는 std::exception 클래스를 배울수 있었다. 

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



