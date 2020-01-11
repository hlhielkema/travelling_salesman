//  _    _ _      _ _          _    _ _      _ _                        
// | |  | (_)    | | |        | |  | (_)    | | |                       
// | |__| |_  ___| | | _____  | |__| |_  ___| | | _____ _ __ ___   __ _ 
// |  __  | |/ _ \ | |/ / _ \ |  __  | |/ _ \ | |/ / _ \ '_ ` _ \ / _` |
// | |  | | |  __/ |   <  __/ | |  | | |  __/ |   <  __/ | | | | | (_| |
// |_|  |_|_|\___|_|_|\_\___| |_|  |_|_|\___|_|_|\_\___|_| |_| |_|\__,_|
// _____________________________________________________________________
//
// Filename: Tour.h
// Project: AI - Travelling salesman problem
// Created: 02-07-2014 (DD-MM-YYYY)
// Changed: 02-07-2014 (DD-MM-YYYY)
//
// Author: Hielke Hielkema
// Contact: HielkeHielkema93@gmail.com
//
// (C) Hielke Hielkema - 2014

#include "CityCollection.h"

#pragma once
class Tour
{
public:
	Tour(int size);
	Tour(CityCollection * allCities, bool shuffle);
	~Tour(void);

	void shuffle();
	City * getCity(int index);
	void setCity(int index, City * city);
	double getFitness();
	double getDistance();
	int getSize();
	bool contains(City * city);
	string toString();

private:
	double m_fitness;
	double m_distance;
	int m_size;
	City ** m_cities;
};

