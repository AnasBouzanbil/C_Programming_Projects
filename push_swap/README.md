# push_swap

Push Swap is a project in the 42 curriculum with the objective of sorting a stack. Due to the structure of the stack, you will need to solve it using specific instructions.

<br />

## What are the instructions?

- `pa` and `pb`:
  To sort the stack, you will have a little help in the form of a temporary stack that will be used to store some data to return it back when you finish sorting.
  - `pa`: This is used when you want to push some element onto stack A.
  - `pb`: This is used when you want to push some element onto stack B.

- `sa` and `sb`:
  These instructions are used to swap the first (the top) element with the second element in the stack.

<p align="center">
  <img src="https://github.com/Elhazin/PNG/blob/main/Screenshot%20from%202023-10-01%2014-56-34.png" alt="Screenshot">
</p>

- `ra` and `rb`:
  These instructions will rotate the elements, with the first (the top) element becoming the last element in the stack (at the bottom), and the second element becoming the top element in the stack.

<p align="center">
  <img src="https://github.com/Elhazin/PNG/blob/main/Screenshot%20from%202023-10-01%2015-10-04.png" alt="Screenshot">
</p>

- `rra` and `rrb`:
  These instructions are used to take the last element in the stack and move it to the first position in the stack. The first (the top) element in the stack will become the second element.

## How to work now?

You will need to find an algorithm that uses as few instructions as possible. First, you have to understand how the stack works and implement a stack data structure because in C, there is no built-in data structure called "stack."
