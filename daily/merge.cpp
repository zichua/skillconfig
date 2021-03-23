#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

void merge(int *array,int left,int right,int mid)
{
    int aux[right-left+1];

    for(int i=left;i<=right;i++)
        aux[i-left] = array[i];

    int i = left;
    int j = mid + 1;

    for(int k=left;k<=right;k++)
    {
        if(i>mid)
        {
            array[k] = aux[j-left];
            j++;
        }
        else if(j>right)
        {
            array[k] = aux[i-left];
            i++;
        }
        else if(aux[i-left]>aux[j-left])
        {
            array[k] = aux[j-left];
            j++;
        }
        else
        {
            array[k] = aux[i-left];
            i++;
        }
        
    }
}   

void merge_sort(int *array,int left,int right)
{
    if(left >= right)
        return;

    int mid = (left + right)/2;

    merge_sort(array,left,mid);
    merge_sort(array,mid+1,right);
    merge(array,left,right,mid);
}

int main()
{
    int array[1001];
    int num;
    scanf("%d",&num);

    for(int i=0;i<num;i++)
        scanf("%d",&array[i]);

    merge_sort(array,0,num);

    for(int &x:array)
    {
        cout << array[x];
    }
    // for(int i=0;i<num;i++)
    //     printf("%d ",array[i]);
    // printf("\n");

    return 0;
}