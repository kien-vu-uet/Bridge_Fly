#include "challenges.h"
#include "INTRO.h"

using namespace std;

challenge::challenge(SDL_Rect challenger_rect) :Base_Object(challenger_rect) {}//1

void challenge::init() {//2
	for (int i = 0; i < 3; i++) {
		srand(time(0));
		pos[i].w = (rand() % 6 + 10) * 20; 
		pos[i].x = object.x + i * 500 - pos[i].w / 2; 
		pos[i].y = 520;
		pos[i].h = 200;
		img_path[i] = "size_" + int_to_str(pos[i].w / 20) + ".png"; 
		SDL_Delay(100);
	}
}

int challenge::pos_of_bridge() {//3
	return pos[0].x + pos[0].w;
}

void challenge::set_challenge_rect(SDL_Rect challenger_rect) {//4
	object = challenger_rect;
}

void challenge::show(int unit) {//5
	for (int i = 0; i < 3; i++) {
		pos[i].x -= unit;
		if (pos[i].x + pos[i].w > 0 || pos[i].x < 1080) {
			displayImage(t_image, img_path[i], pos[i]);
		}
	}
}

void challenge::pull() {//6
	pos[0] = pos[1]; img_path[0] = img_path[1]; 
	pos[1] = pos[2]; img_path[1] = img_path[2]; 

	srand(time(0));
	if (list[4].get_score() < 5) pos[2].w = (rand() % 6 + 10) * 20; // 15 -> 20
	else if (list[4].get_score() < 10) pos[2].w = (rand() % 11 + 5) * 20; // 10 -> 20
	else if (list[4].get_score() < 20) pos[2].w = (rand() % 15 + 1) * 20; // 5 -> 20
	else pos[2].w = (rand() % 20 + 1) * 20; // 1 -> 20

	pos[2].x = pos[1].x + 500 - pos[2].w / 2 + pos[1].w / 2;  
	pos[2].y = 520;
	pos[2].h = 200;
	img_path[2] = "size_" + int_to_str(pos[2].w / 20) + ".png"; 
}

bool challenge::compare(int p) {
	if (p < pos[1].x || p > pos[1].x + pos[1].w) { //pos[1] is 2nd challenger
		return false;
	}
	else return true;
}