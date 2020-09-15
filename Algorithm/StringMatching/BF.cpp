#include <iostream>
#include <string>
using namespace std;

void BF()
{
    string tStr = "ABCEDBCDEBCDEHBCDEUBCDE";
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
            cout << " Find: " << i+1 << endl;
            //break;
        }
    }
}

int main()
{
    BF();

    system("pause");

    return 0;
}
