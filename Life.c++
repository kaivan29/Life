/** @file Life.c++
 *  @brief Life is a simple simulation of cell automata
 *   
 * It creates a Life of cells and goes under evolutions.
 */

// --------
// includes
// --------

#include <iostream>
#include <string>
#include <sstream>
#include "Life.h"

using namespace std;


/**********************/
/* ABSTRACTCELL CLASS */
/**********************/

AbstractCell::AbstractCell() :
	alive(false),
	alivePrint('A'),
	deadPrint('D') {}

/*
 * To check if the cell is alive.
 */
// according to Piazza this getter is allowed (and encouraged/required)
bool AbstractCell::isAlive() {
	return alive;
}

/*
* @param rhs the AbstractCell
* <br> Override the Equals Operator
*/
AbstractCell& AbstractCell::operator=(AbstractCell& rhs){
	alive = rhs.alive;
	alivePrint = rhs.alivePrint;
	deadPrint = rhs.deadPrint;
	return *this;
}

/*
* @param rhs the AbstractCell
* <br> Override the Equals Operator
*/
AbstractCell* AbstractCell::operator=(AbstractCell* rhs){
	alive = rhs->alive;
	alivePrint = rhs->alivePrint;
	deadPrint = rhs->deadPrint;
	return this;
}


/********************/
/* CONWAYCELL CLASS */
/********************/

/*
* @param _alive boolean value
* <br> parameterized Constructor for Conway Cell
*/
ConwayCell::ConwayCell(bool _alive) {
	alivePrint = '*';
	deadPrint = '.';
	alive = _alive;
}

/*
* @param numAdjAlive Alive Cells as Adjacent Neigbors
* @param cellType The type of the cells Life should have
* <br> Evolves the conway cell based on the conditions.
*/
size_t ConwayCell::evolve(size_t numAdjAlive, string cellType) {
	if (this->alive && (numAdjAlive < 2 || numAdjAlive > 3))	return CC_GO_DEAD;	// alive -> dead
	else if ((!this->alive) && (numAdjAlive == 3))				return CC_GO_ALIVE;	// dead -> alive
																return CC_STAY_SAME;
}

/*
* @param inst Enums for the State of the ConwayCell
* <br> Updates the state of the ConwayCell based on the argument.
*/
void ConwayCell::update(size_t inst) {
	switch (inst) {
		case CC_STAY_SAME: {
			break;
		}
		case CC_GO_DEAD: {
			alive = false;
			break;
		}
		case CC_GO_ALIVE: {
			alive = true;
			break;
		}
		default: {
			throw invalid_argument("unhandled instruction in ConwayCell::update()");
		}
	}
}


/*********************/
/* FREDKINCELL CLASS */
/*********************/

/*
* @param age size_t value
* @param _alive boolean value
* <br> Parameterized Constructor for FredkinCell.
*/
FredkinCell::FredkinCell(size_t age, bool _alive) {
	alivePrint = '0';
	deadPrint = '-';
	setAge(age);
	alive = _alive;
}

/*
* @param numAdjAlive Alive Cells as Adjacent Neigbors
* @param cellType The type of the cells Life should have
* <br> Evolves the Fredkin cell based on the conditions.
*/
size_t FredkinCell::evolve(size_t numAdjAlive, string cellType) {
	// convert from alive to dead
	if (this->alive && (numAdjAlive % 2 == 0)) {
		return FC_GO_DEAD;
	}

	// convert from dead to alive
	else if (!this->alive && (numAdjAlive % 2 == 1)) {
		return FC_GO_ALIVE;
	}

	// stays alive
	else if (this->alive && (numAdjAlive % 2 == 1)) {

		// convert to a ConwayCell if age is 2 after incrementation
		if ((cellType == "Cell") && this->alivePrint == '1') {
			return FC_BECOME_CC;
		}
		return FC_STAY_ALIVE;
	}
	return FC_STAY_DEAD;															// dead -> dead
}

/*
* Increment the age of an alive FredkinCell
* <br> If over 9 set to a '+'
*/
FredkinCell& FredkinCell::operator++() {
	if (alivePrint != '+') {
		size_t age_num = (size_t) (alivePrint - '0');
		setAge(++age_num);
	}
	return *this;
}

/*
* @param age size_t value
* <br> sets the age of an alive FredkinCell if it stays alive
*/
void FredkinCell::setAge(const size_t& age) {
	if (age > 9 || (age == (size_t) '+'))	alivePrint = '+';
	else									alivePrint = age + '0';
}

/*
* @param inst Enums for the State of the FredkinCell
* <br> Updates the state of the FredkinCell based on the argument.
*/
void FredkinCell::update(size_t inst) {
	switch (inst) {
		case FC_STAY_ALIVE: {
			++(*this);
			break;
		}
		case FC_STAY_DEAD: {
			break;
		}
		case FC_GO_DEAD: {
			alive = false;
			break;
		}
		case FC_GO_ALIVE: {
			alive = true;
			break;
		}
		default: {
			throw invalid_argument("unhandled instruction in ConwayCell::update()");
		}
	}
}


/**************/
/* CELL CLASS */
/**************/

/*
* @param rhs Abstract Cell
* <br> parameterized Constructor for Cell
*/
Cell::Cell(AbstractCell* const rhs) :
nextState(0) {
	container = rhs;
}

/*
* @param rhs Cell
* <br> parameterized Constructor for Cell
*/
Cell::Cell(const Cell& rhs) {
	*container = *(rhs.container);
	nextState = rhs.nextState;
}

/*
* @param numAdjAlice size_t value
* @param cellType string value
* <br> Sets up the nextState of the Cell
*/
void Cell::setup(size_t numAdjAlive, string cellType) {
	nextState = container->evolve(numAdjAlive, cellType);
}

/*
 * Takes the nextTurn/evolution and update the state of the Cell.
 */
void Cell::takeTurn() {
	if (nextState == FC_BECOME_CC) {
		AbstractCell* contain = container;
		delete contain;
		*this = new ConwayCell(true);
	} else container->update(nextState);
}

/*
* @param rhs the AbstractCell
* <br> Override the Equals Operator of Cell
*/
Cell& Cell::operator=(AbstractCell* const rhs) {
	*container = *rhs;
	nextState = 0;
	return *this;
}


/**************/
/* LIFE CLASS */
/**************/

/*
* @param x size_t value
* @param y size_t value
* <br> Gets the Alive Adjacent Cells
*/
template <typename T>
size_t Life<T>::getAdjAlive(size_t x, size_t y) {

	size_t counter = 0;

	// ConwayCell
	if (ConwayCell* cc = dynamic_cast<ConwayCell*> (grid[x][y].container)) {
	//if (grid[x][y].container->)
		//cout << "conway cell" << endl;
		int dx[] = { -1, 1,  0, 0, -1, -1,  1, 1 };
		int dy[] = {  0, 0, -1, 1, -1,  1, -1, 1 };
		for (int temp = 0; temp < 8; temp++)
			if ((grid[x + dx[temp]][y + dy[temp]]).container->isAlive())
				++counter;
	}
	
	// FredkinCell
	else {
		//cout << "fredkin cell" << endl;
		int dx[] = { -1, 1,  0, 0 };
		int dy[] = {  0, 0, -1, 1 };
		for (int temp = 0; temp < 4; temp++)
			if ((grid[x + dx[temp]][y + dy[temp]]).container->isAlive())
				++counter;
	}
	return counter;
}

/*
 * Beginning of the iterable Life.
 */
template<>
typename Life<Cell>::iterator Life<Cell>::begin() {
	return grid.begin();
}

/*
 * End of the iterable Life.
 */
template<>
typename Life<Cell>::iterator Life<Cell>::end() {
	return grid.end();
}

/*
* @param x size_t value
* @param y size_t value
* <br> (x,y) position of cell on the Life grid
*/
template<>
Cell Life<Cell>::at(size_t x, size_t y) {
	return grid[x][y];
}

/*
* @param i istream
* @param o ostream
* <br> Reads the data and Simulates the cell automata
*/
template<>
void Life<Cell>::go(istream &i, ostream &out) {

	getline(i, cellType);

	if (cellType != "Cell" &&
		cellType != "ConwayCell" &&
		cellType != "FredkinCell")
		throw invalid_argument("cell type " + cellType + " is unsupported");

	string numRowsS;
	getline(i, numRowsS);
	size_t numRows = stoi(numRowsS)+2;
	
	string numColsS;
	getline(i, numColsS);
	size_t numCols = stoi(numColsS)+2;

	string numEvolS;
	getline(i, numEvolS);
	numEvol = stoi(numEvolS);

	string freqS;
	getline(i, freqS);
	freq = stoi(freqS);

	out << "*** Life<" + cellType + "> " << numRows-2 << "x" << numCols-2 << " ***" << endl<<endl;

	// intialize grid with border; defaulted to dead ConwayCells
	for (size_t j = 0; j < numRows; j++)
		grid.push_back(vector<Cell>(numCols, Cell(new ConwayCell(false))));

	string row;
	for (size_t rowNum = 1; rowNum < numRows-1; rowNum++) {
		getline(i, row);
		if (row != "\n") {
			for (size_t colNum = 1; colNum < numCols-1; colNum++) {
				char c = row[colNum-1];

				// remove default data
				Cell& cPos = grid[rowNum][colNum];
				AbstractCell* contain = cPos.container;

				// fill board based on input
				if (c == '.')		grid[rowNum][colNum].container = new ConwayCell(false); // TODO: is this new allowed?
				else if (c == '*')	grid[rowNum][colNum].container = new ConwayCell(true);
				else if (c == '-')	grid[rowNum][colNum].container = new FredkinCell(0, false);
				else if (c == '+')	grid[rowNum][colNum].container = new FredkinCell(10, true);
				else if (c <= '9' && c >= '0') grid[rowNum][colNum].container = new FredkinCell(c - '0', true);
				else throw invalid_argument("cannot have cell of type " + c);
			}
		}
	}

	// while there are still turns to take
	// get info on what is about to happen
	int generation = 0;
	while (numEvol!= -1) {

		//print the grid
		if (numEvol%freq == 0){
			int numAlive = 0;
			for (size_t i = 1; i < numRows - 1; ++i) {
				for (size_t j = 1; j < numCols - 1; ++j)
					if (grid[i][j].container->isAlive())
						++numAlive;
			}
			out << "Generation = " << generation << ", Population = " << numAlive << "." << endl;
			for (size_t i = 1; i < numRows - 1; ++i) {
				for (size_t j = 1; j < numCols - 1; ++j)
					out << grid[i][j].container;
					out << endl;
			}
			out << endl;
		}
		++generation;

		int count = 0;
		// setup each cell
		for (size_t x = 1; x < numRows-1; ++x) {
			for (size_t y = 1; y < numCols-1; ++y) {
				Cell& c = grid[x][y];
				// cout << count++ << endl;
				c.setup(getAdjAlive(x, y), cellType);
			}
		}

		// evolve each cell
		for (size_t x = 1; x < numRows - 1; ++x) {
			for (size_t y = 1; y < numCols - 1; ++y) {
				Cell& c = grid[x][y];
				c.takeTurn();
			}
		}
		--numEvol;
	}
}