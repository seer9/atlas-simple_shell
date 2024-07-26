# Simple Shell Project

## Contents

[Synopsis](#synopsis)<br>
[Description](#description)<br>
[Authors](#authors)<br>
[Flowchart][#flowchart]<br>

## Synopsis

This project creates a simple Unix-like shell program, codenamed T.S. SHELLiot (Thames-Sexton Shell), taking in user input and executing the given commands.

## Description

T.S. SHELLiot implements a simple command-line shell that mimics basic Unix shell functionality. It continuously displays a prompt ($) and allows users to execute commands by typing them into the terminal. The shell can handle interactive and non-interactive modes, parsing user input and executing commands using execve. It also gracefully handles end-of-file (EOF) signals and displays appropriate error messages for invalid commands.

## Flowchart

```mermaid
flowchart TB
	A[Start Shell] --> B[Initialize Variables]
	B --> C[Begin Loop]
	C --> D[Display Prompt]
	D --> E[Read Input]
	E --> F{Read Success?}
	F -- No --> G[Free/Exit]
	F -- Yes --> H[Tokenize Input]
	H --> I{Tokenization Success?}
	I -- No --> J[Free/Continue]
	I -- Yes --> K[Check for Built-Ins]
	K --> L{Built-In Found?}
	L -- Yes --> M[Execute Built-In]
	M --> N[Free/Continue]
	L -- No --> O[Search for Executable]
	O --> P{Executable Found?}
	P -- No --> Q[Free/Error/Continue]
	P -- Yes --> R[Fork Process]
	R --> S{Fork Success?}
	S -- No --> T[Free/Error/Continue]
	S -- Yes --> U{Child Process Success?}
	U -- Yes --> Z[Parent Waits]
	V --> W{Execution Success?}
	W -- No --> X[Free/Error/Continue]
	W -- Yes --> Y[SUCCESSFUL COMMAND EXECUTION]
	U -- No --> V[Execute]
	Z --> AA[Free/Update Status/Continue]
	AA --> C
	J --> C
	N --> C
	Q --> C
	T --> C
	X --> C
	Y --> C
```

## Authors

[@internashionalist](https://github.com/internashionalist/internashionalist/blob/main/README.md)

[@seer9]()
