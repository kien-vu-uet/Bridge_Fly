#ifndef base_class_
	#define base_class_

#include "data.h"

using namespace std;

class Base_Object {
public:
	Base_Object(SDL_Rect _object);
	void displayImage(SDL_Texture* t_image, string path, SDL_Rect rect);
	SDL_Rect get_rect();
protected:
	SDL_Rect object;
};

#endif