# Simple Shell Project

>*"If you aren't in over your head, how do you know how tall you are?"*<br>
\-T.S. Eliot

## Contents

[Synopsis](#synopsis)<br>
[Description](#description)<br>
[Authors](#authors)<br>
[Use Instructions](#use-instructions)<br>
[Features](#features)<br>
[Flowchart](#flowchart)<br>
[Authors](#authors)

## Synopsis

This project creates a simple Unix-like shell program, codenamed T.S. SHELLiot (Thames-Sexton Shell), taking in user input and executing the given commands.

## Description

T.S. SHELLiot implements a simple command-line shell that mimics basic Unix shell functionality. It continuously displays a prompt ($) and allows users to execute commands by typing them into the terminal. The shell can handle interactive and non-interactive modes, parsing user input and executing commands using execve. It also gracefully handles end-of-file (EOF) signals and displays appropriate error messages for invalid commands.

## Use Instructions

**Clone into T.S. SHELLiot's Repository:**
```
git clone https://github.com/seer9/atlas-simple_shell.git
```
**Open the Shell Directory:**
```
cd atlas-simple_shell
```
**Compile Contents:**
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
**Run Shell Program:**
```
./hsh
```
**Command Shell:**
```
What we call the beginning is often the end.
TS SHELLIOT $ /bin/ls
```
**Exit Shell:**
```
TS SHELLIOT $ exit
The end is where we start from.

TS SHELLIOT $ ^D
This is the way the world ends,
Not with a bang but a whimper.
```

## Features
```
•Interactive and Non-Interactive Modes:
  - Interactive: Displays a prompt
  - Non-Interactive: Can process input from scripts or files

•Input Handling:
  - Reads input from the user using getline
	- Differentiates between NULL and End-Of-File with flag
	- Trims newline characters from the input

•Tokenization:
	- Splits input into tokens for further processing
	- Resizes the token array if number of tokens exceeds initial allocation

•Built-in Command Handling:
	- Processes exit and env commands
  - Executes built-in commands directly without creating a new process

•Command Execution:
	- Checks the status of the last executed command
	- Supports executing commands with arguments
  - Uses fork and execve to create child processes for command execution
  - Handles failures gracefully, allowing shell to continue

•Memory Management:
  - Frees allocated memory for input and tokens after each command execution
	- Allocates memory dynamically based on input size, ensuring efficient memory usage

•Modular Structure:
	- Uses a header file to declare function prototypes
	- Separates implementation into multiple source files

•Graceful Exit:
	- Exits gracefully whether upon encountering EOF or utilizing the exit built-in command
```


## Flowchart

![FlowChart](https://github.com/seer9/atlas-simple_shell/blob/main/flowchart.jpg)

## Authors

[@internashionalist](https://github.com/internashionalist/internashionalist/blob/main/README.md)

[@seer9]()
