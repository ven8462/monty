# THE MONTY PROJECT

- The Monty language is a scripting language that uses a unique stack data structure. The goal is to create an interpreter for Monty bytecode files. The interpreter reads a bytecode file containing instructions and executes them line by line. Instructions manipulate a stack, which is a data structure that follows a Last-In-First-Out (LIFO) principle. The interpreter implements the stack using a doubly linked list. It performs error handling, checks for the correct number of arguments, opens the file, and validates instructions. The program is compiled and executed from the command line, taking the bytecode file as an argument. It executes the instructions, updates the stack accordingly, and provides output or error messages. 

- By updating the stack I mean, lets say the intepreter we created checks the monty file we've provided and the instruction read is ** push **  the interpreter adds the value to the top of the stack
