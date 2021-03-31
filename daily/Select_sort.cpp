#include <iostream>

using namespace std;

void Select_sort(int *num,int len)
{
    int j,min;
    for(int i=0;i<len-1;++i)
    {
        min = i;
        for(j=i+1;j<len;++j)
        {
            if(num[min] > num[j])
            {
                min = j;
            }
        }
        if(i != min)
        {
            num[i] = num[i]^num[min];
            num[min] = num[i]^num[min];
            num[i] = num[i]^num[min];
        }
    }

}

int main()
{
    int num[] = {3,1,4,5,6,3,7,2};
    Select_sort(num,8);

    for(auto &x : num)
        cout << x << " ";
    cout << endl;

    return 0;
}