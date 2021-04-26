#ifndef bridge_
	#define bridge_

#include "base_class.h"

using namespace std;

class bridge : public Base_Object {
public:
	bridge(SDL_Rect _bridge);
	void draw(int unit);
	void fall_down();
	void set_bridge_rect(SDL_Rect B_rect);
	void inc_len();
	int local_pos();
};

#endif 
