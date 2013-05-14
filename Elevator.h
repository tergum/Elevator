#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Floor.h"
#include "Person.h"
#include "Doors.h"
#include "Bell.h"
#include "ElevatorButton.h"


class Elevator {
public:
  Elevator(Floor &, Floor &);
	~Elevator();

	void processTime(int time);
	void comeGetMe(int flrNmbr);
	void move(int t);
	void setPerson(Person *);

	ElevatorButton elevatorbutton;
private:
	bool moving;
	int movingDirection;
	int currentTime;
	int arrivalTime;

	static const int tripTime;

	int currentFloor;
	int destFloor;
	Floor &floor1;
	Floor &floor2;

	Person *personPtr;
	Bell bell;
	Doors doors;

	void prepareToLeaveFor(int floorNumber);
	void prepareToArrive(void);
};

#endif
