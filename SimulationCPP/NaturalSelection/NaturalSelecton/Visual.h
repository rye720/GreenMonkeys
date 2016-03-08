#pragma once
#ifndef VISUAL_H
#define VISUAL_H
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <memory>
#include <omp.h>
#include <iostream>
#include "GA.h"


class Visual {
public:
	Visual();
	~Visual(); 
	Visual(std::vector<std::shared_ptr<Animal>> &incPop);
	Visual(std::vector<std::shared_ptr<Animal>> &incPop1, std::vector<std::shared_ptr<Animal>> &incPop2);

	/*
	* Input: None
	* Output: None
	* Function: Creates and registers the window class and converts the program into a windows program instead of a console program. 
	* Notes: Only public call in Visual.
	*/
	void visualSetup();
	
protected:
	HWND hWnd;
	HINSTANCE hInstance;
	HDC hDc;

private:
	/*Variables*/
	int gridWidth = 900;
	int gridHeight = 500;
	int startX, startY;
	bool firstTime = true;
	bool twoPops = false;
	std::vector<std::shared_ptr<Animal>> pop1;
	std::vector<std::shared_ptr<Animal>> pop2;
	std::vector<std::vector<std::shared_ptr<Animal>>> gridBoard;
	
	
	/*Functions*/

	/*
	* Input: None
	* Output: None
	* Function: Randomly generates the animals position offsets. The offests are used to determine which way the animal is moving by adding either +1 or -1 to the animals x and y pos. 
	*            I.E. +x, -y means it is moving in the positive x and the negative y direction so it's moving in the direction of 225 degrees.
	* Notes: None
	*/
	void animalPosUpdate(std::vector<std::shared_ptr<Animal>> pop);

	/*
	* Input: Handle to the paint device. Handle to the window to be painted on.
	* Output: Dots on the screen.
	* Function: Paints dots on the screen according to their current position.
	* Notes: This function is only called when the timer for animalPosUpdate is called.
	*/
	void paintAnimals(HDC hdc, HWND hWnd, std::vector<std::shared_ptr<Animal>> pop,std::string color);

	/*
	* Input:  Handle to the paint device. Handle to the window to be painted on.
	* Output: Initial dots on the screen
	* Function: Plots the initial animal position
	* Notes: None
	*/
	void initialPopPlot(HDC hdc, HWND hWnd, std::vector<std::shared_ptr<Animal>> pop);

	/*
	* Input: None
	* Output: Changes x and y offsets of each animal.
	* Function: Moves the x and y offets of each animal one step closer to 0. When it is 0 that means the animal is no longer moving
	* Notes: None
	*/
	void animalIncUpdate(std::vector<std::shared_ptr<Animal>> pop);

	/*
	* Input:  Handle to the window being called in the wnd proc. Message sent to the window (i.e. button clicked). First message parameter. Second message parameter.
	* Output:  None
	* Function:  Static version of window procedure (aka message handler). Dspatch msg can only call this. Cannot use any external data sets.
	* Notes: See .cpp comment for more indepth notes.
	*/
	static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	/*
	* Input: Message sent to the window. First message parameter. Second message parameter.
	* Output: None
	* Function: None static version of window procedure. Can use external data sets.
	* Notes: see .cpp comment for more indepth notes.
	*/
	LRESULT WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};


#endif