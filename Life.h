/** @file Life.h
 *  @brief Life is a simple simulation of Cell Automata
 *   
 * Header file for Life
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

enum STATES {	CC_STAY_SAME, CC_GO_DEAD, CC_GO_ALIVE,
				FC_STAY_ALIVE, FC_STAY_DEAD, FC_GO_DEAD, FC_GO_ALIVE, FC_BECOME_CC };

class AbstractCell {
protected:
	FRIEND_TEST(ConwayCell, cc_1);
	FRIEND_TEST(ConwayCell, cc_2);
	FRIEND_TEST(ConwayCell, cc_3);
	FRIEND_TEST(ConwayCell, cc_4);
	FRIEND_TEST(ConwayCell, cc_5);
	FRIEND_TEST(ConwayCell, cc_6);
	FRIEND_TEST(ConwayCell, cc_7);
	FRIEND_TEST(ConwayCell, cc_8);
	FRIEND_TEST(ConwayCell, cc_9);
	FRIEND_TEST(ConwayCell, cc_10);
	FRIEND_TEST(ConwayCell, cc_11);
	FRIEND_TEST(ConwayCell, cc_12);
	FRIEND_TEST(ConwayCell, cc_13);
	FRIEND_TEST(ConwayCell, cc_14);
	FRIEND_TEST(ConwayCell, cc_15);
	FRIEND_TEST(ConwayCell, cc_16);
	FRIEND_TEST(ConwayCell, cc_17);
	FRIEND_TEST(ConwayCell, cc_18);
	FRIEND_TEST(ConwayCell, cc_19);
	FRIEND_TEST(ConwayCell, cc_20);
	FRIEND_TEST(ConwayCell, cc_21);
	FRIEND_TEST(ConwayCell, cc_22);
	FRIEND_TEST(ConwayCell, cc_23);
	FRIEND_TEST(ConwayCell, cc_24);
	FRIEND_TEST(ConwayCell, cc_25);
	FRIEND_TEST(ConwayCell, cc_26);
	FRIEND_TEST(ConwayCell, cc_27);
	FRIEND_TEST(ConwayCell, cc_28);
	FRIEND_TEST(ConwayCell, cc_29);
	FRIEND_TEST(ConwayCell, cc_30);
	FRIEND_TEST(ConwayCell, cc_31);
	FRIEND_TEST(ConwayCell, cc_32);
	FRIEND_TEST(ConwayCell, cc_33);


	FRIEND_TEST(FredkinCell, fc_1);
	FRIEND_TEST(FredkinCell, fc_2);
	FRIEND_TEST(FredkinCell, fc_3);
	FRIEND_TEST(FredkinCell, fc_4);
	FRIEND_TEST(FredkinCell, fc_5);
	FRIEND_TEST(FredkinCell, fc_6);
	FRIEND_TEST(FredkinCell, fc_7);
	FRIEND_TEST(FredkinCell, fc_8);
	FRIEND_TEST(FredkinCell, fc_9);
	FRIEND_TEST(FredkinCell, fc_10);
	FRIEND_TEST(FredkinCell, fc_11);
	FRIEND_TEST(FredkinCell, fc_12);
	FRIEND_TEST(FredkinCell, fc_13);
	FRIEND_TEST(FredkinCell, fc_14);
	FRIEND_TEST(FredkinCell, fc_15);
	FRIEND_TEST(FredkinCell, fc_16);
	FRIEND_TEST(FredkinCell, fc_17);
	FRIEND_TEST(FredkinCell, fc_18);
	FRIEND_TEST(FredkinCell, fc_19);
	FRIEND_TEST(FredkinCell, fc_20);
	FRIEND_TEST(FredkinCell, fc_21);
	FRIEND_TEST(FredkinCell, fc_22);
	FRIEND_TEST(FredkinCell, fc_23);
	FRIEND_TEST(FredkinCell, fc_24);
	FRIEND_TEST(FredkinCell, fc_25);
	FRIEND_TEST(FredkinCell, fc_26);
	FRIEND_TEST(FredkinCell, fc_27);
	FRIEND_TEST(FredkinCell, fc_28);
	FRIEND_TEST(FredkinCell, fc_29);
	FRIEND_TEST(FredkinCell, fc_30);
	FRIEND_TEST(FredkinCell, fc_31);
	FRIEND_TEST(FredkinCell, fc_32);
	FRIEND_TEST(FredkinCell, fc_33);
	FRIEND_TEST(FredkinCell, fc_34);
	FRIEND_TEST(FredkinCell, fc_35);
	FRIEND_TEST(FredkinCell, fc_36);
	FRIEND_TEST(FredkinCell, fc_37);
	FRIEND_TEST(FredkinCell, fc_38);

	bool alive;
	char alivePrint;
	char deadPrint;

 public:
	AbstractCell();
	virtual ~AbstractCell() {}
	bool isAlive();
	virtual size_t evolve(size_t numAdjAlive, string cellType) = 0;
	virtual void update(size_t inst) = 0;

	AbstractCell& operator=(AbstractCell& rhs);
	AbstractCell* operator=(AbstractCell* rhs); 
	friend ostream& operator<<(ostream& out, AbstractCell* rhs) {
		if (rhs->alive)	out << rhs->alivePrint;
		else			out << rhs->deadPrint;
		return out;
	}
};

class ConwayCell : public AbstractCell {
public:
	ConwayCell(bool _alive);
	size_t evolve(size_t numAdjAlive, string cellType);
	void update(size_t inst);
};

class FredkinCell : public AbstractCell {
public:
	FredkinCell(size_t age, bool _alive);
	FredkinCell& operator++(); // increment the age of the FredkinCell; if over 9 set to a '+'
	void setAge(const size_t& age);
	size_t evolve(size_t numAdjAlive, string cellType);
	void update(size_t inst);
};

class Cell {
public:
	size_t nextState;
	AbstractCell* container = new ConwayCell(false);

	Cell(AbstractCell* const rhs);
	Cell(const Cell& rhs);
	~Cell() { delete container; }

	Cell& operator=(AbstractCell* const rhs);

	void setup(size_t numAdjAlive, string cellType);
	void takeTurn();
};

template<typename T>
class Life {
private:
	typedef vector<vector<Cell>>::iterator iterator;
	vector<vector<Cell> > grid;
	size_t numEvol;
	size_t freq;
	string cellType;

	size_t getAdjAlive(size_t x, size_t y);
	void nextTurn();

public:
	void go(istream &i, ostream &o);
	iterator begin();
	iterator end();
	T at(size_t x, size_t y);
};