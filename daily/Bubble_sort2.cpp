#include <iostream>

using namespace std;

void Bubbel_sort2(int *num,int len)
{
    int j;
    bool flag = true;
    for(int i=0;i<len-1 && flag;++i)
    {
        flag = false;
        for(j=len-2;j>=i;--j)
        {
            if(num[j] > num[j+1])
            {
                num[j] = num[j]^num[j+1];
                num[j+1] = num[j]^num[j+1];
                num[j] = num[j]^num[j+1];
                flag = true;
            }
        }
    }

}

int main()
{
    int num[] = {2,3,5,4,7,1,9,0};
    Bubbel_sort2(num,8);

    for(auto &x : num)
        cout << x << " ";
    cout << endl;

    return 0;
}