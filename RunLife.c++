/** @file RunLife.c++
 *  @brief includes the main()
 *   
 * It creates a Life of cells and let them evolve over a certain number of evolutions.
 */

// --------
// includes
// --------
#include <iostream>
#include <string>
#include "Life.h"

using namespace std;

int main() {
	string line;
	while (cin) {
		Life<Cell> l;
		l.go(cin, cout);
		getline(cin, line);
	}
	return 0;
}