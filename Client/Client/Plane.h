#pragma once
#include <string>
#include "RandomGenerator.h"

class Plane
{
public:
	Plane(void);
	Plane(std::string id, std::string destination, double maxS, double minS);
	~Plane(void);

	std::string getid(void);

	double getMaxSpeed(void);
	double getMinSpeed(void);

	void setMaxSpeed(double _max);
	void setMinSpeed(double _min);

private:
	std::string destination, id;
	double MAX_SAFE_SPEED, MIN_SAFE_SPEED;

	RandomGenerator* r;
};

