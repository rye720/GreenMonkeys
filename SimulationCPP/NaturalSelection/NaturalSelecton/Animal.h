#ifndef ANIMAL_H
#define ANIMAL_H

#include <vector>

struct Animal{
private:

public:
	char sex;
	std::string species;
	std::string tag;
	float fitness;
	int generation;
	std::vector<float> genes;
	int age;
};

#endif