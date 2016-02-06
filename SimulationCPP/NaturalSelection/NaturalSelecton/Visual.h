#pragma once
#ifndef VISUAL_H
#define VISUAL_H
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <memory>
#include <iostream>
#include "GA.h"


class Visual {
public:
    Visual(std::vector<Animal> &incPop);
	void visualSetup();

private:
    std::vector<Animal> &pop;
	static LRESULT CALLBACK WindowProcedure(HWND hWnd, unsigned int msg, WPARAM wParam, LPARAM lParam);
    void animalPosUpdate();
	void paintAnimals(HDC hdc, HWND hWnd);
};


#endif