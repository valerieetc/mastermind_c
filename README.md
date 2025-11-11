# mastermind_c
***

## Task
The task was to make a program that simulates the Mastermind game by using numbers from 0 to 8 instead of colours.

## Description
In this version of the Mastermind game instead of a combination of colours you have to guess a combination of
four digits from 0 to 8 that don't repeat themselves. When you make a guess, the game tells you how many
correctly placed digits you have and how many digits are correct, but misplaced. You have a limited amount
of attempts - you either set the attempt number yourself, or it is 10 by default.

## Installation
The project is installed by typing "make" in the terminal.

## Usage
You can run the program without putting in any options, and it will automatically generate a random code.
You can type in your secret code by typing "-c CODE". The code should contain four different digits from 0 to 8.
You can type in a set number of attempts by typing "-t NUMBER" which should be greater than 0.
You can set both the code and the number of attempts at the same time.
When you're prompted for a guess, instead of the guess you can press Ctrl + D to exit the game.
```
./my_project -c 1234 -t 12
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
