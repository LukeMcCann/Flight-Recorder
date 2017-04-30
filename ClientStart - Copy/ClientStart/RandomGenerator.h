#pragma once
#include <ctime>
#include <cstdlib>
#include <string>

class RandomGenerator
{
public:
	RandomGenerator(void);
	~RandomGenerator(void);

	int genRandom(int min, int max);
	std::string genRandomString(int min, int max);
};

