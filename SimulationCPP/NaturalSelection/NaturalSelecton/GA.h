#pragma once
#ifndef GA_H
#define GA_H

#include "Math.h"
#include "GAUtils.h"
#include "Animal.h"
#include <iostream>
#include <vector>
#include <String>

class GA{

public:
	std::vector<Animal> generatePop(std::string name, int animals, int genes, int generation);
	void combination(std::vector<Animal> &pop, int animalNum, int currentGen);
	void selection(std::vector<Animal> &pop);
	void mutateGenes(std::vector<float> &genes);
	void mutate(float &gene);
	void ranking(std::vector<Animal> &pop);

private:

};
#endif
