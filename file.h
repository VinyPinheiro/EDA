#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void saveFile(List *lst, char *caminho);
List *loadFile(char *caminho);

FILE *arq;

#endif
