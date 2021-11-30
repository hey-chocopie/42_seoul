# CPP Module 00
이 장에서는 Namespace, class, member functions, stdio stream, initialization lists, static, const, and lots of basic stuf 에 대해 배울 수 있습니다.

### CPP Module 00에 도움되는 개념들을 정리해 두었습니다!
https://velog.io/@hey-chocopie/cpp-%EA%B0%9C%EB%85%90%EA%B3%B5%EB%B6%80

# Exercise 00: Megaphone

Just to be sure that everybody is awake, write a program that has the following
behavior:
(Use C++ style to interact with stdin!)

```
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

# Exercise 01: My Awesome PhoneBook
>Turn-in directory : ex01/
Files to turn in : Makefile, *.cpp, *.{h, hpp}
Forbidden functions : None

Welcome to the 80s and its unbelievable technology! Write a program that behaves
like a crappy awesome phonebook software. Please take some time to give your executable a relevant name. When the program starts, the user is prompted for input: you
should accept the ADD command, the SEARCH command or the EXIT command. Any other
input is discarded.

The program starts empty (no contacts), doesn’t use any dynamic allocation, and
can’t store more than 8 contacts. If a ninth contact is added, replace the oldest contact.

• If the command is EXIT:
	◦ The program quits and the contacts are lost forever.

• Else if the command is ADD:
	◦ The program will prompt the user to input a new contact’s information, one field at a time, until every field is accounted for.
	◦ A contact is defined by the following fields: first name, last name, nickname,
phone number,darkest secret.
	◦ The PhoneBook must be represented as as an instance of a class in your code it must contain an array of contact.
	◦ A contact MUST be represented as an instance of a class in your code. You’re free to design the class as you like, but the peer evaluation will check the consistency of your choices. Go look at today’s videos again if you don’t understand what I mean (and I don’t mean "use everything" before you ask).
• Else if the command is SEARCH:
	◦ The program will display a list of the available non-empty contacts in 4 columns: index, first name, last name and nickname.
	◦ Each column must be 10 chars wide, right aligned and separated by a ’|’ character. Any output longer than the columns’ width is truncated and the last displayable character is replaced by a dot (’.’).
	◦ Then the program will prompt again for the index of the desired entry and displays the contact’s information, one field per line. If the input makes no sense, define a relevant behavior.
• Else the input is discarded.
	When a command has been correctly executed, the program waits for another ADD or SEARCH command until an EXIT command.

