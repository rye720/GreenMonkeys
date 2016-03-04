#ifndef POPULATION_H
#define POPULATION_H

#include "Animal.h"
#include "GA.h"
#include "GAUtils.h"
#include <string>
#include <iostream>

class Population{
private:
	GA ga = GA();
	GAUtils gau = GAUtils();
	int generation;
protected:
	std::string populationName;
	std::vector<std::shared_ptr<Animal>> pop;

public:
	Population();
	Population(std::string popName);
	void createPopulation(int geneNum, int startingSize, int generation);
	void createPopulation(int geneNum, int startingSize, int generation, std::string name);
	void advanceGeneration();
	std::vector<std::shared_ptr<Animal>> getPopulation();
	int getPopSize();
	friend std::ostream& operator<<(std::ostream& os, const Population& pop);
	
};

#endif