#include "Animal.h"	

Animal::Animal() {
	this->species = "Random Animal";
}

Animal::Animal(std::string name){
	this->species = name;
}

void Animal::setSex(char sex){
	this->sex = sex;
}

void Animal::setFitness(float fitness){
	this->fitness = fitness;
}

void Animal::setGeneration(int generation){
	this->generation = generation;
}

void Animal::setAge(int age){
	this->age = age;
}

void Animal::setGenes(std::vector<float> &genes){
	this->genes = genes;
}

void Animal::setPosition(int x, int y, int z){
	this->position[0] = x;
	this->position[1] = y;
	this->position[2] = z;
}
void Animal::setXPosition(int x){
	this->position[0] = x;
}

void Animal::setYPosition(int y){
	this->position[1] = y;
}

void Animal::setZPosition(int z){
	this->position[2] = z;
}

void Animal::setPosXOffset(int posXOffset){
	this->posXOffset = posXOffset;
}

void Animal::setPosYOffset(int posYOffset){
	this->posYOffset = posYOffset;
}

void Animal::setTag(std::string tag){
	this->tag = tag;
}

char Animal::getSex(){
	return this->sex;
}

float Animal::getFitness(){
	return this->fitness;
}

std::vector<float> Animal::getGenes(){
	return this->genes;
}

int Animal::getGeneSize(){
	return this->genes.size();
}

std::string Animal::getName(){
	return this->species;
}

std::string Animal::getTag(){
	return this->tag;
}

int Animal::getGeneration(){
	return this->generation;
}

int Animal::getAge(){
	return this->generation;
}

int Animal::getXPos(){
	return this->position[0];
}

int Animal::getYPos(){
	return this->position[1];
}

int Animal::getZPost(){
	return this->position[2];
}

int Animal::getPosXOffset(){
	return this->posXOffset;
}

int Animal::getPosYOffset(){
	return this->posYOffset;
}
