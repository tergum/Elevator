#ifndef PERSON_H
#define PERSON_H

class Floor;
class Elevator;

class Person {
public:
  Person(Floor &);
	~Person();
	int getID(void);
	void pressFloorButton(void);
	void getInElevator(Elevator &);
private:
	static int count;
	Floor &currentFloor;
	const int ID;
	const int sourceFloor;
	const int destFloor;

	void pressElevatorButton(Elevator &);
	void leaveFloorFor(Elevator &);
};

#endif
