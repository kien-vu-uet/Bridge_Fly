#include "INTRO.h"

using namespace std;

vector <ranked_list> list;

SDL_Rect ps_box1, ps_box2, t_box;

void INTRO() {
	if (!INTRO_ON) return;
	//animation home -> game_play
	for (int i = -1080; i <= 0; i += 120) {
		SDL_RenderClear(renderer);
		displayImage(t_image, "home1.png", i, 0);
	}
	//
	read_file("a.txt"); COLOUR = { 0, 255, 0 };
	int _x = 190 - (list[4].get_name().size() * 8), _w = list[4].get_name().size() * 16;
	t_box = { _x, 215, _w, 35 };
	displayText(home_screen, text, list[4].get_name(), t_box);
	//
	COLOUR = { 255, 100, 0 };
	for (int i = 0; i < 4; i++) {
		int _y = 340 + i * 70, _w_1 = list[i].get_name().size() * 16, _w_2 = int_to_str(list[i].get_score()).size() * 16;
		ps_box1 = { 675, _y, _w_1, 35 };
		ps_box2 = { 975, _y, _w_2, 35 };
		//
		displayText(home_screen, text, list[i].get_name(), ps_box1);
		displayText(home_screen, text, int_to_str(list[i].get_score()), ps_box2);
	}
	//
	while (INTRO_ON) {
		//
		int _x = 190 - (list[4].get_name().size() * 8), _w = list[4].get_name().size() * 16;
		t_box = { _x, 215, _w, 35 };
		//
		while (SDL_PollEvent(&game_event)) {

			int mouse_x = game_event.motion.x, mouse_y = game_event.motion.y;

			if (game_event.type == SDL_QUIT) {
				INTRO_ON = false;
				GAME_RUN = false;
				GAME_PLAY = false;
				return;
			}
			if (game_event.type == SDL_MOUSEBUTTONDOWN) {

				if (mouse_x >= 400 && mouse_x <= 500 && mouse_y >= 180 && mouse_y <= 280 && list[4].get_name().size() >= 5) {
					SDL_RenderClear(renderer);
					displayImage(t_image, "home2.png", 0, 0);
					displayImage(t_image, "home1.png", 0, 0);
					displayText(home_screen, text, list[4].get_name(), t_box);
					INTRO_ON = false;
				}

			}

			if (game_event.type == SDL_KEYDOWN) {
				int keycode = game_event.key.keysym.sym;

				list[4].change_name(keycode);

				//set position
				_x = 190 - (list[4].get_name().size() * 8);
				_w = list[4].get_name().size() * 16;
				t_box = { _x, 215, _w, 35 };
				//set colour
				if (list[4].get_name().size() >= 5) COLOUR = { 0, 255, 0 };
				else COLOUR = { 255, 0, 0 };
				//display
				displayImage(t_image, "fill_name_rect.png", 50, 210);
				displayText(home_screen, text, list[4].get_name(), t_box);
			}

		} // event loop

	} // intro loop
	//animation game_play -> home
	for (int i = 1080; i >= 0; i -= 120) {
		SDL_RenderClear(renderer);
		displayImage(t_image, "background.png", i, 0);
	}
}

void displayText(SDL_Surface* t_surface, SDL_Texture* text_box, string text, SDL_Rect t_box) {
	t_surface = TTF_RenderText_Solid(font, text.c_str(), COLOUR);
	text_box = SDL_CreateTextureFromSurface(renderer, t_surface);

	SDL_RenderCopy(renderer, text_box, NULL, &t_box);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(text_box);
	SDL_FreeSurface(t_surface);
}

void displayImage(SDL_Texture* t_image, string path, int x, int y) {
	t_image = IMG_LoadTexture(renderer, path.c_str());
	SDL_QueryTexture(t_image, NULL, NULL, &WIDTH, &HEIGHT);
	SDL_Rect pos = { x, y, WIDTH, HEIGHT };
	SDL_RenderCopy(renderer, t_image, NULL, &pos);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(t_image);
}
