#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void saveFile(List *lst, char *caminho);
List *loadFile(char *caminho);
void addnode(char type, int page, int end, List *lst, int inserts);

FILE *arq;

#endif
