#include <iostream>
using namespace std;

int num = 5;
void Bubble_sort(int *array)
{

    int j = 0,temp = 0;
    for(int i=0;i<num-1;++i)
    {
        for(j=i+1;j<num;++j)
        {
            if(array[i] > array[j])
            {
                //1.所有类型,性能高
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;

                //2.仅数字，性能较高
                // a = (b) + (b=a)*0;
                
                //3.
                // a = (a+b) - (b=a);
                
                //4. b不为０，仅数字，性能较高
                // a = a*b;
                // b = a/b;
                // a = a/b; 
                
                //5.数字，字符串，性能较较高
                // a = a^b;
                // b = a^b;
                // a = a^b;
                //即　a = (b = (a ^= b)^ b) ^ a;
                
                //6.仅数字，性能较高
                // a = a+b;
                // b = a-b;
                // a = a-b;
            
                //7.所有类型
                // 新对象交换，实用低

                //8.新数组,性能不高
                // a = [b,b=a][0];

                //9.try catch交换,性能垫底

            }
        }
    }

}

int main()
{
    int array[num];
    for(auto &x : array)
        cin >> x;

    Bubble_sort(array);

    for(auto &x:array)
        cout << x << " ";
    cout << endl;

    return 0;
}