#ifndef challenges_
	#define challenges_

#include "data.h"
#include "base_class.h"

using namespace std;

class challenge : public Base_Object {
public:
	challenge(SDL_Rect challenger_rect);//1
	void init();//2
	int pos_of_bridge();//3
	void set_challenge_rect(SDL_Rect challenger_rect);//4
	void show(int unit);//5
	void pull();//6
	bool compare(int p);
	//
	SDL_Rect* pos = new SDL_Rect[3];
	string* img_path = new string[3];
	int distance;
};
#endif
