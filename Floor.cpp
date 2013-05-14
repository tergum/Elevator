#include "Floor.h"

#include <iostream>
using namespace std;

int Floor::FLOOR1 = 1;
int Floor::FLOOR2 = 2;

Floor::Floor(const int floorLevel, Elevator &elvtrRef)
:  floorNumber(floorLevel),
	personPtr(0),
	elevatorRef(elvtrRef),
	floorbutton(*this, elvtrRef)
{
	cout << "Floor " << getNumber() << " was created." << endl;

}
Floor::~Floor()
{
	cout << "Floor " << getNumber() << " was created." << endl;
}

int Floor::getNumber(void)
{
	return floorNumber;
}

void Floor::setPerson(Person* newPersonPtr)
{
	personPtr = newPersonPtr;
}

bool Floor::isBusy(void)
{
	return (personPtr == 0)? false : true;
}

void Floor::canCallElevator()
{
	if (isBusy())
		personPtr->pressFloorButton();		
}

void Floor::elevatorIsReadyToGetIn()
{
	personPtr->getInElevator(elevatorRef);
}
