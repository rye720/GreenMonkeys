#include "Animal.h"	

/*
* Input:
* Output:
* Funcation:
* Notes: 
*/
Animal::Animal() {
	this->species = "Random Animal";
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
Animal::Animal(std::string name){
	this->species = name;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
void Animal::setSex(char sex){
	this->sex = sex;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
void Animal::setFitness(float fitness){
	this->fitness = fitness;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
void Animal::setGeneration(int generation){
	this->generation = generation;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
void Animal::setAge(int age){
	this->age = age;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
void Animal::setGenes(std::vector<float> &genes){
	this->genes = genes;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
void Animal::setPosition(int x, int y, int z){
	this->position[0] = x;
	this->position[1] = y;
	this->position[2] = z;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
void Animal::setXPosition(int x){
	this->position[0] = x;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
void Animal::setYPosition(int y){
	this->position[1] = y;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
void Animal::setZPosition(int z){
	this->position[2] = z;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
void Animal::setPosXOffset(int posXOffset){
	this->posXOffset = posXOffset;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
void Animal::setPosYOffset(int posYOffset){
	this->posYOffset = posYOffset;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
void Animal::setTag(std::string tag){
	this->tag = tag;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
char Animal::getSex(){
	return this->sex;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
float Animal::getFitness(){
	return this->fitness;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
std::vector<float> Animal::getGenes(){
	return this->genes;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
int Animal::getGeneSize(){
	return this->genes.size();
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
std::string Animal::getName(){
	return this->species;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
std::string Animal::getTag(){
	return this->tag;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
int Animal::getGeneration(){
	return this->generation;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
int Animal::getAge(){
	return this->generation;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
int Animal::getXPos(){
	return this->position[0];
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
int Animal::getYPos(){
	return this->position[1];
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
int Animal::getZPost(){
	return this->position[2];
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
int Animal::getPosXOffset(){
	return this->posXOffset;
}

/*
* Input:
* Output:
* Funcation:
* Notes:
*/
int Animal::getPosYOffset(){
	return this->posYOffset;
}
