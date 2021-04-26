#include "hooman.h"

using namespace std;

hooman::hooman(SDL_Rect _hooman) :Base_Object(_hooman) {};

void hooman::def_show() {
	displayImage(t_image, "pic_0.png", object);
}

void hooman::show() {
	switch (index % 4 + 1) {
	case (1):
		displayImage(t_image, "pic_1.png", object);
		break;
	case (2):
		displayImage(t_image, "pic_2.png", object);
		break;
	case (3):
		displayImage(t_image, "pic_3.png", object);
		break;
	case (4):
		displayImage(t_image, "pic_4.png", object); index = -1;
		break;
	}
	index++;
}

bool hooman::fall() {
	object.y += 10;
	show();
	if (object.y + object.h > 700) return false;
	return true;
}

void hooman::set_hooman_rect(SDL_Rect _hooman) {
	object = _hooman;
}