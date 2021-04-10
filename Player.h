#include "position.h"
#include "Bored.h"
#include <iostream>

#ifndef PLAYER_H_
#define PLAYER_H_

using namespace std;

class player {
	public:
	virtual position get_input(bored Bored) = 0;
	virtual void getErrorMessage();
	virtual bool shouldDisplay();

	player();
	virtual ~player();

};

player::player() {
}

player::~player() {

}

bool player::shouldDisplay() {
	return false;
	cout << "-------------This code should not show up----------------";
}
void player::getErrorMessage() {
}

//position player::get_input(bored Bored) {
//
//	position pos;
//
//	return pos;
//
//}




#endif /* PLAYER_H_ */
