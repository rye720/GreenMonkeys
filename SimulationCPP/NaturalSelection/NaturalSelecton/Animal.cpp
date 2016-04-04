#include "Animal.h"	

/*
* Input:
* Output:
* Function:
* Notes: 
*/
Animal::Animal() {
	this->species = "Random Animal";
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
Animal::Animal(std::string name){
	this->species = name;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
void Animal::setSex(char sex){
	this->sex = sex;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
void Animal::setFitness(float fitness){
	this->fitness = fitness;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
void Animal::setGeneration(int generation){
	this->generation = generation;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
void Animal::setAge(int age){
	this->age = age;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
void Animal::setGenes(std::vector<float> &genes){
	this->genes = genes;
}

/*
* Input:
* Output:
* Function:
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
* Function:
* Notes:
*/
void Animal::setXPosition(int x){
	this->position[0] = x;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
void Animal::setYPosition(int y){
	this->position[1] = y;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
void Animal::setZPosition(int z){
	this->position[2] = z;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
void Animal::setPosXOffset(int posXOffset){
	this->posXOffset = posXOffset;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
void Animal::setPosYOffset(int posYOffset){
	this->posYOffset = posYOffset;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
void Animal::setTag(std::string tag){
	this->tag = tag;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
void Animal::setTypeID(int id) {
	this->typeID = id;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
char Animal::getSex(){
	return this->sex;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
float Animal::getFitness(){
	return this->fitness;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
std::vector<float> Animal::getGenes(){
	return this->genes;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
int Animal::getGeneSize(){
	return this->genes.size();
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
std::string Animal::getName(){
	return this->species;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
std::string Animal::getTag(){
	return this->tag;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
int Animal::getTypeID() {
	return this->typeID;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
int Animal::getGeneration(){
	return this->generation;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
int Animal::getAge(){
	return this->generation;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
int Animal::getXPos(){
	return this->position[0];
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
int Animal::getYPos(){
	return this->position[1];
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
int Animal::getZPost(){
	return this->position[2];
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
int Animal::getPosXOffset(){
	return this->posXOffset;
}

/*
* Input:
* Output:
* Function:
* Notes:
*/
int Animal::getPosYOffset(){
	return this->posYOffset;
}
