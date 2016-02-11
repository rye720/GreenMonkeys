#ifndef ANIMAL_H
#define ANIMAL_H

#include <vector>

/*
 * Why a struct and not a class? It seems like you could start incorporating
 * some of the behaviors of an animal into a class rather than having the
 * logic live in various other places.
 */
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
	int position[3];
    int posXOffset = 0;
	int posYOffset = 0;

};

#endif
