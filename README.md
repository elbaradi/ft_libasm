Note: _This was my seventh 42 project. The code is from May 2021. This README was written by the amazing [Qing Li](https://github.com/qingqingqingli), it was copied and modified with her permission; it perfectly describes the project._

[![Logo](https://github.com/qingqingqingli/readme_images/blob/master/codam_logo_1.png)](https://github.com/elbaradi/ft_libasm)

# ft_libasm

***The aim of this project is to get familiar with assembly language.***

## Technical considerations

- The project is written in `64 bits` ASM, compiled with [NASM](https://www.nasm.us/)

- It follows the `Intel` syntax

- The following functions are rewritten in assembly:
	- `ft_strlen`: calculate the length of a string
	- `ft_strcpy`: copy a string
	- `ft_strcmp`: compare two strings
	- `ft_write`: write to a file descriptor
	- `ft_read`: read from a file descriptor
	- `ft_strdup`: duplicate a string

- `Errors` during syscalls need to be checked and `Errno` to be set properly


## How to test


> Run the following commands to test (MacOS):

```shell
$ git clone https://github.com/elbaradi/ft_libasm.git
$ cd ft_libasm
$ brew install nasm
$ nasm -f macho64 ft_strcmp.s ft_strcpy.s ft_strlen.s ft_write.s
$ gcc main.c ft_strlen.o ft_strcpy.o ft_strcmp.o ft_write.o
$ ./a.out
```
