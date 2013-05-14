#include "FloorButton.h"
#include "Floor.h"
#include "Elevator.h"

#include <iostream>
using namespace std;

FloorButton::FloorButton(Floor &flr, Elevator &elevator)
:  pressed(false),
	floorRef(flr),
	elevatorRef(elevator)
{
	cout << "FloorButton on Floor " << floorRef.getNumber()
		 << " was created." << endl;
}

FloorButton::~FloorButton()
{
	cout << "FloorButton on Floor " << floorRef.getNumber()
		 << " was destroyed." << endl;
}

void FloorButton::pressButton(void)
{
	pressed = true;
	elevatorRef.comeGetMe(floorRef.getNumber());
}

void FloorButton::resetButton(void)
{
	pressed = false;
}
