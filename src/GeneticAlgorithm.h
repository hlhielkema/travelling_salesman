//  _    _ _      _ _          _    _ _      _ _                        
// | |  | (_)    | | |        | |  | (_)    | | |                       
// | |__| |_  ___| | | _____  | |__| |_  ___| | | _____ _ __ ___   __ _ 
// |  __  | |/ _ \ | |/ / _ \ |  __  | |/ _ \ | |/ / _ \ '_ ` _ \ / _` |
// | |  | | |  __/ |   <  __/ | |  | | |  __/ |   <  __/ | | | | | (_| |
// |_|  |_|_|\___|_|_|\_\___| |_|  |_|_|\___|_|_|\_\___|_| |_| |_|\__,_|
// _____________________________________________________________________
//
// Filename: GeneticAlgorithm.h
// Project: AI - Travelling salesman problem
// Created: 02-07-2014 (DD-MM-YYYY)
// Changed: 02-07-2014 (DD-MM-YYYY)
//
// Author: Hielke Hielkema
// Contact: HielkeHielkema93@gmail.com
//
// (C) Hielke Hielkema - 2014

#include "Population.h"

#pragma once
class GeneticAlgorithm
{
public:
	GeneticAlgorithm(void);

	Population * evolvePopulation(Population * population);
	Tour * crossover(Tour * firstParent, Tour * secondParent);

private:
    double m_mutationRate;
    int m_tournamentSize;
    bool m_elitism;

	void mutate(Tour * tour);
	Tour * tournamentSelection(Population * population);
};

