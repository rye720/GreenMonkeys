// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the NATURALSELECTIONDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// NATURALSELECTIONDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef NATURALSELECTIONDLL_EXPORTS
#define NATURALSELECTIONDLL_API __declspec(dllexport)
#else
#define NATURALSELECTIONDLL_API __declspec(dllimport)
#endif

#include <vector>
#include <memory>
// This class is exported from the NaturalSelectionDLL.dll
class NATURALSELECTIONDLL_API CNaturalSelectionDLL {
private:
public:
	CNaturalSelectionDLL(void);
	float FitnessSingle(std::vector<float> fitnessVec);

	
	// TODO: add your methods here.
};

extern NATURALSELECTIONDLL_API int nNaturalSelectionDLL;

NATURALSELECTIONDLL_API int fnNaturalSelectionDLL(void);
