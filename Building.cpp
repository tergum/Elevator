#include <iostream>
using namespace std;

#include "Building.h"

Building::Building()
:  scheduler(floor1, floor2),
	clock(),
	floor1(Floor::FLOOR1, elevator),
	floor2(Floor::FLOOR2, elevator),
	elevator(floor1, floor2)
{
	cout << "Building was created." << endl;
}

Building::~Building()
{
	cout << "Building was destroyed." << endl;
}

void Building::runSimulation(int simulationTime)
{
	int currentTime = 0;

	while (currentTime < simulationTime)
	{
		clock.tick();
		currentTime = clock.getTime();
		cout << "Time: " << currentTime << "." << endl;
		scheduler.processTime(currentTime);
		elevator.processTime(currentTime);
		cin.get();
	}

}
