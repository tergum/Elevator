#ifndef ELEVATORBUTTON_H
#define ELEVATORBUTTON_H

class Elevator;

class ElevatorButton {
public:
  ElevatorButton(Elevator &);
	~ElevatorButton();

	void pressToFloor(int);
	void resetButton(void);
private:
	bool pressed;
	Elevator &elevatorRef;
};

#endif 
