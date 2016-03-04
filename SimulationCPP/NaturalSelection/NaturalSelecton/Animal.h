#ifndef ANIMAL_H
#define ANIMAL_H

#include <vector>
#include <string>

class Animal{
private:
	/*Variables*/
	char sex;
	std::string species;
	std::string tag;
	float fitness;
	int generation;
	std::vector<float> genes;
	int age;
	int position[3];
	int posXOffset = 0;
	int posYOffset = 0;

public:
	Animal();
	Animal(std::string name);
	void setSex(char sex);
	void setFitness(float fitness); 
	void setGeneration(int generation);
	void setAge(int ge);
	void setGenes(std::vector<float> &genes);
	void setPosition(int x, int y, int z);
	void setXPosition(int x);
	void setYPosition(int y);
	void setZPosition(int z);
	void setPosXOffset(int posXOffset);
	void setPosYOffset(int posYOffset);
	void setTag(std::string tag);
	char getSex();
	float getFitness();
	std::vector<float> getGenes();
	int getGeneSize(); 
	std::string getName();
	std::string getTag();
	int getGeneration();
	int getAge();
	int getXPos();
	int getYPos();
	int getZPost();
	int getPosXOffset();
	int getPosYOffset();
};

#endif