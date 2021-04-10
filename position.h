#ifndef POSITION_H_
#define POSITION_H_

using namespace std;

class position {

public:

	int row;
	int col;

	position(int row, int col);

};

position::position(int row = 0, int col = 0) {
	this->row = row;
	this->col = col;
}


#endif /* POSITION_H_ */
