#pragma once
#include "stdafx.h"
#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
}


RandomGenerator::~RandomGenerator()
{
}

/*
* <subject>
* generates a random int between
* min and max
* @param min - minimum possible value
* @param max - maximum possible value
* </subject>
*/
int RandomGenerator::genRandom(int min, int max)
{
	srand(time(0));
	return min + (rand() % (max - min +1));
}

/*
* <subject>
* generates a string consisting of
* a random character [A-Z] and a random
* int between min and max
*/
std::string RandomGenerator::genRandomString(int min, int max)
{
	srand(time(0));
	std::string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	std::string generatedStr;
	int pos = ((rand() % (str.size() - 1)));

	generatedStr += str.substr(pos, 1);

	return generatedStr + std::to_string(genRandom(min, max));
}

