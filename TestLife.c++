/** @file TestLife.c++
 *  @brief Unit Tests 
 *   
*/

#include <string>
#include <iostream>
#include <cassert>

#include "Life.h"

#include "gtest/gtest.h"

using namespace std;
using std::ostringstream;

/*g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++11 
-Wall Life.c++ TestLife.c++ -o TestLife -lgtest -lgtest_main -lpthread*/

//********ConwayCell******
TEST(ConwayCell, cc_1) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.alive, true);
}

TEST(ConwayCell, cc_2) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.alivePrint, '*');
}

TEST(ConwayCell, cc_3) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.deadPrint, '.');
}

TEST(ConwayCell, cc_4) {
	ConwayCell cc(false);
	ASSERT_EQ(cc.alive, false);
}

TEST(ConwayCell, cc_5) {
	ConwayCell cc(false);
	ASSERT_EQ(cc.alivePrint, '*');
}

TEST(ConwayCell, cc_6) {
	ConwayCell cc(false);
	ASSERT_EQ(cc.deadPrint, '.');
}

//evolve in ConwayCell
TEST(ConwayCell, cc_7) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(0, "ConwayCell"), 1);
}

TEST(ConwayCell, cc_8) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(1, "ConwayCell"), 1);
}

TEST(ConwayCell, cc_9) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(2, "ConwayCell"), 0);
}

TEST(ConwayCell, cc_10) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(3, "ConwayCell"), 0);
}

TEST(ConwayCell, cc_11) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(4, "ConwayCell"), 1);
}

TEST(ConwayCell, cc_12) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(5, "ConwayCell"), 1);
}

TEST(ConwayCell, cc_13) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(6, "ConwayCell"), 1);
}

TEST(ConwayCell, cc_14) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(7, "ConwayCell"), 1);
}

TEST(ConwayCell, cc_15) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(8, "ConwayCell"), 1);
}

//dead Conway Cells
TEST(ConwayCell, cc_16) {
	ConwayCell cc(false);
	ASSERT_EQ(cc.evolve(0, "ConwayCell"), CC_STAY_SAME);
}

TEST(ConwayCell, cc_17) {
	ConwayCell cc(false);
	ASSERT_EQ(cc.evolve(1, "ConwayCell"), CC_STAY_SAME);
}

TEST(ConwayCell, cc_18) {
	ConwayCell cc(false);
	ASSERT_EQ(cc.evolve(2, "ConwayCell"), CC_STAY_SAME);
}

TEST(ConwayCell, cc_19) {
	ConwayCell cc(false);
	ASSERT_EQ(cc.evolve(3, "ConwayCell"), CC_GO_ALIVE);
}

TEST(ConwayCell, cc_20) {
	ConwayCell cc(false);
	ASSERT_EQ(cc.evolve(4, "ConwayCell"), CC_STAY_SAME);
}

TEST(ConwayCell, cc_21) {
	ConwayCell cc(false);
	ASSERT_EQ(cc.evolve(5, "ConwayCell"), CC_STAY_SAME);
}

TEST(ConwayCell, cc_22) {
	ConwayCell cc(false);
	ASSERT_EQ(cc.evolve(6, "ConwayCell"), CC_STAY_SAME);
}

TEST(ConwayCell, cc_23) {
	ConwayCell cc(false);
	ASSERT_EQ(cc.evolve(7, "ConwayCell"), CC_STAY_SAME);
}

TEST(ConwayCell, cc_24) {
	ConwayCell cc(false);
	ASSERT_EQ(cc.evolve(8, "ConwayCell"), CC_STAY_SAME);
}

//UPDATE CONWAY CELL
TEST(ConwayCell, cc_25) {
	ConwayCell cc(true);
	cc.update(0);
	ASSERT_EQ(cc.isAlive(), true);
}

TEST(ConwayCell, cc_26) {
	ConwayCell cc(true);
	cc.update(1);
	ASSERT_EQ(cc.isAlive(), false);
}

TEST(ConwayCell, cc_27) {
	ConwayCell cc(false);
	cc.update(0);
	ASSERT_EQ(cc.isAlive(), false);
}

TEST(ConwayCell, cc_28) {
	ConwayCell cc(false);
	cc.update(2);
	ASSERT_EQ(cc.isAlive(), true);
}

//cellType Cell
TEST(ConwayCell, cc_29) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(0, "Cell"), 1);
}

TEST(ConwayCell, cc_30) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(1, "Cell"), 1);
}

TEST(ConwayCell, cc_31) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(2, "Cell"), 0);
}

TEST(ConwayCell, cc_32) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(3, "Cell"), 0);
}

TEST(ConwayCell, cc_33) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(4, "Cell"), 1);
}

TEST(ConwayCell, cc_34) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(5, "Cell"), 1);
}

TEST(ConwayCell, cc_35) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(6, "Cell"), 1);
}

TEST(ConwayCell, cc_36) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(7, "Cell"), 1);
}

TEST(ConwayCell, cc_37) {
	ConwayCell cc(true);
	ASSERT_EQ(cc.evolve(8, "Cell"), 1);
}

TEST(ConwayCell, upd_exc) {
	ConwayCell cc(true);
	bool got_into_exc = false;
	try {
		cc.update(11);
	} catch(invalid_argument& e) {
		// caught exception successfully
		got_into_exc = true;
	} catch(...) {
		ASSERT_TRUE(false);
	}
    ASSERT_TRUE(got_into_exc);
}


//******FredkinCell******
TEST(FredkinCell, fc_1) {
	FredkinCell fc(0, true);
	ASSERT_EQ(fc.alive, true);
}

TEST(FredkinCell, fc_2) {
	FredkinCell fc(0, true);
	ASSERT_EQ(fc.alivePrint, '0');
}

TEST(FredkinCell, fc_3) {
	FredkinCell fc(0, true);
	ASSERT_EQ(fc.deadPrint, '-');
}

TEST(FredkinCell, fc_4) {
	FredkinCell fc(0, false);
	ASSERT_EQ(fc.alive, false);
}

TEST(FredkinCell, fc_5) {
	FredkinCell fc(0, false);
	ASSERT_EQ(fc.alivePrint, '0');
}

TEST(FredkinCell, fc_6) {
	FredkinCell fc(0, false);
	ASSERT_EQ(fc.deadPrint, '-');
}

//evolve Fredkin Cell
TEST(FredkinCell, fc_7) {
	FredkinCell fc(0, true);
	ASSERT_EQ(fc.evolve(0, "FredkinCell"), 5);
}

TEST(FredkinCell, fc_8) {
	FredkinCell fc(0, true);
	ASSERT_EQ(fc.evolve(1, "FredkinCell"), 3);
}

TEST(FredkinCell, fc_9) {
	FredkinCell fc(0, true);
	ASSERT_EQ(fc.evolve(2, "FredkinCell"), 5);
}

TEST(FredkinCell, fc_10) {
	FredkinCell fc(0, true);
	ASSERT_EQ(fc.evolve(3, "FredkinCell"), 3);
}

TEST(FredkinCell, fc_11) {
	FredkinCell fc(0, true);
	ASSERT_EQ(fc.evolve(4, "FredkinCell"), 5);
}

//dead Fredkin Cells
TEST(FredkinCell, fc_12) {
	FredkinCell fc(0, false);
	ASSERT_EQ(fc.evolve(0, "FredkinCell"), 4);
}

TEST(FredkinCell, fc_13) {
	FredkinCell fc(0, false);
	ASSERT_EQ(fc.evolve(1, "FredkinCell"), 6);
}

TEST(FredkinCell, fc_14) {
	FredkinCell fc(0, false);
	ASSERT_EQ(fc.evolve(2, "FredkinCell"), 4);
}

TEST(FredkinCell, fc_15) {
	FredkinCell fc(0, false);
	ASSERT_EQ(fc.evolve(3, "FredkinCell"), 6);
}

TEST(FredkinCell, fc_16) {
	FredkinCell fc(0, false);
	ASSERT_EQ(fc.evolve(4, "FredkinCell"), 4);
}

//UPDATE FREDKIN CELL
TEST(FredkinCell, fc_17) {
	FredkinCell fc(0, true);
	fc.update(3);
	ASSERT_EQ(fc.isAlive(), true);
}

TEST(FredkinCell, fc_18) {
	FredkinCell fc(0, true);
	fc.update(5);
	ASSERT_EQ(fc.isAlive(), false);
}

TEST(FredkinCell, fc_19) {
	FredkinCell fc(0, false);
	fc.update(4);
	ASSERT_EQ(fc.isAlive(), false);
}

TEST(FredkinCell, fc_20) {
	FredkinCell fc(0, false);
	fc.update(6);
	ASSERT_EQ(fc.isAlive(), true);
}

//CellType is "Cell" to evolve Fredkin Cell
TEST(FredkinCell, fc_21) {
	FredkinCell fc(0, true);
	ASSERT_EQ(fc.evolve(1, "Cell"), 3);
}

TEST(FredkinCell, fc_22) {
	FredkinCell fc(1, true);
	ASSERT_EQ(fc.evolve(1, "Cell"), 7);
}

TEST(FredkinCell, fc_23) {
	FredkinCell fc(0, true);
	ASSERT_EQ(fc.evolve(3, "Cell"), 3);
}

TEST(FredkinCell, fc_24) {
	FredkinCell fc(1, true);
	ASSERT_EQ(fc.evolve(3, "Cell"), 7);
}

//setAge
TEST(FredkinCell, fc_25) {
	FredkinCell fc(0, true);
	fc.setAge(0);
	ASSERT_EQ(fc.alivePrint, '0');
}

TEST(FredkinCell, fc_26) {
	FredkinCell fc(1, true);
	fc.setAge(1);
	ASSERT_EQ(fc.alivePrint, '1');
}

TEST(FredkinCell, fc_27) {
	FredkinCell fc(2, true);
	fc.setAge(2);
	ASSERT_EQ(fc.alivePrint, '2');
}

TEST(FredkinCell, fc_28) {
	FredkinCell fc(3, true);
	fc.setAge(3);
	ASSERT_EQ(fc.alivePrint, '3');
}

TEST(FredkinCell, fc_29) {
	FredkinCell fc(4, true);
	fc.setAge(4);
	ASSERT_EQ(fc.alivePrint, '4');
}

TEST(FredkinCell, fc_30) {
	FredkinCell fc(5, true);
	fc.setAge(5);
	ASSERT_EQ(fc.alivePrint, '5');
}

TEST(FredkinCell, fc_31) {
	FredkinCell fc(6, true);
	fc.setAge(6);
	ASSERT_EQ(fc.alivePrint, '6');
}

TEST(FredkinCell, fc_32) {
	FredkinCell fc(7, true);
	fc.setAge(7);
	ASSERT_EQ(fc.alivePrint, '7');
}

TEST(FredkinCell, fc_33) {
	FredkinCell fc(8, true);
	fc.setAge(8);
	ASSERT_EQ(fc.alivePrint, '8');
}
TEST(FredkinCell, fc_34) {
	FredkinCell fc(9, true);
	fc.setAge(9);
	ASSERT_EQ(fc.alivePrint, '9');
}

TEST(FredkinCell, fc_35) {
	FredkinCell fc(10, true);
	fc.setAge(10);
	ASSERT_EQ(fc.alivePrint, '+');
}

//++operator of FredkinCell
TEST(FredkinCell, fc_36) {
	FredkinCell fc(1, true);
	++fc;
	ASSERT_EQ(fc.alivePrint, '2');
}

TEST(FredkinCell, fc_37) {
	FredkinCell fc(9, true);
	++fc;
	ASSERT_EQ(fc.alivePrint, '+');
}

TEST(FredkinCell, fc_38) {
	FredkinCell fc(3, true);
	++fc;
	ASSERT_EQ(fc.alivePrint, '4');
}

TEST(FredkinCell, upd_exc) {
	FredkinCell fc(5, true);
	bool got_into_exc = false;
	try {
		fc.update(11);
	} catch(invalid_argument& e) {
		// caught exception successfully
		got_into_exc = true;
	} catch(...) {
		ASSERT_TRUE(false);
	}
	ASSERT_TRUE(got_into_exc);
}

// Cell
TEST(Cell, c_1) {
	Cell c = new ConwayCell(true);
	c.setup(1,"Cell");
	ASSERT_EQ(c.nextState,1);
}

TEST(Cell, c_2) {
	Cell c = new ConwayCell(true);
	c.setup(2,"Cell");
	ASSERT_EQ(c.nextState,0);
}

TEST(Cell, c_3) {
	Cell c = new ConwayCell(true);
	c.setup(3,"Cell");
	ASSERT_EQ(c.nextState,0);
}

TEST(Cell, c_4) {
	Cell c = new FredkinCell(1,true);
	c.setup(3,"Cell");
	ASSERT_EQ(c.nextState,7);
}

TEST(Cell, c_5) {
	Cell c = new FredkinCell(1,true);
	c.setup(2,"Cell");
	ASSERT_EQ(c.nextState,5);
}

TEST(Cell, c_6) {
	Cell c = new FredkinCell(0,true);
	c.setup(3,"Cell");
	ASSERT_EQ(c.nextState,3);
}

TEST(LIFE, l_1) {
	string grid =
    "ConwayCell\n"
    "3\n"
    "3\n"
    "3\n"
    "1\n"
    "...\n"
    ".*.\n"
    "...\n";

    istringstream sin(grid);
    Life<Cell> life;

    ostringstream sout;

    life.go(sin, sout);

    ASSERT_EQ(sout.str(), 
    "*** Life<ConwayCell> 3x3 ***\n\nGeneration = 0, Population = 1.\n...\n.*.\n...\n\nGeneration = 1, Population = 0.\n...\n...\n...\n\nGeneration = 2, Population = 0.\n...\n...\n...\n\nGeneration = 3, Population = 0.\n...\n...\n...\n\n");
}

TEST(LIFE, l_2) {
	string grid =
    "ConwayCell\n"
    "3\n"
    "3\n"
    "3\n"
    "1\n"
    "...\n"
    ".*.\n"
    "...\n";

    istringstream sin(grid);
    Life<Cell> life;

    ostringstream sout;

    life.go(sin, sout);

    ASSERT_EQ(sout.str(), 
    "*** Life<ConwayCell> 3x3 ***\n\nGeneration = 0, Population = 1.\n...\n.*.\n...\n\nGeneration = 1, Population = 0.\n...\n...\n...\n\nGeneration = 2, Population = 0.\n...\n...\n...\n\nGeneration = 3, Population = 0.\n...\n...\n...\n\n");
}

TEST(LIFE, l_3) {
	string grid =
    "ConwayCell\n21\n13\n12\n1\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n....*****....\n.......*.....\n......*......\n.....*.......\n....*****....\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n";

    istringstream sin(grid);
    Life<Cell> life;

    ostringstream sout;

    life.go(sin, sout);

    ASSERT_EQ(sout.str(), 
    "*** Life<ConwayCell> 21x13 ***\n\nGeneration = 0, Population = 13.\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n....*****....\n.......*.....\n......*......\n.....*.......\n....*****....\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n\nGeneration = 1, Population = 17.\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.....***.....\n.....****....\n........*....\n......*......\n....*........\n....****.....\n.....***.....\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n\nGeneration = 2, Population = 14.\n.............\n.............\n.............\n.............\n.............\n.............\n......*......\n.....*..*....\n.....*..*....\n.....*..*....\n.............\n....*..*.....\n....*..*.....\n....*..*.....\n......*......\n.............\n.............\n.............\n.............\n.............\n.............\n\nGeneration = 3, Population = 18.\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.....***.....\n....******...\n.............\n.............\n.............\n...******....\n.....***.....\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n\nGeneration = 4, Population = 16.\n.............\n.............\n.............\n.............\n.............\n.............\n......*......\n....*........\n....*...*....\n.....****....\n.............\n....****.....\n....*...*....\n........*....\n......*......\n.............\n.............\n.............\n.............\n.............\n.............\n\nGeneration = 5, Population = 18.\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.....*.......\n....*.*.*....\n.....****....\n....*...*....\n....****.....\n....*.*.*....\n.......*.....\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n\nGeneration = 6, Population = 16.\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.....*.......\n....*...*....\n....*.*.**...\n....*...*....\n...**.*.*....\n....*...*....\n.......*.....\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n\nGeneration = 7, Population = 18.\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n....*..***...\n...**...**...\n....*...*....\n...**...**...\n...***..*....\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n\nGeneration = 8, Population = 18.\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n........*....\n...**..*.*...\n...***.......\n.....*.*.....\n.......***...\n...*.*..**...\n....*........\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n\nGeneration = 9, Population = 16.\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n........*....\n...*.*..*....\n...*.*..*....\n.....*.*.....\n....*..*.*...\n....*..*.*...\n....*........\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n\nGeneration = 10, Population = 14.\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.......***...\n.....*.**....\n.....*.*.....\n....**.*.....\n...***.......\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n\nGeneration = 11, Population = 12.\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n........*....\n......**.*...\n.........*...\n.....*.*.....\n...*.........\n...*.**......\n....*........\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n\nGeneration = 12, Population = 10.\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n.......**....\n.......*.*...\n.......*.....\n.............\n.....*.......\n...*.*.......\n....**.......\n.............\n.............\n.............\n.............\n.............\n.............\n.............\n\n");
}

TEST(LIFE, l_5) {
	string grid =
    "ConwayCell\n21\n13\n12\n1\n.............\n.............\n.............\n.............\n.....***.....\n.............\n.............\n.............\n....*****....\n.......*.....\n......*......\n.....*.......\n....*****....\n.............\n.............\n.............\n.............\n....****.....\n.....**......\n.....**......\n.............\n";

    istringstream sin(grid);
    Life<Cell> life;

    ostringstream sout;

    life.go(sin, sout);

    ASSERT_EQ(sout.str(), 
    "*** Life<ConwayCell> 21x13 ***\n\nGeneration = 0, Population = 24.\n.............\n.............\n.............\n.............\n.....***.....\n.............\n.............\n.............\n....*****....\n.......*.....\n......*......\n.....*.......\n....*****....\n.............\n.............\n.............\n.............\n....****.....\n.....**......\n.....**......\n.............\n\nGeneration = 1, Population = 26.\n.............\n.............\n.............\n......*......\n......*......\n......*......\n.............\n.....***.....\n.....****....\n........*....\n......*......\n....*........\n....****.....\n.....***.....\n.............\n.............\n.....**......\n....*..*.....\n.............\n.....**......\n.............\n\nGeneration = 2, Population = 24.\n.............\n.............\n.............\n.............\n.....***.....\n.............\n.....*.*.....\n.....*..*....\n.....*..*....\n.....*..*....\n.............\n....*..*.....\n....*..*.....\n....*..*.....\n......*......\n.............\n.....**......\n.....**......\n.....**......\n.............\n.............\n\nGeneration = 3, Population = 32.\n.............\n.............\n.............\n......*......\n......*......\n.....*.*.....\n......*......\n....**.**....\n....******...\n.............\n.............\n.............\n...******....\n.....***.....\n.............\n.....**......\n.....**......\n....*..*.....\n.....**......\n.............\n.............\n\nGeneration = 4, Population = 31.\n.............\n.............\n.............\n.............\n.....***.....\n.....*.*.....\n....*...*....\n....*....*...\n....*....*...\n.....****....\n.............\n....****.....\n....*...*....\n........*....\n.......*.....\n.....**......\n....*..*.....\n....*..*.....\n.....**......\n.............\n.............\n\nGeneration = 5, Population = 45.\n.............\n.............\n.............\n......*......\n.....*.*.....\n....**.**....\n....**..*....\n...***..**...\n....*.**.*...\n.....****....\n....*...*....\n....****.....\n....*.*.*....\n.......**....\n......**.....\n.....***.....\n....*..*.....\n....*..*.....\n.....**......\n.............\n.............\n\nGeneration = 6, Population = 33.\n.............\n.............\n.............\n......*......\n....**.**....\n.......**....\n.............\n...*.....*...\n...*.....*...\n....*....*...\n....*...*....\n...**.*.*....\n....*...*....\n.....*..*....\n.....*.......\n.....*..*....\n....*..**....\n....*..*.....\n.....**......\n.............\n.............\n\nGeneration = 7, Population = 50.\n.............\n.............\n.............\n.....***.....\n.....*..*....\n......***....\n........*....\n.............\n...**...***..\n...**...**...\n....*..***...\n...**...**...\n...**...**...\n....**.......\n....***......\n....*****....\n....*****....\n....*..**....\n.....**......\n.............\n.............\n\nGeneration = 8, Population = 34.\n.............\n.............\n......*......\n.....***.....\n.....*..*....\n......*.**...\n........*....\n........*....\n...**...*.*..\n.....*.......\n.....*.*..*..\n.....*....*..\n........**...\n......*......\n...*.........\n...*....*....\n...*.....*...\n....*...*....\n.....***.....\n.............\n.............\n\nGeneration = 9, Population = 40.\n.............\n.............\n.....***.....\n.....*.*.....\n.....*..**...\n........**...\n........*....\n.......**....\n....*....*...\n.....**..*...\n....**.......\n......*.*.*..\n.........*...\n.............\n.............\n..***........\n...**...**...\n....*****....\n.....***.....\n......*......\n.............\n\nGeneration = 10, Population = 38.\n.............\n......*......\n.....*.*.....\n....**.*.....\n......**.*...\n.......*.....\n.............\n.......***...\n.....***.*...\n......*......\n....*..*.*...\n.....*...*...\n.........*...\n.............\n...*.........\n..*.*........\n..*...*.**...\n...*.....*...\n....*...*....\n.....***.....\n.............\n\nGeneration = 11, Population = 39.\n.............\n......*......\n....**.*.....\n....**.*.....\n.....*.*.....\n......***....\n.......*.....\n.......*.*...\n.....*...*...\n.............\n.....**.*....\n.........**..\n.............\n.............\n...*.........\n..*..........\n..*.....**...\n...*...*.*...\n....*****....\n.....***.....\n......*......\n\nGeneration = 12, Population = 31.\n.............\n.....**......\n....*..*.....\n.......**....\n....**.......\n........*....\n.............\n......*......\n........*....\n.....**......\n.........*...\n.........*...\n.............\n.............\n.............\n..**.........\n..**....**...\n...***...*...\n....*........\n....*...*....\n.....***.....\n\n");
}

TEST(LIFE, l_6) {
	string grid =
    "ConwayCell\n20\n29\n28\n4\n.............................\n.............................\n.............................\n...**........................\n...*.......***......****.....\n.............................\n.............................\n.............................\n.............................\n.............................\n.............................\n....*......*.........*.......\n....**.....***......***......\n.....*.......................\n.............................\n.............................\n.............................\n.............................\n.............................\n.............................\n";

    istringstream sin(grid);
    Life<Cell> life;

    ostringstream sout;

    life.go(sin, sout);

    ASSERT_EQ(sout.str(), 
    "*** Life<ConwayCell> 20x29 ***\n\nGeneration = 0, Population = 22.\n.............................\n.............................\n.............................\n...**........................\n...*.......***......****.....\n.............................\n.............................\n.............................\n.............................\n.............................\n.............................\n....*......*.........*.......\n....**.....***......***......\n.....*.......................\n.............................\n.............................\n.............................\n.............................\n.............................\n.............................\n\nGeneration = 4, Population = 33.\n.............................\n.............................\n.............................\n...**................**......\n...**......***......*..*.....\n.....................**......\n.............................\n.............................\n.............................\n.............................\n.............................\n....**.....**.......***......\n...*..*...*..*......*.*......\n....**.....**.......***......\n.............................\n.............................\n.............................\n.............................\n.............................\n.............................\n\nGeneration = 8, Population = 45.\n.............................\n.............................\n.............................\n...**................**......\n...**......***......*..*.....\n.....................**......\n.............................\n.............................\n.............................\n.....................*.......\n....................***......\n....**.....**......*.*.*.....\n...*..*...*..*....***.***....\n....**.....**......*.*.*.....\n....................***......\n.....................*.......\n.............................\n.............................\n.............................\n.............................\n\nGeneration = 12, Population = 37.\n.............................\n.............................\n.............................\n...**................**......\n...**......***......*..*.....\n.....................**......\n.............................\n.............................\n.....................*.......\n.....................*.......\n.....................*.......\n....**.....**................\n...*..*...*..*...***...***...\n....**.....**................\n.....................*.......\n.....................*.......\n.....................*.......\n.............................\n.............................\n.............................\n\nGeneration = 16, Population = 37.\n.............................\n.............................\n.............................\n...**................**......\n...**......***......*..*.....\n.....................**......\n.............................\n.............................\n.....................*.......\n.....................*.......\n.....................*.......\n....**.....**................\n...*..*...*..*...***...***...\n....**.....**................\n.....................*.......\n.....................*.......\n.....................*.......\n.............................\n.............................\n.............................\n\nGeneration = 20, Population = 37.\n.............................\n.............................\n.............................\n...**................**......\n...**......***......*..*.....\n.....................**......\n.............................\n.............................\n.....................*.......\n.....................*.......\n.....................*.......\n....**.....**................\n...*..*...*..*...***...***...\n....**.....**................\n.....................*.......\n.....................*.......\n.....................*.......\n.............................\n.............................\n.............................\n\nGeneration = 24, Population = 37.\n.............................\n.............................\n.............................\n...**................**......\n...**......***......*..*.....\n.....................**......\n.............................\n.............................\n.....................*.......\n.....................*.......\n.....................*.......\n....**.....**................\n...*..*...*..*...***...***...\n....**.....**................\n.....................*.......\n.....................*.......\n.....................*.......\n.............................\n.............................\n.............................\n\nGeneration = 28, Population = 37.\n.............................\n.............................\n.............................\n...**................**......\n...**......***......*..*.....\n.....................**......\n.............................\n.............................\n.....................*.......\n.....................*.......\n.....................*.......\n....**.....**................\n...*..*...*..*...***...***...\n....**.....**................\n.....................*.......\n.....................*.......\n.....................*.......\n.............................\n.............................\n.............................\n\n");
}

TEST(LIFE, l_7) {
	string grid = "ConwayCell\n3\n3\n1\n1\n*..\n..*\n.*.\n";

	istringstream sin(grid);
	Life<Cell> life;

	ostringstream sout;

	life.go(sin, sout);

	ASSERT_EQ(sout.str(), "*** Life<ConwayCell> 3x3 ***\n\nGeneration = 0, Population = 3.\n*..\n..*\n.*.\n\nGeneration = 1, Population = 1.\n...\n.*.\n...\n\n");
}

TEST(LIFE, l_8) {
	string grid = "ConwayCell\n3\n3\n1\n1\n***\n***\n***\n";

	istringstream sin(grid);
	Life<Cell> life;

	ostringstream sout;

	life.go(sin, sout);

	ASSERT_EQ(sout.str(), "*** Life<ConwayCell> 3x3 ***\n\nGeneration = 0, Population = 9.\n***\n***\n***\n\nGeneration = 1, Population = 4.\n*.*\n...\n*.*\n\n");
}

TEST(LIFE, l_9) {
	string grid = "FredkinCell\n3\n3\n1\n1\n---\n---\n---\n";

	istringstream sin(grid);
	Life<Cell> life;

	ostringstream sout;

	life.go(sin, sout);

	ASSERT_EQ(sout.str(), "*** Life<FredkinCell> 3x3 ***\n\nGeneration = 0, Population = 0.\n---\n---\n---\n\nGeneration = 1, Population = 0.\n---\n---\n---\n\n");
}

TEST(LIFE, l_10) {
	string grid = "FredkinCell\n3\n3\n1\n1\n000\n000\n000\n";

	istringstream sin(grid);
	Life<Cell> life;

	ostringstream sout;

	life.go(sin, sout);

	ASSERT_EQ(sout.str(), "*** Life<FredkinCell> 3x3 ***\n\nGeneration = 0, Population = 9.\n000\n000\n000\n\nGeneration = 1, Population = 4.\n-1-\n1-1\n-1-\n\n");
}

TEST(LIFE, l_12) {
	string grid = "Cell\n3\n3\n1\n1\n*..\n..*\n.*.\n";

	istringstream sin(grid);
	Life<Cell> life;

	ostringstream sout;

	life.go(sin, sout);

	ASSERT_EQ(sout.str(), "*** Life<Cell> 3x3 ***\n\nGeneration = 0, Population = 3.\n*..\n..*\n.*.\n\nGeneration = 1, Population = 1.\n...\n.*.\n...\n\n");
}

TEST(LIFE, l_13) {
	string grid = "Cell\n3\n3\n1\n1\n***\n***\n***\n";

	istringstream sin(grid);
	Life<Cell> life;

	ostringstream sout;

	life.go(sin, sout);

	ASSERT_EQ(sout.str(), "*** Life<Cell> 3x3 ***\n\nGeneration = 0, Population = 9.\n***\n***\n***\n\nGeneration = 1, Population = 4.\n*.*\n...\n*.*\n\n");
}

TEST(LIFE, l_14) {
	string grid = "Cell\n3\n3\n1\n1\n---\n---\n---\n";

	istringstream sin(grid);
	Life<Cell> life;

	ostringstream sout;

	life.go(sin, sout);

	ASSERT_EQ(sout.str(), "*** Life<Cell> 3x3 ***\n\nGeneration = 0, Population = 0.\n---\n---\n---\n\nGeneration = 1, Population = 0.\n---\n---\n---\n\n");
}

TEST(LIFE, l_15) {
	string grid = "Cell\n3\n3\n1\n1\n000\n000\n000\n";

	istringstream sin(grid);
	Life<Cell> life;

	ostringstream sout;

	life.go(sin, sout);

	ASSERT_EQ(sout.str(), "*** Life<Cell> 3x3 ***\n\nGeneration = 0, Population = 9.\n000\n000\n000\n\nGeneration = 1, Population = 4.\n-1-\n1-1\n-1-\n\n");
}

TEST(LIFE, l_16) {
	string grid = "Cell\n3\n3\n1\n1\n---\n0--\n---\n";

	istringstream sin(grid);
	Life<Cell> life;

	ostringstream sout;

	life.go(sin, sout);

	ASSERT_EQ(sout.str(), "*** Life<Cell> 3x3 ***\n\nGeneration = 0, Population = 1.\n---\n0--\n---\n\nGeneration = 1, Population = 3.\n0--\n-0-\n0--\n\n");
}

TEST(LIFE, l_17) {
	string grid = "Cell\n3\n3\n3\n1\n000\n000\n000\n";

	istringstream sin(grid);
	Life<Cell> life;

	ostringstream sout;

	life.go(sin, sout);

	ASSERT_EQ(sout.str(), "*** Life<Cell> 3x3 ***\n\nGeneration = 0, Population = 9.\n000\n000\n000\n\nGeneration = 1, Population = 4.\n-1-\n1-1\n-1-\n\nGeneration = 2, Population = 0.\n---\n---\n---\n\nGeneration = 3, Population = 0.\n---\n---\n---\n\n");
}

TEST(LIFE, iterable) {
	string grid =
    "ConwayCell\n"
    "3\n"
    "3\n"
    "3\n"
    "1\n"
    "...\n"
    ".*.\n"
    "...\n";

    istringstream sin(grid);
    Life<Cell> life;

    ostringstream sout;

    life.go(sin, sout);

    ostringstream iterated;
    for(auto& a : life)
    	for(auto& b : a)
    		iterated << b.container;

    ASSERT_EQ(iterated.str(), ".........................");
}

TEST(LIFE, indexable) {
	string grid =
    "ConwayCell\n"
    "3\n"
    "3\n"
    "3\n"
    "1\n"
    "...\n"
    ".*.\n"
    "...\n";

    istringstream sin(grid);
    Life<Cell> life;

    ostringstream sout;

    life.go(sin, sout);
	ASSERT_EQ(life.at(0,0).container->isAlive(), false);
	ASSERT_EQ(life.at(0,1).container->isAlive(), false);
	ASSERT_EQ(life.at(0,2).container->isAlive(), false);
	ASSERT_EQ(life.at(1,0).container->isAlive(), false);
	ASSERT_EQ(life.at(1,1).container->isAlive(), false);
	ASSERT_EQ(life.at(1,2).container->isAlive(), false);
	ASSERT_EQ(life.at(2,0).container->isAlive(), false);
	ASSERT_EQ(life.at(2,1).container->isAlive(), false);
	ASSERT_EQ(life.at(2,2).container->isAlive(), false);
}

TEST(LIFE, fredkin) {
	string grid =
   "FredkinCell\n20\n20\n5\n1\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n---------00---------\n---------00---------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n";

    istringstream sin(grid);
    Life<Cell> life;

    ostringstream sout;

    life.go(sin, sout);

    ASSERT_EQ(sout.str(), 
    "*** Life<FredkinCell> 20x20 ***\n\nGeneration = 0, Population = 4.\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n---------00---------\n---------00---------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n\nGeneration = 1, Population = 8.\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n---------00---------\n--------0--0--------\n--------0--0--------\n---------00---------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n\nGeneration = 2, Population = 16.\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n---------00---------\n---------11---------\n-------01--10-------\n-------01--10-------\n---------11---------\n---------00---------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n\nGeneration = 3, Population = 16.\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n---------00---------\n--------0--0--------\n-------0----0-------\n------0------0------\n------0------0------\n-------0----0-------\n--------0--0--------\n---------00---------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n\nGeneration = 4, Population = 16.\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n---------00---------\n---------11---------\n--------------------\n--------------------\n-----01------10-----\n-----01------10-----\n--------------------\n--------------------\n---------11---------\n---------00---------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n\nGeneration = 5, Population = 32.\n--------------------\n--------------------\n--------------------\n--------------------\n---------00---------\n--------0--0--------\n--------0--0--------\n---------00---------\n-----00------00-----\n----0--0----0--0----\n----0--0----0--0----\n-----00------00-----\n---------00---------\n--------0--0--------\n--------0--0--------\n---------00---------\n--------------------\n--------------------\n--------------------\n--------------------\n\n");
}

TEST(LIFE, go_exc) {
	string grid =
   "NonsenseCell\n"
    "3\n"
    "3\n"
    "3\n"
    "1\n"
    "...\n"
    ".*.\n"
    "...\n";

    istringstream sin(grid);
    ostringstream sout;

    Life<Cell> life;

    bool got_into_exc = false;
    try {
    	life.go(sin, sout);
    } catch(invalid_argument& e) {
    	// successfully caught exception
    	got_into_exc = true;
    } catch(...) {
    	ASSERT_TRUE(false);
    }
    ASSERT_TRUE(got_into_exc);
}