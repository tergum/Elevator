#include "Clock.h"

#include <iostream>
using namespace std;

Clock::Clock()
: time(0)
{
  cout << "Clock was created." << endl;
}
Clock::~Clock()
{
	cout << "Clock was destroyed." << endl;
}
int Clock::getTime(void)
{
	return time;
}

void Clock::tick(void)
{
	time++;
}
