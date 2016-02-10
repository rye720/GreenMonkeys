#include "Driver.h"
#undef max


int main() {
	GA main = GA();
	GAUtils g = GAUtils();
	Driver d = Driver();
	std::vector<Animal> population;
	std::string animalName, visualConf;
	int geneNum, animalStart, loops;

	std::cout << "Enter the name of the animal: ";
	std::cin >> animalName;
	std::cout << std::endl;
	std::cout << "Genes per animal: ";
	d.defensiveInt(geneNum);
	std::cout << std::endl;
	std::cout << "Starting population: ";
	d.defensiveInt(animalStart);
	std::cout << std::endl;
	std::cout << "Visual mode: ";
	std::cin >> visualConf;
	std::locale loc;
	std::transform(visualConf.begin(), visualConf.end(), visualConf.begin(), ::tolower);
	population = main.generatePop(animalName, animalStart, geneNum, 1);

	if (visualConf == "yes" || visualConf == "y"){

		//visual mode
		for (int i = 0; i < 20; i++) {
			main.combination(population, population.size(), i + 2);
			main.ranking(population);
			main.selection(population);
		}
		Visual v = Visual(population);
		v.visualSetup();
	}
	else {

		//console window mode
		std::cout << std::endl;
		std::cout << "Simulate how many generations?: ";
		d.defensiveInt(loops);

		/*Loop i < loops; loops is the number of times you iterate through it*/
		for (int i = 0; i < loops; i++) {
			main.combination(population, population.size(), i + 2);
			main.ranking(population);
			main.selection(population);
		}
		std::cout << std::endl;

		/*g.popOut(population);*/
		std::cout << "Top 10 individuals by gene ranking: ";
		std::cout << std::endl;
		g.popOut(population, 10);
		std::cout << std::endl;
		std::cout << "Population size: " + std::to_string(population.size());
		std::cout << std::endl;
	}
	/*system("pause");*/
	return 0;
}

int Driver::defensiveInt(int &x){
startover:
	while (!(std::cin >> x)){
		std::cin.clear();
		std::cout << "Please enter an int: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
	}

	if ((x < 5) || (x > 1000)){
		std::cout << "Please enter an int between 5 and 1000: ";
		goto startover;
	}
	return x;
}