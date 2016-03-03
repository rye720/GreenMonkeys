#include "Driver.h"
#include "XGetopt.h"
#include <tchar.h>
#undef max


int main(int argc, TCHAR *argv[]) {

	GA main = GA();
	GAUtils g = GAUtils();
	Driver d = Driver();
	std::vector<Animal> population;
	std::string animalName, visualConf;

	//extern char* optarg;
	//extern int optind, optopt;

	int geneNum, animalStart, loops, c = 0;
	TCHAR* optopt = argv[optind - 1];
	//opterr = 0;
	

	// command line arguments supplied:
	// animalName, geneNum, animalStart

	while ((c = getopt(argc, argv, "a:b:c:d:")) != -1) {
		switch (c) {
		case ('a') :
			animalName = std::string(optarg);
			break;
		case ('b') :
			geneNum = atoi(optarg);
			break;
		case ('c') :
			animalStart = atoi(optarg);
			break;
		case ('d') :
			visualConf = std::string(optarg);
			break;
		case ('?') :

			//still default messages
			
			if (_tcscmp(argv[optind], _T('c') == 0))
				fprintf(stderr, "Option -%c requires an argument.\n", optopt);
			else if (isprint((int)optopt))
				fprintf(stderr, "Unknown option `-%c'.\n", optopt);
			else
				fprintf(stderr,
					"Unknown option character `\\x%x'.\n",
					optopt);
			return 1;

			std::cout << "Bad Arguments";
			std::cout << std::endl;
			break;

		default:
			abort();
		}
	}
		std::cout << "Animal Name: ";
		std::cout << animalName;
		std::cout << std::endl;

		std::cout << "Number of genes: ";
		std::cout << geneNum;
		std::cout << std::endl;

		std::cout << "Starting Population ";
		std::cout << animalStart;
		std::cout << std::endl;

		std::cout << "Animal Name: ";
		std::cout << visualConf;
		std::cout << std::endl;

	

	/**
	if (argc == 5) {
		animalName = std::string(argv[1]);
		sscanf(argv[2], "%d", (int *)&geneNum);
		sscanf(argv[3], "%d", (int *)&animalStart);
		visualConf = std::string(argv[4]);
	}
	//no command line arguments
	else {

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

	}
	**/

		std::locale loc;
		std::transform(visualConf.begin(), visualConf.end(), visualConf.begin(), ::tolower);
		population = main.generatePop(animalName, animalStart, geneNum, 1);

		if (visualConf == "yes" || visualConf == "y") {

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

	if ((x < 5) || (x > 25)){
		std::cout << "Please enter an int between 5 and 25: ";
		goto startover;
	}
	return x;
}