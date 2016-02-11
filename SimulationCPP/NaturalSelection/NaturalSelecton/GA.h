#pragma once
#ifndef GA_H
#define GA_H

#include "Math.h"
#include "GAUtils.h"
#include "Animal.h"
#include <iostream>
#include <vector>
#include <String>

/*
 * I would include a long description here of what the class is supposed
 * to do.
 * I would also name it something more descriptive like GeneticAlgorithm.
 */
class GA{

/*
 * You should indent the things contained in a class a bit, so +2 on public:
 * and private:, but that's more of a style guide convention than a rule.
 */
public:
	std::vector<Animal> generatePop(std::string name, int animals, int genes, int generation);
	/*
	 * In general it's a good idea to try to name your methods based on what they
	 * actually do, a convention you're following with generatePop but not below.
	 * I.e. use verb language rather than noun language for methods.
	 */
	void combination(std::vector<Animal> &pop, int animalNum, int currentGen);
	/*
	 * This is a style / religion, but I feel that documentation about what a
	 * method does should be in the header file, and documentation about how it
	 * does it belongs in the function, so I would move the high-level method
	 * comments here.
	 *
	 * In general, I prefer to comment on "why", not "what" when documenting
	 * how a function does what it does. For example, if I'm iterating through a
	 * string and removing all occurrences of '%' with '\%', instead of saying:
	 *   "remove all '%' and replace with '\%'
	 * I would say:
	 *   "'%' a URL-reserved character so we need to escape it here so that TextProcessor doesn't barf"
	 *
	 * In general you should assume the reader knows the language so unless it's
	 * something tricky or subtle you can avoid documenting what you are doing,
	 * but you should usually say why you're doing something because that's what's
	 * hard to infer from the code you have in front of you.
	 */
	void selection(std::vector<Animal> &pop);
	void mutateGenes(std::vector<float> &genes);
	void mutate(float &gene);
	void ranking(std::vector<Animal> &pop);

private:

};
#endif
