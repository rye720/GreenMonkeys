#include "Population.h"

Population::Population(){
	this->populationName = "Random Animals";
}

Population::Population(std::string popName){
	this->populationName = popName;
}

void Population::createPopulation(int geneNum, int startingSize, int generation){
	ga.generatePop(pop, populationName, startingSize, geneNum, generation);
	this->generation = generation;
}

void Population::createPopulation(int geneNum, int startingSize, int generation, std::string name){
	ga.generatePop(pop, name, startingSize, geneNum, generation);
	this->generation = generation;
}

void Population::advanceGeneration(){
	ga.combination(pop, pop.size(), generation);
	ga.ranking(pop);
	ga.selection(pop);
	generation++;
}

std::vector<std::shared_ptr<Animal>> Population::getPopulation(){
	return this->pop;
}

int Population::getPopSize(){
	return this->pop.size();
}

std::ostream& operator<<(std::ostream& os, const Population& pop){
	for (auto & animal : pop.pop){
		os << animal->getTag() + "  " + std::to_string(animal->getFitness()) << std::endl;
	}
	return os;
}
