#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{ 
int my_array[5] = { 1, 2, 3, 4, 5 };

// 不会改变 my_array 数组中元素的值
// x 将使用 my_array 数组的副本
for (int x : my_array)
{
    x *= 2;
    cout << x << endl;
}

// 会改变 my_array 数组中元素的值
// 符号 & 表示 x 是一个引用变量，将使用 my_array 数组的原始数据
// 引用是已定义的变量的别名
for (int& x : my_array)
{
    x *= 2;
    cout << x << endl;
}

// 还可直接使用初始化列表
for (int x : { 1, 2, 3, 4, 5 })
{
    x *= 2;
    cout << x << endl;
}
}