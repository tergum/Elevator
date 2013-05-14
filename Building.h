#ifndef BUILDING_H
#define BUILDING_H

#include "Elevator.h"
#include "Floor.h"
#include "Scheduler.h"
#include "Clock.h"

class Building {
public:
  Building();
	~Building();
	void runSimulation(int time);
private:
	Scheduler scheduler;
	Floor floor1;
	Floor floor2;
	Elevator elevator;
	Clock clock;
};

#endif
