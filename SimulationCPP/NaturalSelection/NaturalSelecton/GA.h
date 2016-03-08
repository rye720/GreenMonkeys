#pragma once
#ifndef GA_H
#define GA_H

#include "Math.h"
#include "GAUtils.h"
#include "Animal.h"
#include <omp.h>
#include <iostream>
#include <vector>
#include <String>
#include <memory>

class GA{

public:
	/*
	* Input: Name of animal for this Population, number of animals to generate, number of genes per animal, and starting generation.
	* Output: Vector of Animals based on the supplied fields.
	* Function: Generates the first Population of animals.
	* Notes: None
	*/
	void generatePop(std::vector<std::shared_ptr<Animal>> &pop, std::string name, int animals, int genes, int generation);

	/*
	* Input: Vector of Animals, number of Animals in the vector, and current generation.
	* Output: Modified Vector of Animals.
	* Function: Recursively combines two top ranking Animals (via fitness) untill there is 1 or less animals left in
	*            the wolfPopulation then re-adds the old and new animals back into the wolfPopulation. Also handles the mutation
	*            process of the genetic algorithm.
	* Notes: None
	*/
	void combination(std::vector<std::shared_ptr<Animal>> &pop, int animalNum, int currentGen);

	/*
	* Input: Vector of Animals.
	* Output: Modified Vector of Animals.
	* Function: Removes 1/4 of the wolfPopulation; lowest fitness is removed.
	* Notes: None
	*/
	void selection(std::vector<std::shared_ptr<Animal>> &pop);

	/*
	* Input: Vector of Floats.
	* Output: Modified Vector of Floats.
	* Function: mutates one randomly selected gene to a random value (could be better or worse).
	* Notes: None
	*/
	void mutateGenes(std::vector<float> &genes);


	/*
	* Input: Vector of Animals.
	* Output: Sorted vector of Animals in non-ascending order.
	* Function: Sorts the Vector of Animals in non-ascending order.
	* Notes: None
	*/
	void ranking(std::vector<std::shared_ptr<Animal>> &pop);

private:

};
#endif
