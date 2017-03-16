#pragma once
#include <ctime>
#include <cstdlib>
#include <string>

class RandomGenerator
{
public:
	RandomGenerator();
	~RandomGenerator();

	int genRandom(int min, int max);
	std::string genRandomString(int min, int max);

	double genRandomDouble(double min, double max);
};

