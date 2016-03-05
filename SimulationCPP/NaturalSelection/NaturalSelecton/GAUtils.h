#pragma once
#ifndef GAUTILS_H
#define GAUTILS_H


#include "GA.h"
#include "Animal.h"
#include <time.h>
#include <random>
#include <memory>
#include <vector>
#include <algorithm>


class GAUtils{

public:
	/*
	* Input: Vector of Animals.
	* Output: Sorted vector of Animals; Ascending order.
	* Function: Sorts the vector of Animals in ascending order.
	* Notes: None
	*/
	void rankPop(std::vector<std::shared_ptr<Animal>> &pop);

	/*
	* Input: Gene vector
	* Output: Fitness value in float with a precision of 4.
	* Function: Determines the fitness value based on the genes supplied.
	* Notes: None
	*/
	float fitnessSingle(std::vector<float> &genes);

	/*
	* Input: Number of genes to generate.
	* Output: Vector of floats.
	* Function: Generates a random vector of floats. Length is based on input.
	* Notes: None
	*/
	std::vector<float> generateGenes(int &genesNum);

	/*
	* Input: None
	* Output: Chararacter M or F.
	* Function: Returns either M or F based on random number.
	* Notes: None
	*/
	char randSex();

	/*
	* Input: None
	* Output: Random float
	* Function: Returns a random float with a precision of 4.
	* Notes: Non-determinsitic number generation taken from https://msdn.microsoft.com/en-us/library/bb982398.aspx
	*/
	float randFloatGen();	

	/*
	* Input: Int upperBound.
	* Output: Random int from 0 to specified upperbound (e.g. upperBound = 7, random number from 0 to 7).
	* Funcation Summary: Returns a random integer from 0 to the supplied parameter.
	* Notes: Non-determinsitic number generation taken from https://msdn.microsoft.com/en-us/library/bb982398.aspx
	*/
	int randIntGen(int upperBound);

	/*
	* Input: Int Upperbound. Int lowerbound.
	* Output: Random int within the range specified (e.g. lowerBound = 2, upperBound = 7, output number random number from 2 to 7).
	* Funcation Summary: Returns a random integer from upperBound to lowerBound
	* Notes: Non-determinsitic number generation taken from https://msdn.microsoft.com/en-us/library/bb982398.aspx
	*/
	int randIntGen(int lowerBound, int upperBound);

	/*
	* Input: Two Animal class objects.
	* Output: Boolean; Animal1 > Animal2.
	* Function Summary: Compares animal 1 to animal 2 based on fitness.
	* Notes: None
	*/
	static bool compareAnimals(std::shared_ptr<Animal> a1,std::shared_ptr<Animal> a2);

	/*
	* Input: Animal population.
	* Output: none
	* Function Summary: Outputs the entire wolfPopulation.
	* Notes: None
	*/
	void popOut(std::vector<std::shared_ptr<Animal>> &pop);

	/*
	* Input: Animal population (vector of smart pointer Animal class objects) and number of animals to output (starting from position 1).
	* Output: none
	* Outputs wolfPopulation to supplied paramter.
	* Notes: None
	*/
	void popOut(std::vector<std::shared_ptr<Animal>> &pop, int x);

	/*
	* Input: Animal poopulation, x number of years.
	* Output: none
	* Advances each member of the Population x number of years.
	* Notes: None
	*/
	void agePopulation(std::vector<std::shared_ptr<Animal>> &pop, int x);

	/*
	* Input: Animal population.
	* Output: none
	* Kills every individual older than 23 (for now).
	* Notes: None
	*/
	void killSeniorCitizens(std::vector<std::shared_ptr<Animal>> &pop);

private:
};

#endif