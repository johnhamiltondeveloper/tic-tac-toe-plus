#include "Player.h"
#include "position.h"
#include <iostream>
#include "Bored.h"
#include <stdlib.h>
#include <time.h>

#ifndef RANDOMPLAYER_H_
#define RANDOMLAYER_H_

using namespace std;

class RandomPlayer: public player {

public:
	RandomPlayer();
	~RandomPlayer();

	position get_input(bored Bored);
	void getErrorMessage();
	bool shouldDisplay();

};

void RandomPlayer::getErrorMessage() {
}

bool RandomPlayer::shouldDisplay(){
	return false;
}

RandomPlayer::RandomPlayer() {
	srand(time(NULL));
}

RandomPlayer::~RandomPlayer() {
}

position RandomPlayer::get_input(bored Bored) {

	position pos;

	pos.row = rand()%Bored.getBoredSize();
	pos.col = rand()%Bored.getBoredSize();

	return pos;
}

#endif /* RANDOMPLAYER_H_ */
