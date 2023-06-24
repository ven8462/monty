#!/bin/bash

echo "executing bytecodes/000.m"
valgrind ./monty bytecodes/000.m

echo "executing bytecodes/001.m"
valgrind ./monty bytecodes/001.m

echo "executing bytecodes/00 (push and pall).m"
valgrind ./monty bytecodes/00.m

echo "executing bytecodes/01.m"
valgrind ./monty bytecodes/01.m

echo "executing bytecodes/06 (pint).m"
valgrind ./monty bytecodes/06.m

echo "executing bytecodes/07 (pop).m"
valgrind ./monty bytecodes/07.m

echo "executing bytecodes/09.m (swap)"
valgrind ./monty bytecodes/09.m

echo "executing bytecodes/12.m (add)"
valgrind ./monty bytecodes/12.m

echo "executing bytecodes/13.m (nop)"
valgrind ./monty bytecodes/13.m

echo "executing bytecodes/19.m (sub)"
valgrind ./monty bytecodes/19.m

echo "executing bytecodes/20.m (div)"
valgrind ./monty bytecodes/20.m

echo "executing bytecodes/21.m (mul)"
valgrind ./monty bytecodes/21.m

echo "executing bytecodes/22.m (mod)"
valgrind ./monty bytecodes/22.m

echo "executing bytecodes/2.m"
valgrind ./monty bytecodes/2.m
