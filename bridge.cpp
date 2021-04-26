#include "bridge.h"

using namespace std;

bridge::bridge(SDL_Rect _bridge) :Base_Object(_bridge) {}

void bridge::fall_down() {
	set_bridge_rect({ object.x, object.y, -object.h, object.w });
	draw(0);
}

void bridge::draw(int unit) {
	SDL_SetRenderDrawColor(renderer, 150, 150, 150, 50); //swap length and thickness
	object.x -= unit;//move some units by x
	SDL_RenderDrawRect(renderer, &object);
	SDL_RenderFillRect(renderer, &object);
	SDL_RenderPresent(renderer);
}


void bridge::set_bridge_rect(SDL_Rect B_rect) {
	object = B_rect;
}

int bridge::local_pos() {
	return object.x + object.w;
}

void bridge::inc_len() {
	if (object.h > -800) object.h -= 5;
}