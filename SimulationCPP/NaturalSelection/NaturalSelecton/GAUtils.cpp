#include "GAUtils.h"

/*
 * Have you thought about using a tool like Doxygen
 * (http://www.doxygen.nl/docblocks.html) for generating documentation from
 * your C++ code? I'm not sure what MS gives you in terms of "extract your
 * comments and turn them into documentation" but it's a good practice to
 * get into. For example, you could override the comparison operators and then
 * sorting a vector of animals would happen naturally.
 */
/*
* Input: Vector of Animals
* Output: Sorted vector of Animals; Ascending order
* Function: Sorts the vector of Animals in ascending order
* Notes: None
*/
void GAUtils::rankPop(std::vector<Animal> &pop){
	std::sort(pop.begin(), pop.end(), compareAnimals);
}

/*
* Input: Gene vector
* Output: Fitness value
* Function: Determines the fitness value based on the genes supplied
* Notes: None
*/
float GAUtils::fitnessSingle(std::vector<float> &genes){
	float total = 0.0;
	int i = 0;
	for (auto & gene : genes){
		total += gene;
		i++;
	}
	return total/(float)i;
}

/*
* Input: Number of genes to generate
* Output: Vector of floats 
* Function: Generates a random vector of floats. Length is based on input
* Notes: None
*/
std::vector<float> GAUtils::generateGenes(int &genesNum){
	std::vector<float> genes;
	for (int i = 0; i < genesNum; i++){
		float r = randFloatGen();
		genes.push_back(r);
	}
	return genes;
}

/*
* Input: None
* Output: Chararacter M or F
* Function: Returns either M or F based on random number
* Notes: None
*/
char GAUtils::randSex(){
	char c;
	std::srand(time(NULL));
	if (randIntGen(10) > 5)
		c = 'M';
	else
		c = 'F';
	return c;
}


/*
* Input: None
* Output: Random float 
* Function: Returns a random float with a precision of 4
* Notes: Non-deterministic number generation taken from https://msdn.microsoft.com/en-us/library/bb982398.aspx
*/
float GAUtils::randFloatGen(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 999);

	return (float)(dist(gen) / 1000.0);
}

/*
* Input: Upper bound on the range of random integer (e.g. upperBound = 7, random number from 0 to 7)
* Output: Random number from 0 to specified upper bound
* Function Summary: Returns a random integer from 0 to the supplied parameter
* Notes: Non-deterministic number generation taken from https://msdn.microsoft.com/en-us/library/bb982398.aspx
*/
int GAUtils::randIntGen(int upperBound){
  /*
   * It looks like you're initializing a random number generator each time,
   * which is not likely what you want. I would wrap up all the random number
   * generation stuff into a class with two constructors, one that takes a seed
   * and one that doesn't. That way if you want reproducible control flow
   * (for tracking down a bug) then you'll initialize the random number
   * with the same seed to get the same control flow. The normal case will be
   * to not seed the generator since you do want randomness in your normal runs.
   */
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, upperBound);

	return dist(gen);
}

int GAUtils::randIntGen(int lowerBound, int upperBound){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(lowerBound, upperBound);

	return dist(gen);
}

/*
 * If fitness is the only way you compare animals then if Animal overloaded
 * < and > you could get sorting by just sorting a vector containing them
 */
/*
* Input: Two animals objects
* Output: None
* Function Summary: Compares animal 1 to animal 2 based on fitness
* Notes: None
*/
bool GAUtils::compareAnimals(Animal &a1, Animal &a2){
	return a1.fitness > a2.fitness;
}

/*
* Input: Population (vector of Animal struct objects)
* Output: none
* Function Summary: Outputs the entire population
* Notes: None
*/
void GAUtils::popOut(std::vector<Animal> &pop){
	for (auto & animal : pop){
		std::cout << animal.tag + "  " + std::to_string(animal.fitness) << std::endl;
	}
}

/*
* Input: population (vector of Animal struct objects) and number of animals to output (starting from position 1)
* Output: none 
* Outputs population to supplied paramter
* Notes: None
*/
void GAUtils::popOut(std::vector<Animal> &pop, int x){
	Animal animal;
	
	for (int i = 0; i < x; i++){
		animal = pop[i];
		/*
		 * for convenience in printing, you could overload std::ostream& operator<< and return a nice stream representation of your animal.
		 */
		/*
		 * You'll probably want to line break on a particular column, but this is
		 * veering into religion. Common choices are 80 and 100. On a more general
		 * note, I would pick a style guide and make sure to stick to it. This
		 * covers method and variable naming, bracing style, line breaks, comment
		 * style, and a billion other things that help readability in large
		 * codebases. Are you using one in particular? If so, which one? It looks
		 * like you're doing visual C++ (windows-only) so if they have a style
		 * guide I would adopt it.
		 * I of course am partial to this one:
		 *   https://google.github.io/styleguide/cppguide.html
		 */
		std::cout << std::to_string((i+1))+": " +animal.tag + "  " + std::to_string(animal.fitness) << std::endl;
	}
}

/*
* Input: population (vector of Animal struct objects), x number of years
* Output: none
* Advances each member of population x number of years
* Notes: None
*/
void GAUtils::agePopulation(std::vector<Animal> &pop, int x) {
	for (int i = 0; i < pop.size(); i++) {
		pop[i].age += x;
	}
}

/*
* Input: population (vector of Animal struct objects)
* Output: none
* Kills every individual older than 23 (for now)
* Notes: None
*/
void GAUtils::killSeniorCitizens(std::vector<Animal> &pop) {
	for (int i = 0; i < pop.size(); i++) {
		if (pop[i].age > 23) {
			Animal a = pop.erase[i];
		}
	}
}
