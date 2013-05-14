#ifndef DOORS_H
#define DOORS_H

class Doors {
public:
  Doors();
	~Doors();
	void close(void);
	void open(void);
	bool areOpen(void);
private:
	bool doorsAreOpen;
};

#endif
