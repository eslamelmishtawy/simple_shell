#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
char *line_read(void);
char **tokenizer(char *str);
void free_list(char **list);
#endif
