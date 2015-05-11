#include "graph.h"

/*Create a visual interface*/
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
	
	writeText(60,5,"Relatório da Memória");
	
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
    
    writeText(5,65,aux);
	
    free(aux);
	
	/*Create Surface and draw second text*/
	
	aux = calloc(1,100);
    strcat(aux, "Memória Ocupada: ");
    strcat(aux,process_memory);
    strcat(aux,"Kb");
    
    writeText(5,120,aux);
    
	free(aux);
	
	/*Create Surface and draw third text*/
    
    aux = calloc(0,100);
    sprintf(aux,"Memória Livre: %.0f",(1-free_percent/300.0)*convert(total_memory));
    strcat(aux,"Kb");
    
    writeText(5,180,aux);
    
    free(aux);
    
	/*Create Surface and draw fourd text*/
    
    aux = calloc(1,100);
    strcat(aux, "Memória Total: ");
    strcat(aux,total_memory);
    strcat(aux,"Kb");
    
    writeText(5,240,aux);
    
    free(aux);
    
    /*Create Surface and draw PERCERNT text*/
    aux = malloc(100);
    sprintf(aux,"%.2f",free_percent/3);
    
    strcat(aux,"% USADA");
    
    writeText(80,380,aux);
    
    free(aux);
    
    /*Close font*/
    TTF_CloseFont(font);
	
	/*Draw de percent bar*/
	drawpercent(free_percent);	
	
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

/*Convert string to int*/
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

/*Write text in the surface*/
void writeText(int posx, int posy, char *text)
{
	s = TTF_RenderUTF8_Blended(font, text, color);
    textura = SDL_CreateTextureFromSurface(renderer, s);
    SDL_FreeSurface(s);
	
	destino.x = posx;
	destino.y = posy;
	destino.w = s->w;
	destino.h = s->h;
	
	SDL_RenderCopy(renderer, textura, NULL, &destino);
	SDL_RenderPresent(renderer);
	
}

/*Draw percent*/
void drawpercent(double percent)
{
	/*Create a rect with de 100 percent free*/
	
	bord = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	drawrect(bord, 50, 310, 310,60, 0,0,0,255);
    
    /*Create a rect with de percent total*/
	
	gtotal = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	drawrect(gtotal, 55, 315, 300,50, 0,0,255,255);
	
	/*Create a rect with de percent no-free*/
	
	gfree = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	drawrect(gfree, 55, 315, percent,50, 255,0,0,255);

}

void drawrect(SDL_Rect *rect, int x, int y, int w, int h, int r, int g, int b, int a)
{
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, rect);
	SDL_RenderPresent(renderer);
}
