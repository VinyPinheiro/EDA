#include "graph.h"

void mountScreen(const char* process_number,const char* process_memory,const char* total_memory)
{
	char *aux;
	double free_percent = (convert(process_memory)*1.0/convert(total_memory)*300);

	try = SDL_Init(SDL_INIT_VIDEO);
	
	if(try != 0)
	{
		return;
	}

    try = TTF_Init();

    if (try != 0)
    {
        return;
    }
	SDL_CreateWindowAndRenderer(400, 450, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	
	/*Define font type*/
	font = TTF_OpenFont("AjarSans-Regular.ttf", 30);
	
	/*Define color font*/
    color.r = 0;
	color.g = 0;
	color.b = 255;
    color.a = 255;
    
    
    /*Create Surface and draw title text*/
    
	TTF_SetFontStyle(font, TTF_STYLE_BOLD);
	TTF_SetFontStyle(font, TTF_STYLE_ITALIC);
	TTF_SetFontStyle(font, TTF_STYLE_UNDERLINE);
    s = TTF_RenderUTF8_Blended(font, "Relatório da Memória", color);
    textura = SDL_CreateTextureFromSurface(renderer, s);
    SDL_FreeSurface(s);
	
	destino.x = 60;
	destino.y = 5;
	destino.w = s->w;
	destino.h = s->h;
	
	SDL_RenderCopy(renderer, textura, NULL, &destino);
	SDL_RenderPresent(renderer);
	
	
	/*Define color font*/
    color.r = 0;
	color.g = 0;
	color.b = 0;
    color.a = 255;
	
    /*Create Surface and draw first text*/
    aux = calloc(0,100);
    strcat(aux, "Total de processos: ");
    strcat(aux,process_number);
	TTF_SetFontStyle(font, TTF_STYLE_NORMAL);
    s = TTF_RenderUTF8_Blended(font, aux, color);
    textura = SDL_CreateTextureFromSurface(renderer, s);
    SDL_FreeSurface(s);
	
	destino.x = 5;
	destino.y = 65;
	destino.w = s->w;
	destino.h = s->h;
	
	SDL_RenderCopy(renderer, textura, NULL, &destino);
	SDL_RenderPresent(renderer);
	free(aux);
	
	/*Create Surface and draw second text*/
	
	aux = calloc(1,100);
    strcat(aux, "Memória Ocupada: ");
    strcat(aux,process_memory);
    strcat(aux,"Kb");
    
    s = TTF_RenderUTF8_Blended(font, aux, color);
    textura = SDL_CreateTextureFromSurface(renderer, s);
    SDL_FreeSurface(s);
	
	destino.x = 5;
	destino.y = 120;
	destino.w = s->w;
	destino.h = s->h;
	
	SDL_RenderCopy(renderer, textura, NULL, &destino);
	SDL_RenderPresent(renderer);
	free(aux);
	
	/*Create Surface and draw third text*/
    
    aux = calloc(0,100);
    sprintf(aux,"Memória Livre: %.0f",(1-free_percent/300.0)*convert(total_memory));
    strcat(aux,"Kb");
    
    s = TTF_RenderUTF8_Blended(font, aux, color);
    textura = SDL_CreateTextureFromSurface(renderer, s);
    SDL_FreeSurface(s);
	
	destino.x = 5;
	destino.y = 180;
	destino.w = s->w;
	destino.h = s->h;
	
	SDL_RenderCopy(renderer, textura, NULL, &destino);
	SDL_RenderPresent(renderer);
    free(aux);
    
	/*Create Surface and draw fourd text*/
    
    aux = calloc(1,100);
    strcat(aux, "Memória Total: ");
    strcat(aux,total_memory);
    strcat(aux,"Kb");
    
    s = TTF_RenderUTF8_Blended(font, aux, color);
    textura = SDL_CreateTextureFromSurface(renderer, s);
    SDL_FreeSurface(s);
	
	destino.x = 5;
	destino.y = 240;
	destino.w = s->w;
	destino.h = s->h;
	
	SDL_RenderCopy(renderer, textura, NULL, &destino);
	SDL_RenderPresent(renderer);
    free(aux);
    
    /*Create Surface and draw PERCERNT text*/
    aux = malloc(100);
    sprintf(aux,"%.2f",free_percent/3);
    
    strcat(aux,"% USADA");
    
    s = TTF_RenderUTF8_Blended(font, aux, color);
    textura = SDL_CreateTextureFromSurface(renderer, s);
    SDL_FreeSurface(s);
	
	destino.x = 80;
	destino.y = 380;
	destino.w = s->w;
	destino.h = s->h;
	
	SDL_RenderCopy(renderer, textura, NULL, &destino);
	SDL_RenderPresent(renderer);
    free(aux);
    
    /*Close font*/
    TTF_CloseFont(font);
	
	/*Create a rect with de 100 percent free*/
	
	bord = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	bord->x = 50;
	bord->y = 310;
	bord->w = 310;
	bord->h = 60;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, bord);
	SDL_RenderPresent(renderer);
    
    /*Create a rect with de percent total*/
	
	gtotal = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	gtotal->x = 55;
	gtotal->y = 315;
	gtotal->w = 300;
	gtotal->h = 50;
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, gtotal);
	SDL_RenderPresent(renderer);
	
	/*Create a rect with de percent no-free*/
	
	gfree = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	gfree->x = 55;
	gfree->y = 315;
	gfree->w = free_percent;
	gfree->h = 50;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, gfree);
	SDL_RenderPresent(renderer);
    
	quit = 0;
	while (!quit)
	{
		
		if(SDL_PollEvent( &event ) != 0)
			if(event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
				quit = !quit;
	}
    TTF_Quit();
	SDL_Quit();
}

int convert(const char *x)
{
	int aux=0;
	unsigned int i, j;
	for (i = 0, j = strlen(x)-1; i < strlen(x) ; i++, j--)
	{
		aux += (x[j]-'0') * pow(10,i);
	}
	return aux;
}
