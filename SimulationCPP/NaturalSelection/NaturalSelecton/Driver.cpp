#include "Driver.h"
#include <string>
#include <locale>


int main() {
	GA main = GA();
	GAUtils g = GAUtils();
	std::vector<Animal> population;
	std::string animalName, visualConf;
	int geneNum, animalStart, loops;

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
	std::locale loc;
	std::transform(visualConf.begin(), visualConf.end(), visualConf.begin(), ::tolower);
	population = main.generatePop(animalName, animalStart, geneNum, 1);
	Visual v = Visual(population);

	if (visualConf == "yes" || visualConf == "y")

		//visual mode

		v.visualSetup();
	else {

		//console window mode
		std::cout << std::endl;
		std::cout << "Simulate how many generations?: ";
		std::cin >> loops;

		/*Loop i < loops; loops is the number of times you iterate through it*/
		for (int i = 0; i < loops; i++) {
			main.combination(population, population.size(), i + 2);
			main.ranking(population);
			main.selection(population);
		}
		std::cout << std::endl;

		/*g.popOut(population);*/
		std::cout << "Top 10 individuals by gene ranking: ";
		g.popOut(population, 10);
		std::cout << "Population size: " + std::to_string(population.size());
	}
	/*system("pause");*/
	return 0;
}