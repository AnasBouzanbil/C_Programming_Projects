# minishell

minishell is a project that aims to implement some behaviors of the bash, such as executing commands (single or multi-command in one line), redirection, and some other features using only C language.

## Benefits

During this project, I found that I was able to understand how bash is working, and I was able to implement those behaviors.

## Implementation Details

I utilized several key functions in the implementation of this project:

- **execve():** A function that executes a program. It takes the path of the program, a pointer to an array of character pointers, and a pointer to an array of character pointers.

- **readline():** This function is used to read a line from the specified stream and returns a pointer to the string.

- **open():** Used to open a file and obtain a file descriptor.

- **access():** Checks whether the calling process can access the file pathname.

- **stat():** Retrieves the status of the file pointed to by pathname.

- **waitpid():** It suspends the execution of the calling process until a child specified by the pid argument has changed state.
