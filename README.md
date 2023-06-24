# THE MONTY PROJECT

- The Monty language is a scripting language that uses a unique stack data structure. The goal is to create an interpreter for Monty bytecode files. The interpreter reads a bytecode file containing instructions and executes them line by line. Instructions manipulate a stack, which is a data structure that follows a Last-In-First-Out (LIFO) principle. The interpreter implements the stack using a doubly linked list. It performs error handling, checks for the correct number of arguments, opens the file, and validates instructions. The program is compiled and executed from the command line, taking the bytecode file as an argument. It executes the instructions, updates the stack accordingly, and provides output or error messages.

- By updating the stack I mean, lets say the intepreter we created checks the monty file we've provided and the instruction read is ** push **  the interpreter adds the value to the top of the stack

## The interpreter created can perform the following operations:

- push - pushes an element to the top of the stack
- pall - prints all the values on the stack following the LIFO rule
- pint - prints the value at the top of the stack
- pop - removes the top element of the stack
- swap - swaps the top two elements of the stack
- add - adds the top two elements of the stack
- nop - does not do anything
- sub - subtracts the top element of the stack from the second top element of the stack
- div - divides the second top element of the stack by the top element of the stack
- mul - multiplies the second top element of the stack with the top element of the stack
- mod - computes the rest of the division of the second top element of the stack by the top element of the stack
- # - When the first non-space character of a line is #, treat this line as a comment
- pchar - prints the char at the top of the stack, followed by a new line

