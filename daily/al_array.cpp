#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    //char
    char n_1 = 4;
    char array[n_1];
    array[n_1+1] = '\0';
    cout << "char array[4]'s sizeof " << sizeof(array) << endl;
    cout << "char array[4]'s strlen " << strlen(array) << endl;
    // for(int i=0;i<strlen(array)-1;i++)
    // {
    //     cin >> array[i];
    // }
    // for(int i=0;i<strlen(array)-1;i++)
    // {
    //     cout <<"array[4]'s " << array[i] << endl;;
    // }
    for(auto &x : array)
    {
        cin >> x;
    }
    for(auto &x : array)
    {
        cout << x << " ";
    }
    cout << endl;



    //int,double...
    int n_2 = 4;
    char array_1[n_2];
    array[n_2+1] = '\0';
    cout << "int array[4]'s sizeof " << sizeof(array_1) << endl;
    cout << "int array[4]'s strlen " << sizeof(array_1)/sizeof(int) << endl;
    
    for(auto &x : array)
    {
        cin >> x;
    }
    for(auto &x : array)
    {
        cout << x << " ";
    }
    cout << endl;


    return 0;
}