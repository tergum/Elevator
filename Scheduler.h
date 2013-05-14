#ifndef SCHEDULER_H
#define SCHEDULER_H

class Floor;

class Scheduler {
public:
  Scheduler(Floor &, Floor &);
	~Scheduler();
	void processTime(int time);
private:
	int currentClockTime;

	Floor &floor1Ref;
	Floor &floor2Ref;

	int floor1ArrivalTime;
	int floor2ArrivalTime;

	int scheduleTime();
	void createPerson(Floor &);
};

#endif
