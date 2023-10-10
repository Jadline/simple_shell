#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void print_myfunc(const char *message);
void prompt_exhibit(void);
void my_command(char *my_string, size_t size);
void invoke_program(char *my_path, char **my_args);
#endif
