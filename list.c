#include "list.h"
#include "list.h"

/*Start the List*/
void startList(List *li){
	int sizeMemory;

	printf("Memória total: ");
	scanf("%d", &sizeMemory);

    li->first=(Node *)malloc(sizeof(Node));
    li->first->type='H';
    li->first->page=0;
    li->first->sizeProcess=sizeMemory;

	li->last=(Node *)malloc(sizeof(Node));
    li->last->type='H';
    li->last->page=0;
    li->last->sizeProcess=sizeMemory;

	li->total_memory = sizeMemory;
    li->process_memory = 0;
    li->total_process = 0;

	li->first->previous=li->last;
	li->last->next=li->first;
}

/*Insert a node in the list*/
void insert(List *li, int sizeNewProcess){
	Node *p, *aux;

	/*Verify if there is just one node in the list*/
	if(li->first->page==li->last->page){
		if(sizeNewProcess>li->total_memory){
			printf("Não há memória suficiente para adicionar esse processo\n");
			return;
		}

		if(li->first==li->last) 
			li->last=(Node *)malloc(sizeof(Node));
		
		li->first->type='P';
		li->first->page=0;
		li->first->sizeProcess=sizeNewProcess;
	
		li->last->type='H';
		li->last->page=sizeNewProcess;
		li->last->sizeProcess=li->total_memory;

		li->first->next=li->last;
		li->first->previous=li->last;

		li->last->previous=li->first;
		li->last->next=li->first;
		
		li->total_process++;
	 	li->process_memory += sizeNewProcess;
	 	
	 	return;
	}
	p=li->first;
	
	while(p->type !='H' || p->sizeProcess-p->page<sizeNewProcess){
		if(p->next==li->first){
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
	
	p->previous->next=aux;
	aux->previous=p->previous;

	aux->next=p;
	p->previous=aux;

	if( (li->last->page - li->last->sizeProcess)==0 ){
		aux=li->last;

		li->last->previous->next=li->last->next;
		li->first->previous=li->last->previous;

		li->last=li->last->previous;

		free(aux);
	}
	
	li->total_process++;
	li->process_memory += sizeNewProcess;

}

/*Remove a process from the list*/
void closeProcess(List *li, int page){
	int aux;
	Node *p = malloc(sizeof(Node)), *auxFree;

	p=li->first;

	while(p->page!=page){
		p=p->next;
		if(p == li->first){
			printf("Página inválida\n");
			return;
		}
	}
	
	if(p->type == 'H'){
		printf("Página inválida\n");
		return;
	}
		
	li->total_process--;
	li->process_memory -= (p->sizeProcess - p->page);
	p->type='H';

	if(p->previous->type=='H'){
		if(p==li->first){
			auxFree=li->first;
			aux=p->sizeProcess;
			while(p->next!=li->first){
				p->page-=aux;
				p->sizeProcess-=aux;
				p=p->next;
			}
			p->page-=aux;
			li->first=li->first->next;
			li->first->previous=li->last;
			li->last->next=li->first;
			free(auxFree);
			return;
		}else{
			auxFree=p;
			p->previous->sizeProcess=p->sizeProcess;
			p->previous->next=p->next;
			p->next->previous=p->previous;
			free(auxFree);

			p=p->previous;
		}
	}

	if(p->next->type=='H'){
		if(p==li->last){
			p=li->first;
			auxFree=li->first;
			aux=p->sizeProcess;
			while(p->next!=li->first){
				p->page-=aux;
				p->sizeProcess-=aux;
				p=p->next;
			}
			p->page-=aux;
			li->first=li->first->next;
			li->first->previous=li->last;
			li->last->next=li->first;
			free(auxFree);
		}else{
			auxFree=p;
			p->next->page=p->page;
			p->next->previous=p->previous;
			p->previous->next=p->next;
			free(auxFree);
		}
	}

}

/*Show all processes*/
void showProcesses(List *li){
	Node *p;
	int i;

	p=li->first;
	printf("Tipo\tPonto de Inicio\tTamanho\n");

	while(1){
		printf("%c\t", p->type);
		printf("%d\t\t", p->page);
		printf("%d\n", p->sizeProcess-p->page);

		p=p->next;
		
		if(p==li->first) break;
	}
}

/*Rearranges the process so that it has no free memory fragments between processes*/
void organizeProcesses(List *li){
	int sizeProcess;
	Node *p, *auxFree, *aux;

	if(li->total_process == 0)
		return;
	
	p=li->first;

	while(p->next!=li->first){
		aux=p;

		if(p->type=='H'){
			sizeProcess=p->sizeProcess-p->page;
			auxFree=p;
			p->previous->next=p->next;
			p->next->previous=p->previous;
			p=p->next;
			aux=p;
			free(auxFree);
			while(p->next!=li->first){
				p->page-=sizeProcess;
				p->sizeProcess-=sizeProcess;
				p=p->next;
			}
			li->last->page-=sizeProcess;
		}

		p=aux;	
		p=p->next;
	}

}

