#include "Doors.h"

#include <iostream>
using namespace std;

Doors::Doors()
:  doorsAreOpen(false)
{
	cout << "Elevator Doors were created." << endl;
}

Doors::~Doors()
{
	cout << "Elevator Doors were created." << endl;
}

bool Doors::areOpen()
{
	return doorsAreOpen;
}

void Doors::close()
{
	doorsAreOpen = false;
	cout << "Elevator Doors are closed." << endl;

}

void Doors::open()
{
	doorsAreOpen = true;
	cout << "Elevator Doors are opened." << endl;
}
