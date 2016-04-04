#include "Population.h"

/*COMMENTS:
*  Default constructor for testing purposes.
*/
Population::Population(){
	this->populationName = "Random Animals";
}

/*COMMENTS:
*  Constructor that should be called. One above was put in for testing purposes, and may have a real use later on;
*  Possible "Demo run" on the final produce. I.E. press one button to see an example run of our program with all default inputs.
*/
Population::Population(std::string popName){
	this->populationName = popName;
}

/*COMMENTS:
*  None
*/
void Population::createPopulation(int geneNum, int startingSize, int generation, int typeID){
	std::vector<std::shared_ptr<Animal>> pop;
	ga.generatePop(pop, populationName, startingSize, geneNum, generation, typeID);
	std::tuple<std::vector<std::shared_ptr<Animal>>, int> popTuple(pop, generation);
	if (popMap.find(populationName) == popMap.end())
		popMap[populationName] = popTuple;
}

/*COMMENTS:
* This one should be used to give each population their own name and key 
* 
*/
void Population::createPopulation(int geneNum, int startingSize, int generation, std::string name, int typeID){
	std::vector<std::shared_ptr<Animal>> pop;
	ga.generatePop(pop, name, startingSize, geneNum, generation, typeID);
	std::tuple<std::vector<std::shared_ptr<Animal>>, int> popTuple(pop, generation);
	popMap[name] = popTuple;
}

/*COMMENTS:
*  This was done so the driver only has to do one call instead of putting this whole thing inside a for or while loop.
*  Makes the driver look more clean.
*/
void Population::advanceGeneration(){
//#pragma omp parallel  
	for (auto& tuple : popMap){
		ga.combination(std::get<0>(tuple.second), std::get<0>(tuple.second).size(), std::get<1>(tuple.second));
		ga.ranking(std::get<0>(tuple.second));
		ga.selection(std::get<0>(tuple.second));
		std::get<1>(tuple.second)++;
//#pragma omp barrier
	}
}

/*COMMENTS:
*  See GAUtils popOut for an explination why this is here.
*/
void Population::outputNAnimals(int outNum){
	gau.popOut(std::get<0>(popMap.begin()->second), outNum);
}

/*COMMENTS:
*  The reason why this is here is purely abstraction. 
*  This way the driver won't have to mess with or touch the vector at all. 
*  Not sure if it's really necessary, but makes it look more clean (personal preference).
*/
Visual Population::initVisual(){
	return this->popMap;
}

/*COMMENTS:
*  Just a basic size function for the caller.
*/
int Population::getPopSize(){
	return std::get<0>(popMap.begin()->second).size();
}

/*COMMENTS:
*  Still need a way to edit this or add a second ostream overload to add in another parameter so we don't have to call the popout in GAUtils.
*  If a way is found please add it below this and edit this comment accordingly.
*/
std::ostream& operator<<(std::ostream& os, const Population& pop){
	for (auto & animal : std::get<0>(pop.popMap.begin()->second)){
		os << animal->getTag() + "  " + std::to_string(animal->getFitness()) << std::endl;
	}
	return os;
}
