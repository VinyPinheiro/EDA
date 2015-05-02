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
	struct node *last;
};
typedef struct list List;

void startList(List *li){
	int sizeMemory;
	
	scanf("%d", &sizeMemory);

    li->first=(Node *)malloc(sizeof(Node));
    li->first->type='H';
    li->first->page=0;
    li->first->sizeProcess=sizeMemory;

	li->last=li->first;
}

void insert(List *li, int sizeNewProcess){
	Node *p, *aux;

	p=li->first;

	while(p->type!='H' || p->sizeProcess-p->page<sizeNewProcess){
		if(p->next==NULL){
			//Implementar depois
			printf("Sem memória disponível, deseja reorganizar os processos de memória?");
			return;
		}
		p=p->next;
	}

	aux=(Node *)malloc(sizeof(Node));
	aux->type='P';
	aux->page=p->page;
	aux->sizeProcess=p->page+sizeNewProcess;

	p->page=aux->sizeProcess;
	aux->next=p;

	if(p->previous==NULL){
		p->previous=aux;

		li->first=aux;

		return;
	}

	p->previous->next=aux;
	aux->previous=p->previous;

	aux->next=p;
	p->previous=aux;

	p=li->first;

}

void delete(List *li){

}

void showProcesses(List *li){
	Node *p;

	p=li->first;

	while(p!=NULL){
		printf("%c\n", p->type);
		printf("%d\n", p->page);
		printf("%d\n\n", p->sizeProcess);

		p=p->next;
	}
}

int main(){
	List *li;
	int sizeProcess=1;

	li=(List *)malloc(sizeof(List));

	startList(li);

	while(sizeProcess){
		printf("Digite o tamanho do novo processo: ");
		scanf("%d", &sizeProcess);
		insert(li, sizeProcess);

		showProcesses(li);
	}


	/*printf("%c\n", li->first->type);
	printf("%d\n", li->first->page);
	printf("%d\n\n", li->first->sizeProcess);

	printf("%c\n", li->first->next->type);
    printf("%d\n", li->first->next->page);
    printf("%d\n", li->first->next->sizeProcess);*/

	return 0;
}
