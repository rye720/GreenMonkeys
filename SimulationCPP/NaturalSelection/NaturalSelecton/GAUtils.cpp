#include "GAUtils.h"

/*COMMENTS:
*  Using C++'s implemented quicksort. 
*  So far this has been working well and only causing the program to run slow on 5k+ animals.
*  May need either implement a better sorting algortihm, or see what algorithm's the BOOST library has to offer, 
*  if we can't fix the issue by balancing out the population by killing off more animals as the growth rises.
*/
void GAUtils::rankPop(std::vector<std::shared_ptr<Animal>> &pop){
	
	std::sort(pop.begin(), pop.end(), compareAnimals);
}

/*COMMENTS:
*  Very basic way to generate a fitness function.
*  Possibly want to change it in the future if we add specific attributes that account for more, 
*  such as strength, dextarity, intelligence, etc...
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

/*COMMENTS:
* Straight forward generating basic genes. Maybe need to rename function to generateRandGenes to be more clear
*/
std::vector<float> GAUtils::generateGenes(int &genesNum){
	std::vector<float> genes;
	for (int i = 0; i < genesNum; i++){
		float r = randFloatGen();
		genes.push_back(r);
	}
	return genes;
}

/*COMMENTS:
* 
*/
char GAUtils::randSex(){
	char c;
	if (randIntGen(10) > 5)
		c = 'M';
	else
		c = 'F';
	return c;
}


/*COMMENTS:
*  Using this version because it generates truly randly values via uniform distribution.
*  Tried using time and it gave the same set of data over and over again, wasn't truly "random".
*  May want to add the time random gen, as it is easier to generate the same data set over and over again for tesing purposes.
*  This does not produce the same data set if ran twice (have tested this).
*/
float GAUtils::randFloatGen(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 999);

	return (float)(dist(gen) / 1000.0);
}

/*COMMENTS:
*  See above comment.
*/
int GAUtils::randIntGen(int upperBound){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, upperBound);

	return dist(gen);
}

/*COMMENTS:
*  See above comment.
*/
int GAUtils::randIntGen(int lowerBound, int upperBound){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(lowerBound, upperBound);

	return dist(gen);
}

/*COMMENTS:
*  Used for C++'s quicksort, again may change if we use a different sorting algorithm
*/
bool GAUtils::compareAnimals(std::shared_ptr<Animal> a1, std::shared_ptr<Animal> a2) {
	return a1->getFitness() > a2->getFitness();
}

/*COMMENTS:
*  This is currently not used due to overloading the ostream on the Population class. 
*  Leaving it in here incase it has some use later on, but for now it has no use.
*/
void GAUtils::popOut(std::vector<std::shared_ptr<Animal>> &pop){
	for (auto & animal : pop){
		std::cout << animal->getTag() + "  " + std::to_string(animal->getFitness()) << std::endl;
	}
}

/*COMMENTS:
*  Currently do not know of any way to overload the ostream on the Population class to also accept an int parameter so I'm keeping this.
*/
void GAUtils::popOut(std::vector<std::shared_ptr<Animal>> &pop, int x){
	for (int i = 0; i < x; i++){
		std::cout << std::to_string((i+1))+": " +pop[i]->getTag() + "  " + std::to_string(pop[i]->getFitness()) << std::endl;
	}
}

/*COMMENTS:
*
*/
void GAUtils::agePopulation(std::vector<std::shared_ptr<Animal>> &pop, int x) {
	for (size_t i = 0; i < pop.size(); i++) {
		pop[i]->setAge(pop[i]->getAge() + x);
	}

}

/*COMMENTS:
*
*/
void GAUtils::killSeniorCitizens(std::vector<std::shared_ptr<Animal>> &pop) {
	for (size_t i = 0; i < pop.size(); i++) {
		if (pop[i]->getAge() > 23) {
			//Animal a = pop[i];
			pop.erase(pop.begin() + i);
			i--;
		}
	}

}