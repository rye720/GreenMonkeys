#pragma once
#ifndef GA_H
#define GA_H

#include "Math.h"
#include "GAUtils.h"
#include "Animal.h"
#include <iostream>
#include <vector>
#include <String>
#include <memory>

class GA{

public:
	void generatePop(std::vector<std::shared_ptr<Animal>> &pop, std::string name, int animals, int genes, int generation);
	void combination(std::vector<std::shared_ptr<Animal>> &pop, int animalNum, int currentGen);
	void selection(std::vector<std::shared_ptr<Animal>> &pop);
	void mutateGenes(std::vector<float> &genes);
	void mutate(float &gene);
	void ranking(std::vector<std::shared_ptr<Animal>> &pop);

private:

};
#endif
