#include <iostream>
#include "position.h"

using namespace std;

#ifndef BORED_H_
#define BORED_H_

using namespace std;

class bored {

private:
	int **GameBored;
	int BoredSize;
	int WinLength;
	int MoveDone;
	int MAX_MOVES;
	int winningPlayer;

public:

	bored(int size, int WinLength);
	~bored();
	bored(const bored &cboard);

	void ApplyMove(position pos, int playerID);
	void display();
	int getBoredSize() const;
	bool Status(position pos, int player);
	bool IsMoveValid(position pos);
	bool isBoredFull();
	int WinningPlayer();
	int getPlayerMoveLength(position pos, int player);

};

bored::bored(int size, int RowA) {

	MoveDone = 0;
	BoredSize = size;
	winningPlayer = -1;

	MAX_MOVES = BoredSize * BoredSize;

	WinLength = RowA;

	GameBored = new int*[size];

	for (int i = 0; i < size; i++) {
		GameBored[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			GameBored[i][j] = -1;
		}
	}

}

bored::~bored() {

	for (int i = 0; i < BoredSize; i++) {
		delete[] GameBored[i];
	}

	delete[] GameBored;

}

bored::bored(const bored &cboard) {

	this->WinLength = cboard.WinLength;
	this->BoredSize = cboard.BoredSize;

	this->MoveDone = cboard.MoveDone;
	this->BoredSize = cboard.BoredSize;
	this->winningPlayer = cboard.winningPlayer;
	this->MAX_MOVES = cboard.MAX_MOVES;

	GameBored = new int*[BoredSize];

	for (int i = 0; i < BoredSize; i++) {
		GameBored[i] = new int[BoredSize];
	}

	for (int i = 0; i < BoredSize; i++) {
		for (int j = 0; j < BoredSize; j++) {
			GameBored[i][j] = cboard.GameBored[i][j];
		}
	}

}

int bored::WinningPlayer() {
	return winningPlayer;
}

void bored::display() {

	char PlayersChar[2] = { 'X', 'O' };

	for (int i = 0; i < BoredSize; i++) {

		for (int j = 0; j < BoredSize; j++) {

			if (GameBored[i][j] == -1) {
				cout << " ";
			} else {
				cout << PlayersChar[GameBored[i][j]];
			}

			if (j < BoredSize - 1) {
				cout << "---";
			}
		}

		cout << endl;

		if (i < BoredSize - 1) {
			for (int j = 0; j < BoredSize; j++) {
				cout << "|   ";
			}

			cout << endl;
		}
	}
}

void bored::ApplyMove(position pos, int playerID) {
	GameBored[pos.row][pos.col] = playerID;

	MoveDone++;

	if (Status(pos, playerID)) {
		winningPlayer = playerID;
	}

}

bool bored::Status(position pos, int player) {

	int MoveLengths = getPlayerMoveLength(pos,player);

	if (MoveLengths >= WinLength) {
		return true;
	}

	return false;
}

int bored::getPlayerMoveLength(position pos, int player) {

	int horizontal = 0;
	int vertical = 0;
	int diagonalDownLeft = 0;
	int diagonalDownRight = 0;

	int LargestLength = 0;

	if (GameBored[pos.row][pos.col] == player){
		horizontal++;
		vertical++;
		diagonalDownLeft++;
		diagonalDownRight++;
	}

	// ------------------------------------horizontal---------------------------------------------------

	{
		int right = 1;

		while (pos.col + right >= 0 && GameBored[pos.row][pos.col + right] == player) {
			right++;
			horizontal++;
		}
	}

	{
		int left = 1;

		while (pos.col - left < BoredSize
				&& GameBored[pos.row][pos.col - left] == player) {
			left++;
			horizontal++;
		}
	}

	// -----------------------------------------vertical--------------------------------------------------

	{
		int up = 1;

		while ((pos.row - up) >= 0 && GameBored[pos.row - up][pos.col] == player) {
			up++;
			vertical++;
		}
	}

	{
		int down = 1;

		while ((pos.row + down) < BoredSize
				&& GameBored[pos.row + down][pos.col] == player) {
			down++;
			vertical++;
		}
	}

	// ------------------------------------diagonalDownRight---------------------------------------------------

	{
		int up = 1;

		while ((((pos.row - up) >= 0) && (pos.col - up) >= 0)
				&& GameBored[pos.row - up][pos.col - up] == player) {
			up++;
			diagonalDownRight++;
		}
	}

	{
		int down = 1;

		while (((pos.row + down) < BoredSize) && ((pos.col + down) < BoredSize)
				&& GameBored[pos.row + down][pos.col + down] == player) {
			down++;
			diagonalDownRight++;
		}
	}

	// ------------------------------------diagonalDownLeft---------------------------------------------------

	{
		int up = 1;

		while ((((pos.row - up) >= 0) && (pos.col + up) >= 0)
				&& GameBored[pos.row - up][pos.col + up] == player) {
			up++;
			diagonalDownLeft++;
		}
	}

	{
		int down = 1;

		while (((pos.row + down) < BoredSize) && ((pos.col - down) < BoredSize)
				&& GameBored[pos.row + down][pos.col - down] == player) {
			down++;
			diagonalDownLeft++;
		}
	}

	LargestLength = 0;

	if (LargestLength < horizontal) {
		LargestLength = horizontal;
	}

	if (LargestLength < vertical) {
		LargestLength = vertical;
	}

	if (LargestLength < diagonalDownLeft) {
		LargestLength = diagonalDownLeft;
	}

	if (LargestLength < diagonalDownRight) {
		LargestLength = diagonalDownRight;
	}

	return LargestLength;
}
int bored::getBoredSize() const{

	return BoredSize;
}

bool bored::isBoredFull() {

	if (MoveDone == MAX_MOVES) {
		return true;
	}

	return false;
}

bool bored::IsMoveValid(position pos) {

	if (pos.row >= BoredSize || pos.row < 0) {
		return false;
	}

	if (pos.col >= BoredSize || pos.col < 0) {
		return false;
	}

	if (GameBored[pos.row][pos.col] != -1) {
		return false;
	}

	return true;

}

#endif /* BORED_H_ */
