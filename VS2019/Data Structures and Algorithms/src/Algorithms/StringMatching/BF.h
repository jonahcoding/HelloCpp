#pragma once

#include <iostream>
#include <string>
using namespace std;

class BF
{
public:
    BF()
    {
        string tStr = "BCEDABCDE";
        string pStr = "BCDE";

        int tLen = tStr.size();
        int pLen = pStr.size();

        for (int i = 0; i < tLen; i++)
        {
            int k = i;
            int j = 0;
            for (j; j < pLen; j++, k++)
            {
                if (tStr[k] != pStr[j])
                    break;
            }

            if (j == pLen)
            {
                cout << "Found at: " << i + 1 << endl;
                //break;
            }
        }
    }
};
