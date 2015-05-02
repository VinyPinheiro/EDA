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
}

void insert(List *li, int sizeProcess){
	Node *p;

	if(li->last==NULL){
		p=(Node *)malloc(sizeof(Node));
		p->type='P';
		p->page=0;
		p->sizeProcess=sizeProcess;
		p->previous=NULL;

		p->next=(Node *)malloc(sizeof(Node));
		p->next=li->first;
		p->next->previous=(Node *)malloc(sizeof(Node));
		p->next->page=p->sizeProcess;
		p->next->sizeProcess=(li->first->sizeProcess)-sizeProcess;
		p->next->next=NULL;
		p->next->previous=p;

		li->first=p;

		li->last=(Node *)malloc(sizeof(Node));
		li->last=p->next;

		return;
	}

	p=li->first;	
	
}

void delete(List *li){

}

int main(){
	List *li;
	int sizeProcess;

	li=(List *)malloc(sizeof(List));

	startList(li);

	printf("Digite o tamanho do novo processo ");
	scanf("%d", &sizeProcess);

	insert(li, sizeProcess);

	printf("%c\n", li->first->type);
	printf("%d\n", li->first->page);
	printf("%d\n\n", li->first->sizeProcess);

	printf("%c\n", li->first->next->type);
    printf("%d\n", li->first->next->page);
    printf("%d\n", li->first->next->sizeProcess);

	return 0;
}
