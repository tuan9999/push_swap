# push_swap
## Overview
This is my implementation for the push_swap project from Codam (42 Amsterdam). The essence of the project is that you have two stacks, a and b, and you need to sort a list of numbers in ascending order in the first stack. You are permitted to use the following operations on the two stacks:
- sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there are only one or no elements).
- sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there are only one or no elements).
- ss : sa and sb at the same time.
- pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

## Usage
Run `make`in the root of the repository. This will give you two programs **push_swap** and **checker**.