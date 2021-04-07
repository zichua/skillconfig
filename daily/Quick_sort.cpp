#include <iostream>

using namespace std;

// void swap(int *array,int a,int b)
// {
//     array[a] = array[a]^array[b];
//     array[b] = array[a]^array[b];
//     array[a] = array[a]^array[b];
// }

int partition(int *array,int left,int right)
{
    int temp = array[left];
    while(left < right)
    {
        while(left<right && array[right]>=temp)
            right--;
        if(left <right)
            // swap(array,left,right);
            array[left] = array[right];

        while(left<right && array[left]<=temp)
            left++;
        if(left < right)
            // swap(array,left,right);
            array[right] = array[left];
    }
    array[left] = temp;
    
    return left;

}

void Qsort(int *array,int left,int right)
{
    int mid;
    if(left < right)
    {
        mid = partition(array,left,right);

        Qsort(array,left,mid-1);
        Qsort(array,mid+1,right);
    }

}

int main()
{
    int array[] = {1,4,7,8,5,2,6,3,9};

    Qsort(array,0,8);

    for(auto &x : array)
        cout << x << " ";
    cout << endl;

    return 0;
}