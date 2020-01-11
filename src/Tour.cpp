//  _    _ _      _ _          _    _ _      _ _                        
// | |  | (_)    | | |        | |  | (_)    | | |                       
// | |__| |_  ___| | | _____  | |__| |_  ___| | | _____ _ __ ___   __ _ 
// |  __  | |/ _ \ | |/ / _ \ |  __  | |/ _ \ | |/ / _ \ '_ ` _ \ / _` |
// | |  | | |  __/ |   <  __/ | |  | | |  __/ |   <  __/ | | | | | (_| |
// |_|  |_|_|\___|_|_|\_\___| |_|  |_|_|\___|_|_|\_\___|_| |_| |_|\__,_|
// _____________________________________________________________________
//
// Filename: Tour.cpp
// Project: AI - Travelling salesman problem
// Created: 02-07-2014 (DD-MM-YYYY)
// Changed: 02-07-2014 (DD-MM-YYYY)
//
// Author: Hielke Hielkema
// Contact: HielkeHielkema93@gmail.com
//
// (C) Hielke Hielkema - 2014

#include "stdafx.h"
#include "Tour.h"
#include <algorithm>

// Constructor
Tour::Tour(int size)
{
	this->m_fitness = 0;
	this->m_distance = 0;
	this->m_size = size;
	this->m_cities = new City*[this->m_size];
	for(int i = 0, s = this->m_size; i < s; i++)
		this->m_cities[i] = NULL;
}

// Constructor
Tour::Tour(CityCollection * allCities, bool shuffle)
{
	this->m_fitness = 0;
	this->m_distance = 0;
	this->m_size = allCities->getSize();
	this->m_cities = new City*[this->m_size];
	for(int i = 0, s = this->m_size; i < s; i++)
		this->m_cities[i] = allCities->get(i);
	if (shuffle)
		this->shuffle();
}

// Destructor
Tour::~Tour(void)
{
	delete[] this->m_cities;
}

// Shuffle the cities in the tour
void Tour::shuffle()
{
	random_shuffle(&this->m_cities[0], &this->m_cities[this->m_size]);
	this->m_fitness = 0;
	this->m_distance = 0;
}

// Get a city from the tour with a given index
City * Tour::getCity(int index)
{
	return this->m_cities[index];
}

// Set a city for the position at a given index
void Tour::setCity(int index, City * city)
{
	this->m_cities[index] = city;
	this->m_fitness = 0;
	this->m_distance = 0;
}

// Get the fitness of the tour
double Tour::getFitness()
{
	if (this->m_fitness == 0)
		this->m_fitness = 1 / this->getDistance();
	return this->m_fitness;
}

// Get the total distance of the tour
double Tour::getDistance()
{
	if (this->m_distance == 0)
	{
		double distance = 0;
		for(int i = 0, s = this->m_size; i < s; i++) {
			distance += this->m_cities[i]->distanceTo(this->m_cities[(i == s - 1) ? 0:(i + 1)]);
		}
		this->m_distance = distance;
	}
	return this->m_distance;
}

// Get the size of the tour
int Tour::getSize()
{
	return this->m_size;
}

// Get if the tour contains a city
bool Tour::contains(City * city)
{
	// Search for the city in the list 
	// (a search for the same pointer because the cities get allocated one time)
	for(int i = 0, s = this->m_size; i < s; i++)
	{
		if (this->m_cities[i] == city)
			// City found
			return true;
	}
	// City not found
	return false;
}

// Convert to string
string Tour::toString()
{
	std::ostringstream stream;
	stream << '|';
	for(int i = 0, s = this->m_size; i < s; i++)
		stream << this->m_cities[i]->toString() << '|';
	return stream.str();
}