#include "file.h"

void saveFile(List *lst, char *caminho)
{
	Node *p;
	int i;

	arq = fopen(caminho, "w");
	
	p=lst->first;

	do{
		fprintf(arq,"%c ", p->type);
		fprintf(arq,"%d ", p->page);
		fprintf(arq,"%d\n", p->sizeProcess);

		p=p->next;
		
		}while(p != lst->first);
	fclose(arq);
}


List* loadFile(char *caminho)
{
	FILE *arq;
	List *lst;
	Node *p;
	char c;
	int end, page;
	char nome[50];
	int total_memory = 0, process_memory = 0, total_process = 0, inserts = 0;
	
	
	arq = fopen(caminho,"r");
	
	if(arq == NULL)
	{
		printf("Houve um erro ao abrir o arquivo, verifique o nome!\n");
		scanf("%s", nome);
		return loadFile(nome);
	}
	
	lst = (List*)malloc(sizeof(List));
	lst->first = NULL;
	lst->total_memory = 0;
	lst->total_process = 0;
	lst->process_memory = 0;
	
	while(fscanf(arq, "%c %d %d", &c, &page, &end) != EOF)
	{	
		if(inserts % 2 == 1)
		{
			inserts++;
			continue;
		}
		addnode(c,page,end,lst,inserts);
		inserts ++;
		if(c == 'P')
		{
			lst->total_process++;
			lst->process_memory = lst->process_memory+ end-page;
		}
	}
	lst->total_memory = lst->last->sizeProcess;
	
	fclose(arq);
	return lst;
}

void addnode(char type, int page, int end, List *lst, int inserts)
{
	Node *aux = (Node*)malloc(sizeof(Node));
	aux->type = type;
	aux->page = page;
	aux->sizeProcess = end;
	
	if (inserts == 0)
	{
		lst->first = aux;
		lst->last = aux;
		aux->next = aux;
		aux->previous = aux;
	}
	else if(inserts == 2)
	{
		lst->first->previous = aux;
		lst->first->next = aux;
		aux->next = lst->first;
		aux->previous = lst->last;
		lst->last = aux;		
	}
	else
	{
		lst->first->previous = aux;
		lst->last->next = aux;
		aux->next = lst->first;
		aux->previous = lst->last;
		lst->last = aux;
	}
}
