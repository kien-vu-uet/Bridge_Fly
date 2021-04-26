#ifndef character_
	#define character_

#include "base_class.h"

using namespace std;

class hooman : public Base_Object{
private:
	int index = 0;
public:
	hooman(SDL_Rect _hooman);
	void set_hooman_rect(SDL_Rect _hooman);
	void def_show();
	void show();
	bool fall();
};

#endif
