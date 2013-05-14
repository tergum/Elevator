#include "Person.h"
#include "Floor.h"
#include "Elevator.h"

#include <iostream>
using namespace std;

int Person::count = 0;

Person::Person(Floor &flr)
:  ID (++count),
	currentFloor(flr),
	sourceFloor(currentFloor.getNumber()),
	destFloor((currentFloor.getNumber() == Floor::FLOOR1)? Floor::FLOOR2 : Floor::FLOOR1)
{

	cout << "Person " << getID() 
		<< " was created on Floor " << sourceFloor << "."
		 << endl;
}

Person::~Person()
{
	cout << "Person " << getID() << " leaves Floor /was destroyed/." << endl;
}

int Person::getID(void)
{
	return ID;
}

void Person::pressFloorButton(void)
{
	cout << "Person " << this->getID() << " presses button on Floor " << currentFloor.getNumber() << "." << endl;
	currentFloor.floorbutton.pressButton();
}

void Person::getInElevator(Elevator &elevatorRef)
{
	cout << "Person " << this->getID() << " gets in Elevator on Floor " << currentFloor.getNumber() << "." << endl;
	leaveFloorFor(elevatorRef);
	pressElevatorButton(elevatorRef);
}

void Person::leaveFloorFor(Elevator &elevatorRef)
{
	currentFloor.setPerson(0);
	elevatorRef.setPerson(this);
}
void Person::pressElevatorButton(Elevator &elevatorRef)
{
	cout << "Person " << this->getID() << " presses ElevatorButton." << endl;
	elevatorRef.elevatorbutton.pressToFloor(destFloor);
}
