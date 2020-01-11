//  _    _ _      _ _          _    _ _      _ _                        
// | |  | (_)    | | |        | |  | (_)    | | |                       
// | |__| |_  ___| | | _____  | |__| |_  ___| | | _____ _ __ ___   __ _ 
// |  __  | |/ _ \ | |/ / _ \ |  __  | |/ _ \ | |/ / _ \ '_ ` _ \ / _` |
// | |  | | |  __/ |   <  __/ | |  | | |  __/ |   <  __/ | | | | | (_| |
// |_|  |_|_|\___|_|_|\_\___| |_|  |_|_|\___|_|_|\_\___|_| |_| |_|\__,_|
// _____________________________________________________________________
//
// Filename: CityCollection.cpp
// Project: AI - Travelling salesman problem
// Created: 02-07-2014 (DD-MM-YYYY)
// Changed: 02-07-2014 (DD-MM-YYYY)
//
// Author: Hielke Hielkema
// Contact: HielkeHielkema93@gmail.com
//
// (C) Hielke Hielkema - 2014

#include "stdafx.h"
#include "CityCollection.h"

// Constructor
CityCollection::CityCollection(int maxSize)
{
	this->m_maxSize = maxSize;
	this->m_size = 0;
	this->m_collection = new City*[this->m_maxSize];
}

// Destructor
CityCollection::~CityCollection(void)
{
	// Delete the indivitual cities
	for(int i = 0, s = this->m_size; i < s; i++)
		delete this->m_collection[i];

	// Delete the array
	delete[] this->m_collection;
}

// Add a city to the collection
void CityCollection::add(int x, int y) 
{
	this->m_collection[this->m_size++] = new City(x, y);
}

// Get a city from the collection
City * CityCollection::get(int index)
{
	return this->m_collection[index];
}

// Get the size of the collection
int CityCollection::getSize()
{
	return this->m_size;
}

// Get the max size of the collection
int CityCollection::getMaxSize()
{
	return this->m_maxSize;
}