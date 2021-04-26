#include "data.h"

SDL_Window* game_window = NULL;

SDL_Renderer* renderer = NULL;

SDL_Color COLOUR = { 255, 200, 0 };

SDL_Event game_event;
//use for display image
SDL_Surface* home_screen = NULL;
SDL_Texture* t_image = NULL;
//use for display text
SDL_Texture* text = NULL;
TTF_Font* font = NULL;

int WIDTH = 1080, HEIGHT = 720;

bool GAME_RUN = true, GAME_PLAY = true, INTRO_ON = true;

int str_to_int(string str_score) {
	int res = 0;
	int len = str_score.size();
	for (int i = 0; i < len; i++) {
		res = res * 10 + (str_score[i] - '0');
	}
	return res;
}

string int_to_str(int _score) {
	string res = "";
	while (_score != 0) {
		char ch = '0' + (_score % 10);
		_score = _score / 10;
		res = ch + res;
	}
	return res;
}
