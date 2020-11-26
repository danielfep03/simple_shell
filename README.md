# SUPER SHELL
This project develop a **UNIX command line interpreter** base in the _sh_ shell.

It consists of a simple shell designed on C language, to be used with simple mode typing commands on the prompt or using "non-interactive" mode.


# Quick start

1- clone the repository to your local directory

> `$ git clone https://github.com/danielfep03/simple_shell`

2- Start up simple_shell, compile using

>`$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

3- start the shell

>`$ ./hsh`

## FEATURES

Build-in Commands

-   exit
-   env

Example of use feature (exit)

```
$ ./hsh
hsh_shell$ exit 98
$ echo $?
98
```

### Features

-   End of File (Ctrl+d) : Exit Shell
-   Accepts arguments for functions
-   Check the Path for executable file

### Interactive vs. Non-Interactive Mode

You can use the shell in both interactive and non-interactive mode. The examples above are done in interactive mode. You can tell because the shell runs continuously, awaiting and executing commands, until you explicitly  `exit`.

Non-interactive mode, however, is when you indirectly feed commands into the executable  `hsh`  file from outside the shell. For example, we can list files by indirectly piping  `ls`  into  `hsh`  using  `echo`:

```
$ echo "ls" | ./hsh
a.out  shell.c  simple_shell	stuff.txt
```
## Environment Information
|   Feature 	|  Version  	|
|:-:	|:-:	|
|**Language**	|   C	|
|**Operating System** 	|   Ubuntu 14.04 LTS	|
|**Compiler**	| `gcc 4.8.4`|
|**Style Guidelines**	|   	[`Betty`](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl")|

## AUTHOR
##### DANIEL FELIPE AMADO
