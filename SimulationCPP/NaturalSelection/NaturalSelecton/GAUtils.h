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
	void rankPop(std::vector<std::shared_ptr<Animal>> &pop);
	float fitnessSingle(std::vector<float> &genes);
	std::vector<float> generateGenes(int &genesNum);
	char randSex();
	float randFloatGen();	
	int randIntGen(int upperBound);
	int randIntGen(int lowerBound, int upperBound);
	static bool compareAnimals(std::shared_ptr<Animal> a1,std::shared_ptr<Animal> a2);
	void popOut(std::vector<std::shared_ptr<Animal>> &pop);
	void popOut(std::vector<std::shared_ptr<Animal>> &pop, int x);
	void agePopulation(std::vector<std::shared_ptr<Animal>> &pop, int x);
	void killSeniorCitizens(std::vector<std::shared_ptr<Animal>> &pop);

private:
};

#endif