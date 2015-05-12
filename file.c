#include "file.h"

void saveFile(List *lst, char *caminho)
{
	Node *p;
	int i;

	arq = fopen(caminho, "w");
	
	p=lst->first;

	while(1){
		fprintf(arq,"%c ", p->type);
		fprintf(arq,"%d ", p->page);
		fprintf(arq,"%d\n", p->sizeProcess);

		p=p->next;
		
		if(p==lst->first) break;
	}
	fclose(arq);
}


List* loadFile(char *caminho)
{
	List *lst;
	char c;
	int size;
	
	startList(lst);
	
	
}
