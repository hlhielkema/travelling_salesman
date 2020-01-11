//  _    _ _      _ _          _    _ _      _ _                        
// | |  | (_)    | | |        | |  | (_)    | | |                       
// | |__| |_  ___| | | _____  | |__| |_  ___| | | _____ _ __ ___   __ _ 
// |  __  | |/ _ \ | |/ / _ \ |  __  | |/ _ \ | |/ / _ \ '_ ` _ \ / _` |
// | |  | | |  __/ |   <  __/ | |  | | |  __/ |   <  __/ | | | | | (_| |
// |_|  |_|_|\___|_|_|\_\___| |_|  |_|_|\___|_|_|\_\___|_| |_| |_|\__,_|
// _____________________________________________________________________
//
// Filename: City.cpp
// Project: AI - Travelling salesman problem
// Created: 02-07-2014 (DD-MM-YYYY)
// Changed: 02-07-2014 (DD-MM-YYYY)
//
// Author: Hielke Hielkema
// Contact: HielkeHielkema93@gmail.com
//
// (C) Hielke Hielkema - 2014

#include "stdafx.h"
#include "City.h"

// Constructor
City::City(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}

// Get the x coordinate
int City::getX()
{
	return this->m_x;
}

// Get the y coordinate
int City::getY()
{
	return this->m_y;
}

// Get the distance to an other points
double City::distanceTo(City * city)
{
	int x1 = this->m_x;
	int y1 = this->m_y;
	int x2 = city->getX();
	int y2 = city->getY();
	return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

// Convert to string
string City::toString()
{
	std::ostringstream stream;
	stream << this->m_x << ", " << this->m_y;
	return stream.str();
}