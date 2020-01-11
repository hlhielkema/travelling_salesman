//  _    _ _      _ _          _    _ _      _ _                        
// | |  | (_)    | | |        | |  | (_)    | | |                       
// | |__| |_  ___| | | _____  | |__| |_  ___| | | _____ _ __ ___   __ _ 
// |  __  | |/ _ \ | |/ / _ \ |  __  | |/ _ \ | |/ / _ \ '_ ` _ \ / _` |
// | |  | | |  __/ |   <  __/ | |  | | |  __/ |   <  __/ | | | | | (_| |
// |_|  |_|_|\___|_|_|\_\___| |_|  |_|_|\___|_|_|\_\___|_| |_| |_|\__,_|
// _____________________________________________________________________
//
// Filename: Population.cpp
// Project: AI - Travelling salesman problem
// Created: 02-07-2014 (DD-MM-YYYY)
// Changed: 02-07-2014 (DD-MM-YYYY)
//
// Author: Hielke Hielkema
// Contact: HielkeHielkema93@gmail.com
//
// (C) Hielke Hielkema - 2014

#include "stdafx.h"
#include "Population.h"

// Constructor
Population::Population(int size)
{
	this->m_size = size;
	this->m_tours = new Tour*[size];
}

// Desctructor
Population::~Population(void)
{
	for(int i = 0, s = this->m_size; i < s; i++)
	{
		if (this->m_tours[i] != NULL)
			delete this->m_tours[i];
	}
	delete[] this->m_tours;
}

void Population::init(CityCollection * allCities)
{
	for(int i = 0, s = this->m_size; i < s; i++)
		this->m_tours[i] = new Tour(allCities, true);
}

// Set a tour
void Population::setTour(int index, Tour * tour) 
{
	this->m_tours[index] = tour;
}

// Get a tour
Tour * Population::getTour(int index)
{
	return this->m_tours[index];
}

// Get the fittest tour in the population
Tour * Population::getFittest()
{
	Tour * fittest = this->m_tours[0];
	for(int i = 1, s = this->m_size; i < s; i++)
	{
		if (fittest->getFitness() <= this->m_tours[i]->getFitness())
			fittest = this->m_tours[i];
	}
	return fittest;
}

// Get the population size
int Population::getSize()
{
	return this->m_size;
}