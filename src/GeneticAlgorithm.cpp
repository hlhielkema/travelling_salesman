//  _    _ _      _ _          _    _ _      _ _                        
// | |  | (_)    | | |        | |  | (_)    | | |                       
// | |__| |_  ___| | | _____  | |__| |_  ___| | | _____ _ __ ___   __ _ 
// |  __  | |/ _ \ | |/ / _ \ |  __  | |/ _ \ | |/ / _ \ '_ ` _ \ / _` |
// | |  | | |  __/ |   <  __/ | |  | | |  __/ |   <  __/ | | | | | (_| |
// |_|  |_|_|\___|_|_|\_\___| |_|  |_|_|\___|_|_|\_\___|_| |_| |_|\__,_|
// _____________________________________________________________________
//
// Filename: GeneticAlgorithm.cpp
// Project: AI - Travelling salesman problem
// Created: 02-07-2014 (DD-MM-YYYY)
// Changed: 02-07-2014 (DD-MM-YYYY)
//
// Author: Hielke Hielkema
// Contact: HielkeHielkema93@gmail.com
//
// (C) Hielke Hielkema - 2014

#include "stdafx.h"
#include "GeneticAlgorithm.h"

// Constructor
GeneticAlgorithm::GeneticAlgorithm(void)
{
	this->m_mutationRate = 0.015;
	this->m_tournamentSize = 5;
	this->m_elitism  = true;
}

// Evolve a population for one generation
Population * GeneticAlgorithm::evolvePopulation(Population * population)
{
	// Create the new population
	Population * newPopulation = new Population(population->getSize());

    // Keep our best individual if elitism is enabled
    int elitismOffset = 0;
    if (this->m_elitism) {
		newPopulation->setTour(0, population->getFittest());
        elitismOffset = 1;
    }

    // Crossover population
    // Loop over the new population's size and create individuals from
    // Current population
	for (int i = elitismOffset; i < newPopulation->getSize(); i++) {
        // Select parents
        Tour * parent1 = this->tournamentSelection(population);
        Tour * parent2 = this->tournamentSelection(population);
            
		// Crossover parents
        Tour * child = this->crossover(parent1, parent2);
            
		// Add child to new population
		newPopulation->setTour(i, child);
    }

    // Mutate the new population a bit to add some new genetic material
	for (int i = elitismOffset; i < newPopulation->getSize(); i++) {
        mutate(newPopulation->getTour(i));
    }

    return newPopulation;
}

// Applies crossover to a set of parents and creates offspring
Tour * GeneticAlgorithm::crossover(Tour * firstParent, Tour * secondParent)
{
	// Create new child tour
	Tour * child = new Tour(firstParent->getSize());

    // Get start and end sub tour positions for parent1's tour
    int startPos = (int)((double)rand() * firstParent->getSize() / (RAND_MAX + 1));
    int endPos = (int)((double)rand() * firstParent->getSize() / (RAND_MAX + 1));

    // Loop and add the sub tour from parent1 to our child
	for (int i = 0; i < child->getSize(); i++) {
        // If our start position is less than the end position
        if (startPos < endPos && i > startPos && i < endPos) {
            child->setCity(i, firstParent->getCity(i));
        } // If our start position is larger
        else if (startPos > endPos) {
            if (!(i < startPos && i > endPos)) {
                child->setCity(i, firstParent->getCity(i));
            }
        }
    }

    // Loop through parent2's city tour
    for (int i = 0; i < secondParent->getSize(); i++) {
        // If child doesn't have the city add it
		if (!child->contains(secondParent->getCity(i))) {
            // Loop to find a spare position in the child's tour
			for (int ii = 0; ii < child->getSize(); ii++) {
                // Spare position found, add city
                if (child->getCity(ii) == NULL) {
                    child->setCity(ii, secondParent->getCity(i));
                    break;
                }
            }
        }
    }
    return child;
}

// Mutate a tour using swap mutation
void GeneticAlgorithm::mutate(Tour * tour)
{
	// Loop through tour cities
	for(int p1=0, s = tour->getSize(); p1 < s; p1++)
	{
		// Apply mutation rate
		if ((double)rand() / (RAND_MAX + 1) < this->m_mutationRate) // random
		{
			// Get a second random position in the tour
			int p2 = (int)((double)rand() * s / (RAND_MAX + 1)); // random

			// Get the cities at target position in tour
            City * city1 = tour->getCity(p1);
            City * city2 = tour->getCity(p2);

            // Swap them around
            tour->setCity(p2, city1);
            tour->setCity(p1, city2);
		}
	}
}

// Selects candidate tour for crossover
Tour * GeneticAlgorithm::tournamentSelection(Population * population)
{
	// Create a tournament population
	Population * tournament = new Population(this->m_tournamentSize);
    // For each place in the tournament get a random candidate tour and add it
    for (int i = 0; i < this->m_tournamentSize; i++) {
		int randomId = (int)((double)rand() * population->getSize() / (RAND_MAX + 1));
		tournament->setTour(i, population->getTour(randomId));
    }
    // Get the fittest tour
    return tournament->getFittest();
}