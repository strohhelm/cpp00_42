# c++ Project 00 - First contact with OOP

##  General Rules for these projects: 
The purpose of these c++ projects is to get introduced into OOP. We are allowed to use standard c++17. 

- code must be coiled with `c++` and the flags `-Wall -Werror -Wextra`.
- there must be a Makefile for each exercise.
- Class names and corresponding filenames must be written in UpperCamelCase format.
- The `using namespace <ns_name>` and `friend` keywords are forbidden.
- There must be no memory leaks.
- Classes must be designed in the Orthodox Canonical Form.
- There can be no function implementations in headerfiles.
- Headers must be able to be used independently from others.
- Use of STL in the Module 08 and 09 only->no containers / Algorithm header

## 🔶 ex00 Megaphone
### Objective:  *write a program that behaves as follows:*
``` $>.\/megaphone \"shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF. $>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

### My thoughts:
This was a very easy introduction to the c++ way of solving this problem. Using the cout function and for loops. (prior in my c programming i wasnt allowed them)


## 🔶 ex01 My Awesome PhoneBook
### Ojective: Welcome to the 80s and their unbelievable technology! Write a program that behaves like a crappy awesome phonebook software.
- On program start-up, the phonebook is empty and the user is prompted to enter one of three commands.  
- The program only accepts ADD, SEARCH and EXIT.Once a command has been correctly executed, the program waits for another one  
- It stops when the user inputs EXIT.
