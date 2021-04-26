#include "base_class.h"

using namespace std;

SDL_Rect Base_Object::get_rect() {
	return object;
}

Base_Object::Base_Object(SDL_Rect _object) {
	object = _object;
}

void Base_Object::displayImage(SDL_Texture* t_image, string path, SDL_Rect rect) {
	t_image = IMG_LoadTexture(renderer, path.c_str());
	SDL_QueryTexture(t_image, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(renderer, t_image, NULL, &rect);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(t_image);
}
