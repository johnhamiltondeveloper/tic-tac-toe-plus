#include <iostream>

#include "Bored.h"

#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "SmartPlayer.h"
#include "Player.h"

#include "position.h"

using namespace std;

#ifndef GAME_H_
#define GAME_H_

class game {

private:

	player **players;

	bored *GameBored;

	int currentPlayer;

	void changePlayer();

	const int PlayersTotal = 2;

public:
	game();

	~game();
	void play();
};

game::game() {


	currentPlayer = 0;

	players = new player*[PlayersTotal];

	cout << "---------------------Bored Setup---------------------" << endl;

	int InputSize, InputWinLength;
	cout << "Enter Bored Size:";
	cin >> InputSize;
	cout << "Enter Win length:";
	cin >> InputWinLength;

	GameBored = new bored(InputSize,InputWinLength);

	cout << "---------------------Player Setup---------------------" << endl;

	cout << "Players Select:" << endl;
	cout << "-Smart Player 1" << endl;
	cout << "-Random Player 2" << endl;
	cout << "-Human Player 3" << endl << endl;

	for (int i = 0; i < PlayersTotal; i++){

		int input = -1;

		cout << "Player " << i+1 << endl << "Enter:";
		cin >> input;

		input--;

		if (input == 0){
			players[i] = new smartPlayer;
		}
		if (input == 1){
			players[i] = new RandomPlayer;
				}
		if (input == 2){
			players[i] = new HumanPlayer;

				}


	}

}

game::~game() {

	for(int i = 0; i < PlayersTotal; i++) {
		delete players[i];
	}

	delete [] players;
}

void game::play() {

	do {

		if(players[currentPlayer]->shouldDisplay()){

			cout << "Player " << currentPlayer+1 << endl;
			GameBored->display();

		}

		position inputPos = players[currentPlayer]->get_input(*GameBored);

		if (GameBored->IsMoveValid(inputPos)) {

			GameBored->ApplyMove(inputPos,currentPlayer);
			changePlayer();
		}

		else {
			players[currentPlayer]->getErrorMessage();
		}

	}

	while(!GameBored->isBoredFull() && GameBored->WinningPlayer() == -1);

	GameBored->display();

	if (GameBored->WinningPlayer() != -1){
		cout << "Player " << GameBored->WinningPlayer()+1 << " is the winer";
	}

	if (GameBored->isBoredFull() == true) {
		cout << "Game was a tie game bored full";
	}

}

void game::changePlayer() {

	currentPlayer++;

	if (currentPlayer >= PlayersTotal) {
		currentPlayer = 0;
	}
}

#endif /* GAME_H_ */
