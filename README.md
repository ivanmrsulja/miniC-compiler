# miniC-compiler
Compiler for very simple C-like language that i wrote for my university course.

Architecture is simple as compiler only contains 2 major modules: lexical analysis and parser (which also contains logic for semantic analysis and code generation).
Flex and Bison were used to generate lexer and parser while semantic analysis and code generation were implemented from scratch using C.

## Project is divided into 3 directories:
- Semantic (containing lexical, syntax and semantic analysis only)
- Code (containing lexical, syntax and semantic analysis with code generation)
- Additional Functionalities (same as Code but with arrays included)

Output of code generation is the program written in "Hipotetical Assembly Language" (HAL). This language is a sort of intermediate language that was provided to me by my university. It can run on HIPSIM virtual machine that was also provided and is included in the project with the corresponding license (i do not own HIPSIM but it was modified by me in some parts to support certain constructs with regards to the license).

To run the tests that are included with the project simply use the Make tool by running `make test` or `make det` (for detailed information about tests). If you want to start interactive execution of HAL you can do so by executing commands that are listed in the documentation provided with HIPSIM VM. If you want to write your own tests, just follow the format of the tests that are allready provided, it is very simple (just 2 comments at the top of the file that you have to add along with the actual code).

## Some of the constructs included:
- single-line and multi-line comments
- single-line declaration (with definition possibility) of multiple variables
- postincrement operator
- int, unsigned and void types
- functions with multiple input parameters
- local variables at the start of every block
- if statement
- global variables
- ternary(conditional) operator
- while and for loops
- SWITCH statement
- arrays

and so on...
