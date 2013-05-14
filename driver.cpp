#include "Building.h"

#include <iostream>
using namespace std;

int main(void)
{
  Building building;
	int duration;

	cout << "Enter duration: ";
	duration = 300;
	cout << endl << endl << "\t\t\t***SIMULATION STARTS***" << endl << endl;
	building.runSimulation(duration);
	cout << endl << endl << "\t\t\t***SIMULATION ENDS***" << endl;
	return 0;
}
