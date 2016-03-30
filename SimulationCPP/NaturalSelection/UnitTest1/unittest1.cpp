#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\NaturalSelectionDLL\NaturalSelectionDLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(FitnessValues)
		{
			std::vector<float> genes;
			genes.push_back(.10);
			genes.push_back(.20);
			genes.push_back(.30);
			genes.push_back(.40);
			genes.push_back(.50);
			CNaturalSelectionDLL ns;
			Assert::AreEqual((float)0.3, (float)ns.FitnessSingle(genes),(float) 0.0, L"FAILED", LINE_INFO());
			
			// TODO: Your test code here
		}

		TEST_METHOD(TEST2)
		{


		}
	};
}