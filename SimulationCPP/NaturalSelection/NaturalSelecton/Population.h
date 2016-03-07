#ifndef POPULATION_H
#define POPULATION_H

#include "Animal.h"
#include "GA.h"
#include "GAUtils.h"
#include "Visual.h"
#include <string>
#include <iostream>

class Population{
private:
	/*Private Variables*/
	GA ga = GA();
	GAUtils gau = GAUtils();
protected:
	/*Protected Variables*/
	std::string populationName;
	std::vector<std::shared_ptr<Animal>> pop;
	int generation;

public:
	Population();
	Population(std::string popName);

	std::vector<std::shared_ptr<Animal>> getPop();

	/*
	* Input: Number of genes per animal. Number of animals to create . Starting generation number.
	* Output: None
	* Function: Fills the population with individual animals. Uses the name supplied in the constructor.
	* Notes: User has access to this, but not to pop. Abstraction is a great thing.
	*/
	void createPopulation(int geneNum, int startingSize, int generation);

	/*
	* Input: Number of genes per animal. Number of animals to create. Starting generation. Name of animals.
	* Output: None
	* Function: Fills the population with individual animals. Uses the name supplied in this function, instead of the constructor one.
	* Notes: User has access to this, but not to pop. Abstraction is a great thing.
	*/
	void createPopulation(int geneNum, int startingSize, int generation, std::string name);

	/*
	* Input: None
	* Output: None 
	* Function: Advances the population one generation. This creates new animals and removes old/low fitness ones.
	* Notes: This is so the driver only has to do one call to advance the generation.
	*/
	void advanceGeneration();

	/*
	* Input: Number of animals to output (highest fitness first).
	* Output: Output of N animals in command line.
	* Function: If you only want to output the top N animals, use this.
	* Notes: cout population to get a list of all animals.
	*/
	void outputNAnimals(int outNum);

	/*
	* Input: None
	* Output: Visual class declaration.
	* Function: Declares visual mode so you can run the setup and begin visualizing the population.
	* Notes: Must catch this declaration.
	*/
	Visual initVisual();



	/*
	* Input: None
	* Output: Size of the population in int.
	* Function: Returns the size of the population.
	* Notes: None.
	*/
	int getPopSize();

	/*
	* Input: See notes
	* Output: All animals in the population.
	* Function: When you cout the population it calls this. This allows us to output what we want from the data class.
	* Notes: None.
	*/
	friend std::ostream& operator<<(std::ostream& os, const Population& pop);
	
};

#endif