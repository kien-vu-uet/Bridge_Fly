#ifndef game_data_
	#define game_date_
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL_ttf.h>
#include <Windows.h>
#include <cstdlib>

using namespace std;

extern SDL_Window* game_window;

extern SDL_Renderer* renderer;

extern SDL_Color COLOUR;

extern SDL_Event game_event;
//use for display image
extern SDL_Surface* home_screen;
extern SDL_Texture* t_image;
//use for display text
extern SDL_Texture* text;
extern TTF_Font* font;

extern int WIDTH, HEIGHT;

extern bool GAME_RUN, GAME_PLAY, INTRO_ON;

int str_to_int(string str_score);
string int_to_str(int _score);


// class

#endif // !1

