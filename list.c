#include "list.h"
#include "list.h"

/*Inicia a Lista*/
void startList(List *li){
	int sizeMemory;

	printf("Memória total: ");
	scanf("%d", &sizeMemory);

    li->first=(Node *)malloc(sizeof(Node));
    li->first->type='H';
    li->first->page=0;
    li->first->sizeProcess=sizeMemory;
    li->total_memory = sizeMemory;
    li->process_memory = 0;
    li->total_process = 0;

	li->last=li->first;
}

/*Insere um nó na lista*/
void insert(List *li, int sizeNewProcess){
	Node *p, *aux;

	p=li->first;

	while(p->type !='H' || p->sizeProcess-p->page<sizeNewProcess){
		if(p->next==NULL){
			/*Implementar depois*/
			printf("%c", (char)7);
			printf("\nSem memória disponível. Tente novamente após reorganizar os processos de memória\n");
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

void closeprocess(List *li, int page){
	Node *p = malloc(sizeof(Node));

	p=li->first;

	while(p->page!=page){
		p=p->next;
	}
	
	p->type='H';
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

void organizeProcesses(List *li){
	int sum=0, sizeProcess;
	Node *p;

	p=li->first;

	while(p->next!=NULL){

		if(p->type=='H'){
			/*Verificar quando o p->previous for NULL*/

			if(p->previous==NULL){
				p=p->next;
				p->sizeProcess=p->sizeProcess - p->page;
				p->page=0;
				p->previous=NULL;

				li->first=p;

				p=p->next;

				continue;
			}
			
			sizeProcess=p->next->sizeProcess - p->next->page;
	
			p->next->page=p->previous->sizeProcess;
			p->next->sizeProcess=p->next->page + sizeProcess;

			p->previous->next=p->next;
			p->next->previous=p->previous;
		}
		
		p=p->next;
	}

	p->type='H';
	p->page=p->previous->sizeProcess;
	p->next=NULL;
	
}

