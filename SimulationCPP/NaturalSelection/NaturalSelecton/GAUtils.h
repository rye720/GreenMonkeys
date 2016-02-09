#pragma once
#ifndef GAUTILS_H
#define GAUTILS_H


#include "GA.h"
#include "Animal.h"
#include <time.h>
#include <random>
#include <vector>
#include <algorithm>


class GAUtils{

public:
	void rankPop(std::vector<Animal> &pop);
	float fitnessSingle(std::vector<float> &genes);
	std::vector<float> generateGenes(int &genesNum);
	char randSex();
	float randFloatGen();	
	int randIntGen(int upperBound);
	int randIntGen(int lowerBound, int upperBound);
	static bool compareAnimals(Animal &a1, Animal &a2);
	void popOut(std::vector<Animal> &pop);
	void popOut(std::vector<Animal> &pop, int x);
	void agePopulation(std::vector<Animal> &pop, int x);
	void killSeniorCitizens(std::vector<Animal> &pop);

private:
};

#endif