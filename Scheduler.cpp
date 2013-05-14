#include "Scheduler.h"
#include "Floor.h"

#include <iostream>
using namespace std;

Scheduler::Scheduler(Floor &firstFloor, Floor &secondFloor)
:  floor1Ref(firstFloor),
	floor2Ref(secondFloor),
	currentClockTime(0)
{
	cout << "Scheduler was created." << endl;

	//srand(time(0));

	//schedule 1st arrival at floor 1 and 2
	floor1ArrivalTime = scheduleTime();
	floor2ArrivalTime = scheduleTime();
}

Scheduler::~Scheduler()
{
	cout << "Scheduler was destroyed." << endl;
}

void Scheduler::processTime(int time)
{
	currentClockTime = time;

	if (currentClockTime == floor1ArrivalTime)
		if (!floor1Ref.isBusy())
			createPerson(floor1Ref);
		else
			floor1ArrivalTime++;
	if (currentClockTime == floor2ArrivalTime)
		if (!floor2Ref.isBusy())
			createPerson(floor2Ref);
		else
			floor2ArrivalTime++;
}

int Scheduler::scheduleTime()
{
	return currentClockTime + rand()%15 + 6;
}

void Scheduler::createPerson(Floor &flr)
{
	Person *newPersonPtr = new Person(flr);
	flr.setPerson(newPersonPtr);

	if (flr.getNumber() == Floor::FLOOR1)
		floor1ArrivalTime = scheduleTime();
	else
		floor2ArrivalTime = scheduleTime();
}

