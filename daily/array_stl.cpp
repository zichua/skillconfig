#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int,5> a;
    for(int i=0;i<10;i++)
        cin >> a.at(i);
    // for(int i=0;i<10;i++)
    //     cout << a.at(i);
    // for(auto &x:a)
    // {
    //     cout << x << " ";
    // }
    
    const int n = 0;
    cout << get<n>(a) << endl;

    return 0;
}