#include "Driver.h"
#undef max


int main(int argc, TCHAR *argv[]) {

	GA main = GA();
	GAUtils g = GAUtils();
	Driver d = Driver();
	std::vector<Animal> wolfPopulation, rabPopulation;
	std::string wolfName, rabName, visualConf;

	//extern char* optarg;
	//extern int optind, optopt;

	int geneNum1, animalStart1, geneNum2, animalStart2, loops, c = 0;
	TCHAR* optopt = argv[optind - 1];
	//opterr = 0;


	// command line arguments supplied:
	// wolfName, geneNum1, animalStart1

	if (argc > 1) {

		while ((c = getopt(argc, argv, "a:b:c:d:e:f:g:")) != -1) {
			switch (c) {
			case ('a') :
				wolfName = std::string(optarg);
				break;
			case ('b') :
				geneNum1 = atoi(optarg);
				break;
			case ('c') :
				animalStart1 = atoi(optarg);
				break;
			case ('d') :
				rabName = std::string(optarg);
				break;
			case ('e') :
				geneNum2 = atoi(optarg);
				break;
			case ('f') :
				animalStart2 = atoi(optarg);
				break;
			case ('g') :
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

		/*

		//TESTING GETOPT

			std::cout << "Animal Name: ";
			std::cout << wolfName;
			std::cout << std::endl;

			std::cout << "Number of genes: ";
			std::cout << geneNum1;
			std::cout << std::endl;

			std::cout << "Starting wolfPopulation ";
			std::cout << animalStart1;
			std::cout << std::endl;

			std::cout << "Animal Name: ";
			std::cout << visualConf;
			std::cout << std::endl;

		*/

		/**

		//OLD COMMAND LINE ARGUMENT PARSING

		if (argc == 5) {
			wolfName = std::string(argv[1]);
			sscanf(argv[2], "%d", (int *)&geneNum1);
			sscanf(argv[3], "%d", (int *)&animalStart1);
			visualConf = std::string(argv[4]);
		}


		**/

	}
	//no command line arguments
	else {

		std::cout << "Enter the name of the predator animal: ";
		std::cin >> wolfName;
		std::cout << std::endl;
		std::cout << "Genes per predator animal: ";
		d.defensiveInt(geneNum1);
		std::cout << std::endl;
		std::cout << "Starting predator population: ";
		d.defensiveInt(animalStart1);
		std::cout << std::endl;
		std::cout << "Enter the name of the prey animal: ";
		std::cin >> rabName;
		std::cout << std::endl;
		std::cout << "Genes per prey animal: ";
		d.defensiveInt(geneNum2);
		std::cout << std::endl;
		std::cout << "Starting prey population: ";
		d.defensiveInt(animalStart2);
		std::cout << std::endl;

		std::cout << "Visual mode: ";
		std::cin >> visualConf;

	}


	std::locale loc;
	std::transform(visualConf.begin(), visualConf.end(), visualConf.begin(), ::tolower);
	//wolfPopulation = main.generatePop(wolfName, animalStart1, geneNum1, 1);
	//rabPopulation = main.generatePop(rabName, animalStart2, geneNum2, 1);
	Population wolfpop = Population("Wolves");
	Population rabpop = Population("Rabbits");
	wolfpop.createPopulation(geneNum1, animalStart1, 1);
	//rabpop.createPopulation(geneNum2, animalStart2, 1);

	if (visualConf == "yes" || visualConf == "y") {

		//visual mode
		for (int i = 0; i < 20; i++) {
			wolfpop.advanceGeneration();
			/*main.combination(wolfPopulation, wolfPopulation.size(), i + 2);
			main.ranking(wolfPopulation);
			main.selection(wolfPopulation);

			main.combination(rabPopulation, rabPopulation.size(), i + 2);
			main.ranking(rabPopulation);
			main.selection(rabPopulation);*/

		}
		Visual v = Visual(wolfpop.getPopulation());
		v.visualSetup();

	}
	else {

		//console window mode
		std::cout << std::endl;
		std::cout << "Simulate how many generations?: ";
		d.defensiveInt(loops);

		/*Loop i < loops; loops is the number of times you iterate through it*/
		for (int i = 0; i < loops; i++) {
			wolfpop.advanceGeneration();

			/*main.combination(wolfPopulation, wolfPopulation.size(), i + 2);
			main.ranking(wolfPopulation);
			main.selection(wolfPopulation);

			main.combination(rabPopulation, rabPopulation.size(), i + 2);
			main.ranking(rabPopulation);
			main.selection(rabPopulation);*/

		}
		std::cout << std::endl;

		/*g.popOut(wolfPopulation);*/
		std::cout << "Top 10 predator individuals by gene ranking: ";
		std::cout << std::endl;
		//g.popOut(wolfpop, 10);
		std::cout << wolfpop;
		std::cout << std::endl;
		std::cout << "wolfPopulation size: " + std::to_string(wolfpop.getPopSize());
		std::cout << std::endl;
		std::cout << std::endl;

		/*std::cout << "Top 10 prey individuals by gene ranking: ";
		std::cout << std::endl;
		g.popOut(rabPopulation, 10);
		std::cout << std::endl;
		std::cout << "rabPopulation size: " + std::to_string(rabPopulation.size());
		std::cout << std::endl;*/
	}

	std::cout << std::endl;
	system("pause");
	return 0;
}

int Driver::defensiveInt(int &x) {
startover:
	while (!(std::cin >> x)) {
		std::cin.clear();
		std::cout << "Please enter an int: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	if ((x < 5) || (x > 25)) {
		std::cout << "Please enter an int between 5 and 25: ";
		goto startover;
	}
	return x;
}