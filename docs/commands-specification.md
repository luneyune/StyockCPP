I/O commands
 - readd - read decimal number from STDIN and push in stack
 - readc - read single character from STDIN and push in stack
 - reads - read string from STDIN and push in stack in reverse order (symbol '\0' placed in depth)
---
 - printd - take a decimal number from top of stack and print into STDOUT
 - printc - take a character from top of stack and print into STDOUT
 - prints - take items from stack and print them into STDOUT until '\0' string will be deleted during this operation
---
Control commands
 - stop - end programm
 - jmp \<arg\> - jump to the command with index arg
 - js - jump to the command with index from top element of stack
---
 - jl \<arg\> - jump to the command with index arg if top of stack < 0
 - jle \<arg\> - jump to the command with index arg if top of stack <= 0
 - jg \<arg\> - jump to the command with index arg if top of stack > 0
 - jge \<arg\> - jump to the command with index arg if top of stack >= 0
 - je \<arg\> - jump to the command with index arg if top of stack = 0

*Note: top element of stack will be removed during all conditional jumps and js*

 ---

Data operation commands

 - push \<arg\> - pushes number, or string, or list of numbers separated by space. String or list of numbers will be pushed in reverse order. If no arguments provided then duplicating top element.
 - pop - remove top element of stack

---

Math operation commands

 - add - takes 2 numbers from stack, and push result of sum of this 2 numbers
 - sub - takes 2 numbers from stack, and push result of sub of this 2 numbers
 - div - takes 2 numbers from stack, and push result of div of this 2 numbers
 - mod - takes 2 numbers from stack, and push result of mod of this 2 numbers
 - mul - takes 2 numbers from stack, and push result of mul of this 2 numbers
 - cmp - takes 2 numbers from stack, and push result of comparing of this 2 numbers, result will rewrite only last pushed number

*Note: numbers order defined by input order from stack*

*For example:*
~~~
PUSH 9
PUSH 5
SUB
PRINTD

4
~~~


