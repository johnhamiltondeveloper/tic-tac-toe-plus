#include "Player.h"
#include "position.h"
#include <iostream>
#include "Bored.h"

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

using namespace std;

class HumanPlayer : public player {

public:
	HumanPlayer();
	~HumanPlayer();
	position get_input(bored Bored);
	void getErrorMessage();
	bool shouldDisplay();

};

bool HumanPlayer::shouldDisplay(){
	return true;
}

void HumanPlayer::getErrorMessage() {
	cout << endl << "## This move is not valid please enter another ##" << endl;
}

HumanPlayer::HumanPlayer() {
}

HumanPlayer::~HumanPlayer() {
}

position HumanPlayer::get_input(bored Bored) {

	position pos;

	int row, col;

	cout << endl << "Enter Row:";
	cin >> row;
	cout << "Enter Col:";
	cin >> col;

	pos.col = col;
	pos.row = row;

	pos.row -= 1;
	pos.col -= 1;


	return pos;

}

#endif /* HUMANPLAYER_H_ */
