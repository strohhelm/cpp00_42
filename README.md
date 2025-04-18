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

## Usage:
  ```
  $> make
  $> ./<executable>
```

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

My output example:  
![rendering](/img/start)

### My thoughts:
This was a very fun first time playing with c++. I had to look up basically everything that i wrote and it took way longer than intended since i wanted to make it fancy also.
For example the output gets interrupted after each character written to the std output by making the thread sleep for some time. This way it feels more immersive and fun in my opinion.
Also i handled signal interrupts and EOF in the input operations and made some fun exiting "animations".

## 🔶 ex02 The Job Of Your Dreams
### Ojective: Recreate the Accounts.cpp file that got "lost". 
- The main funciton and .hpp file are left over.
- The output must be exactly the same except for the timestamps and order of constructors / destructors.

### My thoughts:
- This was interesting because i had to read understand the provided code.
- To recreate the functionality i had to see the funtions in the headerfile, how they are used in the main function and what output they produce in the provided file.
- The output had to be perfect, so each character printed was to be considered otherwise it counted as a fail.
