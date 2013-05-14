#ifndef FLOOR_H
#define FLOOR_H

#include "Person.h"
#include "FloorButton.h"

class Floor {
public:
  Floor(const int, Elevator &);
	~Floor();

	static int Floor::FLOOR1;
	static int Floor::FLOOR2;

	int getNumber(void);
	void setPerson(Person*);
	bool isBusy(void);
	void canCallElevator(void);
	void elevatorIsReadyToGetIn(void);
	//FloorButton floorbutton;
private:
	int floorNumber;
	Person *personPtr;
	Elevator &elevatorRef;
public:
	FloorButton floorbutton;

};

#endif
