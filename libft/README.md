# libft




<h4>As a student at 1337school, I completed the libft project which involved creating a library of basic C functions. This project required me to implement a variety of functions including memory and string manipulation.

Throughout this project, I sharpened my skills in C programming and gained a deeper understanding of how to manipulate memory and utilize pointers effectively. I also had to consider and implement various edge cases and error handling in each function.

Overall, the libft project was a challenging and rewarding experience that allowed me to develop my skills in C programming and deepen my understanding of the language. I am confident that the skills and knowledge I gained from this project will serve me well in my future projects. <br/>
<br>
## some resource that may help
         
In the 42 journey, our first project is 'libft.' To excel in it, I did a lot of reading to build my knowledge. I focused on helpful resources like old YouTube tutorials and books. For instance, I found a great <a href="http://cslibrary.stanford.edu/106/" target="_blank">book</a> that explains pointers well. Additionally, there's a useful <a href="http://cslibrary.stanford.edu/102/PointersAndMemory.pdf" target="_blank">PDF</a> about pointers and memory. You can find more valuable information on this <a href="http://cslibrary.stanford.edu/" target="_blank">website</a>. For advanced C programming, this <a href="https://users.ece.utexas.edu/~valvano/embed/" target="_blank">website</a> is also worth exploring


[objects file](https://stackoverflow.com/questions/7718299/whats-an-object-file-in-c#:~:text=An%20object%20file%20is%20just,debugging%20symbols%20and%20so%20forth.)<br/>
[Makefile](https://www.geeksforgeeks.org/how-to-use-make-utility-to-build-c-projects/) <br/>
[Makefile tutorial](https://makefiletutorial.com/)<br/>
[malloc](https://www.freecodecamp.org/news/malloc-in-c-dynamic-memory-allocation-in-c-explained/#:~:text=Malloc%20is%20used%20for%20dynamic,by%20value%20instead%20of%20reference.) <br/>
[DMA](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/?ref=rp)<br/>
[strucut](https://www.w3schools.com/c/c_structs.php#:~:text=Structures%20(also%20called%20structs)%20are,%2C%20char%2C%20etc.).)<br/>
[linked_list](https://www.youtube.com/watch?v=92S4zgXN17o&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P)<br/>
[function pointer](https://www.geeksforgeeks.org/function-pointer-in-c/)<br/>
[ovelaping](https://cs50.stackexchange.com/questions/14615/memory-overlap-in-c#:~:text=If%20the%20memory%20segments%20coincide,and%20copying%20to%20address%200x8F.)<br/>
[typecasting](https://byjus.com/gate/type-casting-in-c/#:~:text=Type%20Casting%20is%20basically%20a,want%20the%20program%20to%20do.)<br/>
[typecasting](https://www.tutorialspoint.com/cprogramming/c_type_casting.htm)<br/>
[type casting](https://en.wikipedia.org/wiki/Type_conversion)<br/>
[scope of function](https://www.tutorialspoint.com/cprogramming/pdf/c_scope_rules.pdf)<br/>
[file descriptor](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/)<br/>
[open function](https://pubs.opengroup.org/onlinepubs/007904875/functions/open.html)<br/>
[This book is awesome](http://cslibrary.stanford.edu/101/EssentialC.pdf)<br/>


## What is libft?

<p> libft is an individual project at 1337 school that requires us to re-create some standard C library functions including some additional ones that can be used later to build a library of useful functions that we will use in most of our C projects at 1337 school. </p 

## Why libft?

<p> This project will help us to have a deeper understanding of data structures and algorithms used in C. Also, it will help us to have a better understanding of the standard library functions and how to create our own. </p>

# What's in it?

<p> The project contains the following functions: </p>

```c
int ft_atoi(const char *str);
void *ft_bzero(void *s, size_t n);
void *ft_calloc(size_t count, size_t size);
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
char *ft_itoa(int n);
void *ft_memccpy(void *dest, const void *src, int c, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memset(void *s, int c, size_t n);
void ft_putchar_fd(char c, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
void ft_putstr_fd(char *s, int fd);
char **ft_split(char const *s, char c);
char *ft_strchr(const char *s, int c);
char *ft_strdup(const char *s1);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t ft_strlen(const char *s);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
char *ft_strrchr(const char *s, int c);
char *ft_strtrim(char const *s1, char const *set);
char *ft_substr(char const *s, unsigned int start, size_t len);
int ft_tolower(int c);
int ft_toupper(int c);
```
and the following functions that are not part of the mandatory part of the project:
```c
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstclear(t_list **lst, void (*del)(void*));
void ft_lstdelone(t_list *lst, void (*del)(void*));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstlast(t_list *lst);
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list *ft_lstnew(void *content);
int ft_lstsize(t_list *lst);
```
<p> Just an advice, if you are a 1337 student will need the bonus in other projects, I recommend you to do the bonus part of this project. </p>

## Why do we allocate memory for the return value of ft_substr and ft_strtrim  and ft_strjoin ...?

<p> Because we need to return a pointer to the first character of the string that we created in the function.  </p>
<p> if we don't allocate memory for the return value, the string will be created in the stack and will be destroyed when the function returns. </p>

## Why do we need to cast the return value of malloc?

<p> Because malloc returns a void pointer (void *), and we need to cast it to the type of the pointer that we want to return. </p> 
<p> small note: in C, void * is a generic pointer that can be casted to any pointer type. </p>

<p> it will work without casting the return value of malloc, but it's not a good practice. </p>


## How to use it?

<p> To use the library, clone the repository and compile the files using the Makefile. </p>

<p> you can find some explanations about funcrions in the files of those functions. </p>
