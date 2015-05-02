#ifndef GRAPH_H
#define GRAPH_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>	
#include <stdlib.h>

void mountScreen(const char* process_number,const char* free_memory,const char* total_memory);

SDL_Window* window; 
SDL_Renderer *renderer;
SDL_Texture *textura;
SDL_Rect destino;
TTF_Font *font;
SDL_Color color;
SDL_Surface *s;
SDL_Event event;
int quit, try;


#endif
