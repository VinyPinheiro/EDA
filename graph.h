#ifndef GRAPH_H
#define GRAPH_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>	
#include <stdlib.h>
#include <math.h>

void mountScreen(const char* process_number,const char* process_memory,const char* total_memory);
int convert(const char *x);

SDL_Window* window; 
SDL_Renderer *renderer;
SDL_Texture *textura;
SDL_Rect destino;
TTF_Font *font;
SDL_Color color;
SDL_Surface *s;
SDL_Event event;
SDL_Rect* gtotal;
SDL_Rect* gfree;
SDL_Rect* bord;
int quit, try;


#endif
