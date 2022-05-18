# C - Simple Shell

## Description

This is a simple UNIX command interpreter written in C.

## Compilation

The shell is be compiled this way:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Usage

The shell program can run in either interactive or non-interactive mode.

#### Interactive Mode

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

#### Non-Interactive Mode

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

#### Included Built-Ins

The simple shell has support for the following built-in commands:

| Command                   | Definition                                    |
| ---------------           | --------------------------------------------- |
| exit [status]             | Exits the shell with a given status           |
| env                       | Prints the current environment                |
| setenv [VARIABLE] [VALUE] | Sets an environment variable to a given value |
| unsetenv [VARIABLE]       | Removes an environment variable               |

### Examples

```
$ /bin/ls
AUTHORS  README.md  built.c  env_list.c  hsh  lists.c  main.c  main.h  shell.c	strings.c  tests  to-do  which.c
$ ls
AUTHORS  README.md  built.c  env_list.c  hsh  lists.c  main.c  main.h  shell.c	strings.c  tests  to-do  which.c
$ ^C
$ hello world
./hsh: 1: hello: not found
$ exit
```

### Credits

Written by [Martin Mulwa](https://github.com/martinmulwa) and [Festus Gichohi](https://github.com/fesgic).
