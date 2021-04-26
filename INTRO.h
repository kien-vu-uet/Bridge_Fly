#ifndef INTRO_
	#define INTRO_
#include "data.h"
#include "memories.h"

class ranked_list {
	private:
		string name = "";
		int score = 0;

	public:
		string get_name() {
			return name;
		}

		int get_score() {
			return score;
		}

		void change_name(int keycode) {
			if (keycode == SDLK_SPACE && name.size() < 16) {
				name += ' ';
			}
			else if (keycode >= SDLK_0 && keycode <= SDLK_9 && name.size() < 16) {
				char ch = '0' + (keycode - SDLK_0);
				name += ch;
			}
			else if (keycode >= SDLK_a && keycode <= SDLK_z && name.size() < 16) {
				char ch = 'a' + (keycode - SDLK_a);
				name += ch;
			}
			else if (keycode == SDLK_BACKSPACE && name.size() > 0) {
				name = name.erase(name.size() - 1, 1);
			}
		}

		void input(string _name, int _score) {
			name = _name;
			score = _score;
		}
};

void displayImage(SDL_Texture* t_image, string path, int x, int y);
void displayText(SDL_Surface* t_surface, SDL_Texture* text_box, string text, SDL_Rect t_box);
void INTRO();

extern vector<ranked_list> list;

#endif