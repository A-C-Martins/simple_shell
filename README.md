# **0x16. C - Simple Shell**

## **Consept**
For this project, we expect you to look at these concepts: <br>
    **.** [Everything you need to know to start coding your own shell](https://intranet.alxswe.com/concepts/64) <br>
    **.** [Approaching a Project](https://intranet.alxswe.com/concepts/350) <br>
    **.** [All about Team Projects + Pairings + FAQ (A must read)](https://intranet.alxswe.com/concepts/100037) <br>
    **.** [Struggling with the sandbox? Try this: Using Docker & WSL on your local host](https://intranet.alxswe.com/concepts/100039) <br>


 # **Background Context**
   Write a simple UNIX command interpreter.

![shell](https://github.com/A-C-Martins/simple_shell/assets/125482540/2ad19c7d-dd69-4dd4-8345-661e865daa57)

# Learning Objectives
At the end of this project, you are expected to be able to [explain to anyone](https://intranet.alxswe.com/rltoken/9LNz86CtOTos9oL3zxIO3A), **without the help of Google:**

## General
**.** Who designed and implemented the original Unix operating system <br>
**.** Who wrote the first version of the UNIX shell <br>
**.** Who invented the B programming language (the direct predecessor to the C programming language) <br>
**.** Who is Ken Thompson <br>
**.** How does a shell work <br>
**.** What is a pid and a ppid <br>
**.** How to manipulate the environment of the current process <br>
**.** What is the difference between a function and a system call <br>
**.** How to create processes <br>
**.** What are the three prototypes of ``main`` <br>
**.** How does the shell use the ``PATH`` to find the programs <br>
**.** How to execute another program with the ``execve`` system call <br>
**.** How to suspend the execution of a process until one of its children terminates <br>
**.** What is ``EOF`` / “end-of-file”? <br>

# Requirements
## General

1. Allowed editors: ``vi``, ``vim``, ``emacs`` <br>
2. All your files will be compiled on Ubuntu 20.04 LTS using ``gcc``, using the options ``-Wall -Werror -Wextra -pedantic -std=gnu89`` <br>
3. All your files should end with a new line <br>
4. A ``README.md`` file, at the root of the folder of the project is mandatory <br>
5. Your code should use the ``Betty`` style. It will be checked using [betty-style.pl](https://github.com/alx-tools/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/alx-tools/Betty/blob/master/betty-doc.pl) <br>
6. Your shell should not have any memory leaks <br>
7. No more than 5 functions per file <br>
8. All your header files should be include guarded <br>
9. Use system calls only when you need to ([why?](https://intranet.alxswe.com/rltoken/EU7B1PTSy14INnZEShpobQ)) <br>
10. Write a ``README`` with the description of your project <br>
11. You should have an ``AUTHORS`` file at the root of your repository, listing all individuals having contributed content to the repository. Format, see [Docker](https://intranet.alxswe.com/rltoken/UL8J3kgl7HBK_Z9iBL3JFg) <br>

# More Info
## Output
**.** Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output. <br>
**.** The only difference is when you print an error, the name of the program must be equivalent to your ``argv[0]`` (See below) <br>

Example of error with ``sh``:
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
Same error with your program ``hsh``:
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

## ***List of allowed functions and system calls***
``access`` (man 2 access)
``chdir`` (man 2 chdir)
``close`` (man 2 close)
``closedir`` (man 3 closedir)
``execve`` (man 2 execve)
``exit`` (man 3 exit)
``_exit`` (man 2 _exit)
``fflush`` (man 3 fflush)
``fork`` (man 2 fork)
``free`` (man 3 free)
``getcwd`` (man 3 getcwd)
``getline`` (man 3 getline)
``getpid`` (man 2 getpid)
``isatty`` (man 3 isatty)
``kill`` (man 2 kill)
``malloc`` (man 3 malloc)
``open`` (man 2 open)
``opendir`` (man 3 opendir)
``perror`` (man 3 perror)
``read`` (man 2 read)
``readdir`` (man 3 readdir)
``signal`` (man 2 signal)
``stat`` (__xstat) (man 2 stat)
``lstat`` (__lxstat) (man 2 lstat)
``fstat`` (__fxstat) (man 2 fstat)
``strtok`` (man 3 strtok)
``wait`` (man 2 wait)
``waitpid`` (man 2 waitpid)
``wait3`` (man 2 wait3)
``wait4`` (man 2 wait4)
``write`` (man 2 write)

## Compilation
Your shell will be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Testing
Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
