#pragma once
#include "stdafx.h"
#include "Plane.h"

Plane::Plane(void)
{
	id = r->genRandomString(1000, 2000);
	destination = "";
	MAX_SAFE_SPEED = 0.674927; // 450 knots in mach
	MIN_SAFE_SPEED = 0.749919; // 500 knots in mach
}

Plane::Plane(std::string _id, std::string _dest, double _maxS, double _minS)
{
	id = _id;
	destination = _dest;
	MAX_SAFE_SPEED = _maxS;
	MIN_SAFE_SPEED = _minS;
}

Plane::~Plane(void)
{
}

// getters and setters
std::string Plane::getid(void)
{
	return id;
}

double Plane::getMaxSpeed(void)
{
	return MAX_SAFE_SPEED;
}

double Plane::getMinSpeed(void)
{
	return MIN_SAFE_SPEED;
}

void Plane::setMaxSpeed(double _max)
{
	MAX_SAFE_SPEED = _max;
}

void Plane::setMinSpeed(double _min)
{
	MIN_SAFE_SPEED = _min;
}