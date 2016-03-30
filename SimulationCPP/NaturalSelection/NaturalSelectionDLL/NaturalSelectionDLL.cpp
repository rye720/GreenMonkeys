// NaturalSelectionDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "NaturalSelectionDLL.h"


// This is an example of an exported variable
NATURALSELECTIONDLL_API int nNaturalSelectionDLL=0;

// This is an example of an exported function.
NATURALSELECTIONDLL_API int fnNaturalSelectionDLL(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see NaturalSelectionDLL.h for the class definition
CNaturalSelectionDLL::CNaturalSelectionDLL()
{
	return;
}

float CNaturalSelectionDLL::FitnessSingle(std::vector<float> fitnessVec){
		float total = 0.0;
		int i = 0;
		for (auto & gene : fitnessVec){
			total += gene;
			i++;
		}
		return total / (float)i;
}