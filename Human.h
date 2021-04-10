#include <iostream>
using namespace std;

#ifndef HUMAN_H_
#define HUMAN_H_

class human {

private:
	int BoradSize;
	int row;
	int col;

public:

	human(int);
	~human();
	void getInput();
	int getRow();
	int getCol();

};

human::human(int Size) {
	BoradSize = Size;
	row = 0;
	col = 0;
}

human::~human() {

}

void human::getInput() {

	int row, col;

	cout << "Please enter player 1s move" << endl;
	cout << "Please Enter Row from 1 to " << BoradSize << ":";
	cin >> row;
	cout << "Please Enter column from 1 to " << BoradSize << ":";
	cin >> col;

	this->col = col;
	this->row = row;


}

int human::getRow() {
	return row;
}

int human::getCol(){
	return col;
}

#endif /* HUMAN_H_ */
