#ifndef FLOORBUTTON_H
#define FLOORBUTTON_H

class Elevator;
class Floor;

class FloorButton {
public:
  FloorButton(Floor &, Elevator &);
	~FloorButton();

	void pressButton(void);
	void resetButton(void);
private:
	bool pressed;

	Floor &floorRef;
	Elevator &elevatorRef;
};

#endif 
