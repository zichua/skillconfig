#include <iostream>

using namespace std;

void Buttle_sort1(int *num,int len)
{
    int j;
    for(int i=0;i<len-1;++i)
    {
        for(j=len-2;j>=i;--j)
        {
            if(num[j] > num[j+1])
            {
                num[j] = num[j]^num[j+1];
                num[j+1] = num[j]^num[j+1];
                num[j] = num[j]^num[j+1];
            }
        }
    }

}


int main()
{
    int num[] = {3,7,5,8,9,2,6};
    Buttle_sort1(num,7);

    for(auto &x : num)
        cout << x << " ";
    cout << endl;

    return 0;
}