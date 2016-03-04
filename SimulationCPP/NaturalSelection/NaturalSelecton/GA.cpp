#include "GA.h"

/*
* Input: Name of animal for this Population, number of animals to generate, number of genes per animal, and starting generation
* Output: Vector of Animals based on the supplied fields
* Funcation: Generates the first Population of animals
* Notes: None
*/
void GA::generatePop(std::vector<std::shared_ptr<Animal>> &pop, std::string name, int animals, int genes, int generation){

	for (int i = 0; i < animals; i++){
		GAUtils gu = GAUtils();
		std::shared_ptr<Animal> a(new Animal(name));
		float fitness;
		char sex = gu.randSex();

		a->setSex(sex);
		a->setGenes(gu.generateGenes(genes));
		fitness = gu.fitnessSingle(a->getGenes());
		a->setFitness(fitness);
		a->setTag(name + "_" + std::to_string(generation) + std::to_string(i));
		pop.push_back(std::move(a));
	}
}

/*
* Input: Vector of Animals, number of Animals in the vector, and current generation 
* Output: Modified Vector of Animals
* Funcation: Recursively combines two top ranking Animals (via fitness) untill there is 1 or less animals left in 
*            the wolfPopulation then re-adds the old and new animals back into the wolfPopulation. Also handles the mutation 
*            process of the genetic algorithm
* Notes: Probably a better way to do the huge if/else statement 
*/
void GA::combination(std::vector<std::shared_ptr<Animal>> &pop, int animalNum, int currentGen){
	char sex;
	GAUtils gu = GAUtils();
	if (pop.size() > 1) {
		sex = gu.randSex();
		std::shared_ptr<Animal> m, d;
		int dRand, mRand;

		if (pop.size() >= 8) {
			dRand = gu.randIntGen(6);
			mRand = gu.randIntGen(6);
			
			d = std::move(pop[dRand]);
			pop.erase(pop.begin() + dRand);
			m = std::move(pop[mRand]);
			pop.erase(pop.begin() + mRand);
		}
		else if (pop.size() >= 7) {
			dRand = gu.randIntGen(5);
			mRand = gu.randIntGen(5);
			d = std::move(pop[dRand]);
			pop.erase(pop.begin() + dRand);
			m = std::move(pop[mRand]);
			pop.erase(pop.begin() + mRand);
		}
		else if (pop.size() >= 6) {
			dRand = gu.randIntGen(4);
			mRand = gu.randIntGen(4);
			d = std::move(pop[dRand]);
			pop.erase(pop.begin() + dRand);
			m = std::move(pop[mRand]);
			pop.erase(pop.begin() + mRand);
		}
		else if (pop.size() >= 5) {
			dRand = gu.randIntGen(3);
			mRand = gu.randIntGen(3);
			d = std::move(pop[dRand]);
			pop.erase(pop.begin() + dRand);
			m = std::move(pop[mRand]);
			pop.erase(pop.begin() + mRand);
		}
		else if (pop.size() >= 4) {
			dRand = gu.randIntGen(2);
			mRand = gu.randIntGen(2);
			d = std::move(pop[dRand]);
			pop.erase(pop.begin() + dRand);
			m = std::move(pop[mRand]);
			pop.erase(pop.begin() + mRand);
		}
		else if (pop.size() >= 3) {
			dRand = gu.randIntGen(1);
			mRand = gu.randIntGen(1);
			d = std::move(pop[dRand]);
			pop.erase(pop.begin() + dRand);
			m = std::move(pop[mRand]);
			pop.erase(pop.begin() + mRand);
		}
		else {
			d = std::move(pop[0]);
			pop.erase(pop.begin());
			m = std::move(pop[0]);
			pop.erase(pop.begin());
		}
		
		
		int cp = (gu.randIntGen(m->getGeneSize()));
		std::vector <float> childGenes;

		std::vector<float> dadGenes = d->getGenes();
		std::vector<float> momGenes = m->getGenes();
		for (int i = 0; i < cp; i++){
			childGenes.push_back(dadGenes[i]); 
		}

		for (int i = cp; i < m->getGeneSize(); i++){
			childGenes.push_back(momGenes[i]);
		}

		bool hasMutation = false;
		if (gu.randIntGen(100) <= 25) {
			mutateGenes(childGenes);
			hasMutation = true;
		}

		float fn = gu.fitnessSingle(childGenes);
		std::shared_ptr<Animal> child(new Animal(d->getName()));
		std::string cTag;
		
		child->setFitness(fn);
		child->setGenes(childGenes);
		child->setSex(sex);
		child->setGeneration(currentGen);
		if (hasMutation)
			cTag.append(m->getName() + "_" + std::to_string(currentGen) + "_" + std::to_string(animalNum + 1) + "m");
		else
			cTag.append(m->getName() + "_" + std::to_string(currentGen) + "_" + std::to_string(animalNum + 1));
		child->setTag(cTag);
		combination(pop, animalNum+1, currentGen);
		pop.push_back(std::move(m));
		pop.push_back(std::move(d));
		pop.push_back(std::move(child));
	}

	gu.agePopulation(pop,5);
	gu.killSeniorCitizens(pop);

}

/*
* Input: Vector of Animals
* Output: Modified Vector of Animals
* Funcation: Removes 1/4 of the wolfPopulation; lowest fitness is removed 
* Notes: None
*/
void GA::selection(std::vector<std::shared_ptr<Animal>> &pop){
	int size = pop.size();
	int x = (size / 4);
	size -= 1;
	for (; x > 0; size--, x--){
		pop.erase(pop.begin() + size);
	}
}

/*
* Input: Vector of Floats
* Output: Modified Vector of Floats
* Funcation: mutates one randomly selected gene to a random value (could be better or worse)
* Notes: None
*/
void GA::mutateGenes(std::vector<float> &genes){
	GAUtils gu = GAUtils();
	genes[gu.randIntGen(genes.size()-1)] = gu.randFloatGen(); 
}

/*
* Input:
* Output:
* Funcation:
* Notes: This is currently not in use. Too lazy to remove
*/
void GA::mutate(float &gene){
}

/*
* Input: Vector of Animals
* Output: Sorted (based on fitness) Vector of Animals
* Funcation: Calls the function to sort the Vector
* Notes: Was trying to avoid using GUtils in the driver.
*/
void GA::ranking(std::vector<std::shared_ptr<Animal>> &pop){
	GAUtils gu = GAUtils();
	gu.rankPop(pop);
}