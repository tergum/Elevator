#ifndef CLOCK_H
#define CLOCK_H

class Clock {
public:
  Clock();
	~Clock();
	int getTime(void);
	void tick(void);
private:
	int time;
};

#endif
