#include "graph.h"

void mountScreen(const char* process_number,const char* free_memory,const char* total_memory)
{
	char *aux = malloc(100);
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
	SDL_CreateWindowAndRenderer(400, 300, 0, &window, &renderer);
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
	
	aux = malloc(100);
    strcat(aux, "Memória Livre: ");
    strcat(aux,free_memory);
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
    
    aux = malloc(100);
    strcat(aux, "Memória Total: ");
    strcat(aux,total_memory);
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
    
	quit = 0;
    
    /*Close font*/
    TTF_CloseFont(font);
	
	
	while (!quit)
	{
		if(SDL_PollEvent( &event ) != 0)
			if(event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
				quit = !quit;
	}
    TTF_Quit();
	SDL_Quit();
}

int stringtonum()
{
	
}
