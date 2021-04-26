#include "INTRO.h"
#include "bridge.h"
#include "challenges.h"
#include "memories.h"
#include "hooman.h"

using namespace std;

challenge Challengers({ 290, 520, 10, 0 });
bridge Bridge({ 0, 520, 15, 0 });
hooman Hooman({ 290, 460, 45, 60 });

SDL_Rect _t_box;

void refresh_window();
void move(int length, int speed_unit);

int main(int argc, char* argv[]) {
	// initialation
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return 1;
	if (TTF_Init() < 0) return 1;

	game_window = SDL_CreateWindow("RUN OVER BRIDGE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(game_window, -1, SDL_RENDERER_ACCELERATED);

	font = TTF_OpenFont("SNAP____.TTF", 30);
	if (font == NULL) return 1;
	//
	while (GAME_RUN) {
		//intro goes here
		INTRO();// 
		// 
		GAME_PLAY = true;
		bool exist = false, start_moving = false;
		
		Challengers.init();
		Challengers.show(0);
		Bridge.set_bridge_rect({ Challengers.pos_of_bridge(), 520, 15, 0 });
		Hooman.set_hooman_rect({ 290, 460, 45, 60 });
		Hooman.def_show();
		
		COLOUR = { 200, 100, 50 };

		while (GAME_PLAY) {
		
			while (SDL_PollEvent(&game_event)) {
				if (game_event.type == SDL_QUIT) {
					GAME_RUN = false;
					GAME_PLAY = false;
					break;
				}

				if (game_event.type == SDL_KEYDOWN && !start_moving) {
					exist = true;
				}

				if (game_event.type == SDL_KEYUP && !start_moving) {
					exist = false; 
					start_moving = true;
					refresh_window();
					Bridge.fall_down();
				}

			}//even loop
			if (!GAME_RUN || !GAME_PLAY) break;

			if (exist) {
				Bridge.inc_len();
				Bridge.draw(0);
				SDL_Delay(10);
			}

			if (start_moving) {//move
				if (Bridge.local_pos() > 290) {
					move(Bridge.local_pos(), 20); /// move
					SDL_Delay(50);
				}
				else {
					start_moving = false; 
					if ( Challengers.compare( Bridge.local_pos() ) ) { // CONTINUE
						list[4].input(list[4].get_name(), list[4].get_score() + 1);
						refresh_window();
						Challengers.show(0);
						Challengers.pull();
						Bridge.set_bridge_rect({ Challengers.pos_of_bridge(), 520, 15, 0 });
						Hooman.def_show();

					}
					else { 
						do {
							SDL_Delay(50);
							refresh_window();
							Challengers.show(0);
							Bridge.draw(0);
						} while (Hooman.fall());
						//
						print_memories("a.txt"); 
						list[4].input(list[4].get_name(), 0); SDL_Delay(250);
						displayImage(t_image, "game_lose.png", 0, 0); SDL_Delay(750);
						displayImage(t_image, "game_lose2.png", 0, 0); SDL_Delay(750);
						displayImage(t_image, "game_lose3.png", 0, 0); SDL_Delay(750);
						GAME_PLAY = false;
						INTRO_ON = true;
					}
				}
			}
		}//loop for play game 

	}// game big loop 

	SDL_FreeSurface(home_screen);
	SDL_DestroyWindow(game_window);
	TTF_CloseFont(font);
	TTF_Quit;
	SDL_Quit;
	return 0;
}

void refresh_window() {
	SDL_RenderClear(renderer);
	displayImage(t_image, "background.png", 0, 0); 
	string s = int_to_str(list[4].get_score());
	_t_box = { 1000, 25, 0 , 35 };
	_t_box.w = s.size() * 20;
	displayText(home_screen, text, s, _t_box);
}

void move(int len, int speed_unit) {
	if (speed_unit > len) speed_unit = len % speed_unit;
	else speed_unit += len % speed_unit;

	refresh_window();

	Challengers.show(speed_unit);
	Bridge.draw(speed_unit); 
	Hooman.show();
}
