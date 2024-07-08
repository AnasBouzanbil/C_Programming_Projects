

</p>
<p align="center">
<img src="https://github.com/Elhazin/PNG/blob/main/Screen%20Shot%202023-04-30%20at%207.34.48%20PM.png" width="250">

<p/>

# Pipex

This project is a part of the curriculum at 42 School. The goal of the project is to create a program in C that replicates the functionality of the shell command:

```bash
< infile cmd1 | cmd2 > outfile
```
The pipex program should take four arguments: infile, cmd1, cmd2, and outfile, and behave like the shell command. Here's an example of how to use pipex:

```bash
./pipex infile "cat -e" "wc -w" outfile
```
This command will take the contents of infile, run it through cat -e, and then pass the result to wc -w, before writing the final output to outfile.

## Usage/Examples

the task is not too difficult if you understand teh allowed function and how to use them

* Access
```c
int access(const char *path, int mode);
```

This function is used to check the file permission.
#####

const char *path: The file name with its path.
######
int mode: The type of access to check for (e.g., R_OK for read permission, W_OK for write permission, etc.).
####
* Fork

```
pid_t fork(void);
```
This function is used to create a new process that is called the child process.

The return value of the parent process is the PID of the child process.

The return value of the child process is 0.

In the case of failure, fork() returns -1.


* execve
```c
int execve(const char *file, char const **argv, char const **envp);
```
This function is used to run programs.

const char *file : is the name of the program with its path

char const *argv[] : is the the arguments that teh program takes

char const *envp[] : a list of environment variables


## Acknowledgements

 - [The Linux Programming inTerface](https://sciencesoftcode.files.wordpress.com/2018/12/the-linux-programming-interface-michael-kerrisk-1.pdf)
 - [Pipe() system call](https://www.geeksforgeeks.org/pipe-system-call/)
 - [Advanced Unix Programming](https://xesoa.com/wp-content/uploads/2014/04/APUE-3rd.pdf) 
 - [Introduction of Process Management](https://www.geeksforgeeks.org/introduction-of-process-management/)
 - [Pipex Tester](https://github.com/vfurmane/pipex-tester)
