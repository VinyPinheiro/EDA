#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

struct node{
	char type;
	int page;
	int sizeProcess;
	struct node *next;
	struct node *previous;
};
typedef struct node Node;

struct list{
	struct node *first;
	float total_memory;
	float process_memory;
	int total_process;
	struct node *last;
};
typedef struct list List;

void startList(List *li);
void insert(List *li, int sizeNewProcess);
void closeProcess(List *li, int page);
void showProcesses(List *li);
void organizeProcesses(List *li);

#endif
