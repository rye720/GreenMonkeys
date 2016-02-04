#include "Driver.h"


int main() {
	GA main = GA();
	GAUtils g = GAUtils();
	Visual v = Visual();
	std::vector<Animal> population;
	std::string animalName, visualConf;
	int geneNum, animalStart;

	std::cout << "Enter the name of the animal: ";
	std::cin >> animalName;
	std::cout << std::endl;
	std::cout << "Genes per animal: ";
	std::cin >> geneNum;
	std::cout << std::endl;
	std::cout << "Starting population: ";
	std::cin >> animalStart;
	std::cout << std::endl;
	std::cout << "Visual mode: ";
	std::cin >> visualConf;
	if (visualConf == "yes" || visualConf == "y")
		v.visualSetup();
	else {
		population = main.generatePop(animalName, animalStart, geneNum, 1);


		/*Loop i < x; x is the number of times you itterate through it*/
		for (int i = 0; i < 35; i++){
			main.combination(population, population.size(), i + 2);
			main.ranking(population);
			main.selection(population);
		}

		/*g.popOut(population);*/
		g.popOut(population, 5);
		std::cout << "Population size: " + std::to_string(population.size());
	}
	/*system("pause");*/
	return 0;
}