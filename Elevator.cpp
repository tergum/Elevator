#include "Elevator.h"
#include "Floor.h"

#include <iostream>
using namespace std;

const int Elevator::tripTime = 5;
const int UP = 1;
const int DOWN = 2;
const int NO = 3;


Elevator::Elevator(Floor &flr1, Floor &flr2)
:  currentFloor(flr1.getNumber()),
	destFloor(flr1.getNumber()),
	floor1(flr1),
	floor2(flr2),
	personPtr(0),
	moving(false),
	doors(),
	bell(),
	currentTime(0),
	arrivalTime(0),
	movingDirection(NO),
	elevatorbutton(*this)
{
	cout << "Elevator was created." << endl;
}

Elevator::~Elevator()
{
	cout << "Elevator was destroyed." << endl;
}

void Elevator::processTime(int time)
{
	currentTime = time;

	if (moving)
		move(currentTime);
	if (!moving)
		floor1.canCallElevator();
	if (!moving)
		floor2.canCallElevator();
	if (!moving)
		cout << "Elevator rests on Floor " << currentFloor << "." << endl;
}

void Elevator::comeGetMe(int flrNmbr)
{
	prepareToLeaveFor(flrNmbr);
}

void Elevator::prepareToLeaveFor(int flrNumber)
{
	destFloor = flrNumber;

	if (destFloor != currentFloor)
	{
		if (doors.areOpen())
		{
			bell.ring();
			doors.close();
		}
		/*
		if (light.isTurnOn())
			light.turnOff();
		*/
		movingDirection = (destFloor == Floor::FLOOR1)? DOWN : UP;
		moving = true;
		arrivalTime = currentTime + tripTime;
		move(currentTime);
	} else {
		prepareToArrive();
	}
}

void Elevator::prepareToArrive()
{
	currentFloor = destFloor;
	bell.ring();
	doors.open();

	Floor &thisFloor = (currentFloor == Floor::FLOOR1)? floor1 : floor2;
	thisFloor.floorbutton.resetButton();

	if (personPtr != 0)
	{
		cout << "Person " << personPtr->getID() << " gets out on Floor " 
			 << thisFloor.getNumber() << "." << endl;
		delete personPtr;
	}

	moving = 0;
	movingDirection = NO;

	if (thisFloor.isBusy())
	{
		thisFloor.elevatorIsReadyToGetIn();
	}
	else
	{
		bell.ring();
		doors.close();
		personPtr = NULL;
	}
}

void Elevator::move(int time)
{
	currentTime = time;

	if (currentTime < arrivalTime)
	{
		cout << "Elevator is moving" << ((movingDirection == UP)? " UP " : " DOWN ")
			 << "from Floor " << currentFloor 
			 << " to Floor " << destFloor  << "." << endl;
		if (personPtr == 0)
			cout << "Noone inside." << endl;
		else
			cout << "Person " << personPtr->getID() << " inside." << endl;
	} else {
		prepareToArrive();
	}
}

void Elevator::setPerson(Person *nextPersonPtr)
{
	personPtr = nextPersonPtr;
}
