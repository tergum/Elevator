#include "Bell.h"

#include <iostream>
using namespace std;

Bell::Bell()
{
  cout << "Elevator Bell was created." << endl;
}

Bell::~Bell()
{
	cout << "Elevator Bell was destroyed." << endl;
}

void Bell::ring()
{
	cout << "Elevator Bell rings!\a" << endl;
}
