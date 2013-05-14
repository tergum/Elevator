#include "ElevatorButton.h"
#include "Elevator.h"

#include <iostream>
using namespace std;

ElevatorButton::ElevatorButton(Elevator &elvtrRef)
:  elevatorRef(elvtrRef),
	pressed(false)
{
	cout << "ElevatorButton was created." << endl;
}

ElevatorButton::~ElevatorButton()
{
	cout << "ElevatorButton was destroyed." << endl;
}

void ElevatorButton::pressToFloor(int floorNumber)
{
	pressed = true;
	elevatorRef.comeGetMe(floorNumber);
}

void ElevatorButton::resetButton(void)
{
	pressed = false;
}
