#ifndef _STRING_MATCHING_TEST_H_
#define _STRING_MATCHING_TEST_H_

//#include <iostream>
//using namespace std;

#include "BruteForce.h"
#include "KMP.h"

class StringMatchingTest
{
public:
	StringMatchingTest()
	{
		t = "ABAABCABBCABCC";
		p = "ABC";

		vector<int> v_BF;
		vector<int> v_KMP;


		//BruteForce(t, p);
		KMPTest();
	}

private:
	string t;
	string p;
};



#endif // !_STRING_MATCHING_TEST_H_
