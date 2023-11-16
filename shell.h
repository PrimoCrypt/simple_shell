#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>



/* toem_atoi.c */
int is_shell_interactive(info_t *);
int is_delimeter(char, char *);
int is_alpha(int);
int string_to_integer(char *);

