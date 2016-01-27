#include "Driver.h"


int main() {
	GA main = GA();
	GAUtils g = GAUtils();
	std::vector<Animal> population;
	population = main.generatePop("bear", 5, 5, 1);

	for (int i = 0; i < 35; i++){
		main.combination(population, population.size(), i + 2);
		main.ranking(population);
		main.selection(population); 
	}
	
	/*g.popOut(population);*/
	g.popOut(population, 5);
	std::cout << "Population size: " + std::to_string(population.size());
	
	/*system("pause");*/
	return 0;
}