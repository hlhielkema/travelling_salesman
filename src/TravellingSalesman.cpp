//  _    _ _      _ _          _    _ _      _ _                        
// | |  | (_)    | | |        | |  | (_)    | | |                       
// | |__| |_  ___| | | _____  | |__| |_  ___| | | _____ _ __ ___   __ _ 
// |  __  | |/ _ \ | |/ / _ \ |  __  | |/ _ \ | |/ / _ \ '_ ` _ \ / _` |
// | |  | | |  __/ |   <  __/ | |  | | |  __/ |   <  __/ | | | | | (_| |
// |_|  |_|_|\___|_|_|\_\___| |_|  |_|_|\___|_|_|\_\___|_| |_| |_|\__,_|
// _____________________________________________________________________
//
// Filename: TravellingSalesman.cpp
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
#include "GeneticAlgorithm.h"
#include "Tour.h"

int _tmain(int argc, _TCHAR* argv[])
{
	// Credits
	cout << "Traveling salesman - By Hielke Hielkema" << endl;
	cout << "(C)Hielke Hielkema - 2014" << endl;

	// Set random seed
	srand (time(NULL));

	// Initialize the city collection
	CityCollection * allCities = new CityCollection(20);
	allCities->add(60, 200);
	allCities->add(180, 200);
	allCities->add(80, 180);
	allCities->add(140, 180);
	allCities->add(20, 160);
	allCities->add(100, 160);
	allCities->add(200, 160);
	allCities->add(140, 140);
	allCities->add(40, 120);
	allCities->add(100, 120);
	allCities->add(180, 100);
	allCities->add(60, 80);
	allCities->add(120, 80);
	allCities->add(180, 60);
	allCities->add(20, 40);
	allCities->add(100, 40);
	allCities->add(200, 40);
	allCities->add(20, 20);
	allCities->add(60, 20);
	allCities->add(160, 20);

	// Inialize population
	Population * pop = new Population(50);
	pop->init(allCities);
	cout << "Initial distance: " << pop->getFittest()->getDistance() << endl;

	GeneticAlgorithm * geneticAlgorithm = new GeneticAlgorithm();
	for (int i = 0; i < 100; i++) {
        pop = geneticAlgorithm->evolvePopulation(pop);
    }

	// Print the final distance and solution
	cout << "Final distance: " << pop->getFittest()->getDistance() << endl;
	cout << "Solution: " << pop->getFittest()->toString() << endl;

	// Delete resources
	delete pop;
	delete allCities;

	// Pause
	int pause;
	std::cin >> pause;

	// No errors
	return 0;
}

