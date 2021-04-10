#ifndef SMART_PLAYER_H_
#define SMART_PLAYER_H_

#include "Bored.h"
#include "Player.h"
#include "position.h"

using namespace std;

class smartPlayer : public player {

public:
	smartPlayer();
	~smartPlayer();
	position get_input(bored Bored);
	void getErrorMessage();
	bool shouldDisplay();

};

smartPlayer::smartPlayer(){

}

smartPlayer::~smartPlayer(){

}

position smartPlayer::get_input(bored Bored){

	int LargestSize = 0;
	position Out(0,0);

	for (int i = 0; i < Bored.getBoredSize(); i++){
		for (int j = 0; j < Bored.getBoredSize(); j++){

			position pos(i,j);

			if (Bored.IsMoveValid(pos) == true){

				for (int player = 0; player < 2;  player++){

					int MoveLength = Bored.getPlayerMoveLength(pos,player);

					if (LargestSize < MoveLength){
						LargestSize = MoveLength;
						Out = pos;
					}
				}

			}

		}

	}
	return Out;
}
void smartPlayer::getErrorMessage() {

}

bool smartPlayer::shouldDisplay() {
	return false;
}

#endif
