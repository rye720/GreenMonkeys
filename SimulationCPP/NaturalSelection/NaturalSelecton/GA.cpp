#include "GA.h"

/* COMMENTS:
*  Using shared pointers for the animals in the vector because the animals pointers will be passed around quite a bit.
*  Not using shared pointer on the vector becuase I'm just passing the reference of it. 
*  I.E. making a vector of shared pointers to animal classes.
*/
void GA::generatePop(std::vector<std::shared_ptr<Animal>> &pop, std::string name, int animals, int genes, int generation, int typeID){

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
		a->setTypeID(typeID);
		pop.push_back(std::move(a));
	}
}

/* COMMENTS:
<param>
*  The big if/else statement is to add variety to the mating (if the pop is > 10 then mate with the top 8. pop > 6 mate with top 4, etc..).
*  This whole function is not taking into account of gender's or position so it will need to be re-written once we have two seperate data structures,
*  one with males and the other with females. Also will need to take into account of proximity once we get there.
*  This also removes older animals; Maybe should move that to selection since it really isn't a part of the combination procedure.
</param>
*/
void GA::combination(std::vector<std::shared_ptr<Animal>> &pop, int animalNum, int currentGen){
	char sex;
	GAUtils gu = GAUtils();
	if (pop.size() > 1) {
		sex = gu.randSex();
		std::shared_ptr<Animal> mom, dad;
		int dRand, mRand;

		if (pop.size() >= 8) {
			dRand = gu.randIntGen(6);
			mRand = gu.randIntGen(6);
			
			dad = std::move(pop[dRand]);
			pop.erase(pop.begin() + dRand);
			mom = std::move(pop[mRand]);
			pop.erase(pop.begin() + mRand);
		}
		else if (pop.size() >= 7) {
			dRand = gu.randIntGen(5);
			mRand = gu.randIntGen(5);
			dad = std::move(pop[dRand]);
			pop.erase(pop.begin() + dRand);
			mom = std::move(pop[mRand]);
			pop.erase(pop.begin() + mRand);
		}
		else if (pop.size() >= 6) {
			dRand = gu.randIntGen(4);
			mRand = gu.randIntGen(4);
			dad = std::move(pop[dRand]);
			pop.erase(pop.begin() + dRand);
			mom = std::move(pop[mRand]);
			pop.erase(pop.begin() + mRand);
		}
		else if (pop.size() >= 5) {
			dRand = gu.randIntGen(3);
			mRand = gu.randIntGen(3);
			dad = std::move(pop[dRand]);
			pop.erase(pop.begin() + dRand);
			mom = std::move(pop[mRand]);
			pop.erase(pop.begin() + mRand);
		}
		else if (pop.size() >= 4) {
			dRand = gu.randIntGen(2);
			mRand = gu.randIntGen(2);
			dad = std::move(pop[dRand]);
			pop.erase(pop.begin() + dRand);
			mom = std::move(pop[mRand]);
			pop.erase(pop.begin() + mRand);
		}
		else if (pop.size() >= 3) {
			dRand = gu.randIntGen(1);
			mRand = gu.randIntGen(1);
			dad = std::move(pop[dRand]);
			pop.erase(pop.begin() + dRand);
			mom = std::move(pop[mRand]);
			pop.erase(pop.begin() + mRand);
		}
		else {
			dad = std::move(pop[0]);
			pop.erase(pop.begin());
			mom = std::move(pop[0]);
			pop.erase(pop.begin());
		}
		
		
		int cp = (gu.randIntGen(mom->getGeneSize()));
		std::vector <float> childGenes;

		std::vector<float> dadGenes = dad->getGenes();
		std::vector<float> momGenes = mom->getGenes();
		
		for (int i = 0; i < dadGenes.size(); i++){
			childGenes.push_back((dadGenes[i] + momGenes[i]) / 2.0); 
		}

		//for (int i = cp; i < mom->getGeneSize(); i++){
		//	childGenes.push_back(momGenes[i]);
		//}

		bool hasMutation = false;
		if (gu.randIntGen(100) <= 25) {
			mutateGenes(childGenes);
			hasMutation = true;
		}

		float fn = gu.fitnessSingle(childGenes);
		std::shared_ptr<Animal> child(new Animal(dad->getName()));
		std::string cTag;
		
		child->setFitness(fn);
		child->setGenes(childGenes);
		child->setSex(sex);
		child->setGeneration(currentGen);
		child->setTypeID(mom->getTypeID());
		child->setPosition(mom->getXPos(), mom->getYPos(), 0);
		if (hasMutation)
			cTag.append(mom->getName() + "_" + std::to_string(currentGen) + "_" + std::to_string(animalNum + 1) + "m");
		else
			cTag.append(mom->getName() + "_" + std::to_string(currentGen) + "_" + std::to_string(animalNum + 1));
		child->setTag(cTag);

		combination(pop, animalNum+1, currentGen);
		pop.push_back(std::move(mom));
		pop.push_back(std::move(dad));
		pop.push_back(std::move(child));
	}

	gu.agePopulation(pop,5);
gu.killSeniorCitizens(pop);

}

/*COMMENTS:
* Removing only 1/4 of the population. 
* Smart pointers are being used so no need to delete
*/

void GA::selection(std::vector<std::shared_ptr<Animal>> &pop){
	int size = pop.size();
	int x = (size / 4);
	size -= 1;

	for (; x > 0; size--, x--){
		pop.erase(pop.begin() + size);
	}
}

/*COMMENTS:
* Straight forware prodecure
*/
void GA::mutateGenes(std::vector<float> &genes){
	GAUtils gu = GAUtils();
	genes[gu.randIntGen(genes.size()-1)] = gu.randFloatGen(); 
}

/*COMMENTS:
* see rankPop in GAUtils
*/
void GA::ranking(std::vector<std::shared_ptr<Animal>> &pop){
	GAUtils gu = GAUtils();
	gu.rankPop(pop);
}