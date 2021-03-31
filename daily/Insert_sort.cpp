#include <iostream>

using namespace std;

void Insert_sort(int *num,int len)
{
    int value = 0;
    int index = 0;
    for(int i=1;i<len;++i)
    {
        value = num[i];
        index = i-1;
        while(index >= 0 && value < num[index])
        {
            num[index+1] = num[index];
            index--;
        }
        num[index+1] = value;
    }

}

int main()
{
    int num[] = {2,3,1,5,4,4,2};
    Insert_sort(num,7);

    for(auto &x : num)
        cout << x << " ";
    cout << endl;

    return 0;
}