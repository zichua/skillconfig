#include <iostream>

using namespace std;

void swap(int *num,int i,int j)
{
    num[i] = num[i] ^ num[j];
    num[j] = num[i] ^ num[j];
    num[i] = num[i] ^ num[j];
}

void Heap_adjust(int *num,int start,int len)
{
    int temp = num[start];

    for(int i=start*2;i<=len;i*=2)
    {
        if(i<len && num[i] < num[i+1])
        {
            ++i;
        }

        if(temp >= num[i])
            break;

        num[start] = num[i];
        start = i;
    }
    num[start] = temp;
}

void Heap_sort(int *num,int len)
{
    for(int i=len/2;i>0;--i)
    {
        Heap_adjust(num,i,len);
    }

    for(int i=len;i>1;--i)
    {
        swap(num,1,i);
        Heap_adjust(num,1,i-1);
    }

}

int main()
{
    int num[] = {999,1,4,2,5,6,7,8,3};
    Heap_sort(num,8);

    for(auto &x : num)
        cout << x << " ";
    cout << endl;

    return 0;
}