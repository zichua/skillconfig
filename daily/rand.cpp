#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand((unsigned )time(0));

    for(int i=0;i<5;i++)
    {
        cout << rand() << endl;
    }

}