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

std::vector<std::shared_ptr<Animal>> Population::getPop(){
	return this->pop;
}

/*COMMENTS:
*  None
*/
void Population::createPopulation(int geneNum, int startingSize, int generation){
	ga.generatePop(pop, populationName, startingSize, geneNum, generation);
	this->generation = generation;
}

/*COMMENTS:
*  Not sure why we really need this one. Thought it might come in handy in the future. 
*  Maybe re-create the population, with new animals, without having to start all over.
*/
void Population::createPopulation(int geneNum, int startingSize, int generation, std::string name){
	ga.generatePop(pop, name, startingSize, geneNum, generation);
	this->generation = generation;
}

/*COMMENTS:
*  This was done so the driver only has to do one call instead of putting this whole thing inside a for or while loop.
*  Makes the driver look more clean.
*/
void Population::advanceGeneration(){
	ga.combination(pop, pop.size(), generation);
	ga.ranking(pop);
	ga.selection(pop);
	generation++;
}

/*COMMENTS:
*  See GAUtils popOut for an explination why this is here.
*/
void Population::outputNAnimals(int outNum){
	gau.popOut(this->pop, outNum);
}

/*COMMENTS:
*  The reason why this is here is purely abstraction. 
*  This way the driver won't have to mess with or touch the vector at all. 
*  Not sure if it's really necessary, but makes it look more clean (personal preference).
*/
Visual Population::initVisual(){
	return this->pop;
}

/*COMMENTS:
*  Just a basic size function for the caller.
*/
int Population::getPopSize(){
	return this->pop.size();
}

/*COMMENTS:
*  Still need a way to edit this or add a second ostream overload to add in another parameter so we don't have to call the popout in GAUtils.
*  If a way is found please add it below this and edit this comment accordingly.
*/
std::ostream& operator<<(std::ostream& os, const Population& pop){
	for (auto & animal : pop.pop){
		os << animal->getTag() + "  " + std::to_string(animal->getFitness()) << std::endl;
	}
	return os;
}
