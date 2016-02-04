#pragma once
#ifndef VISUAL_H
#define VISUAL_H

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <iostream>

class Visual {
public:
	void visualSetup();

private:
	long __stdcall WindowProcedure(HWND hWnd, unsigned int msg, WPARAM wParam, LPARAM lParam);
};

#endif