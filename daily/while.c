#include <stdio.h>

int main()
{ 
    int y = 10;
    int count = 0;
    while (y--) {
        ++count;
        printf("第%d次:y=%d\n", count, y);
    }
    printf("最后y的值:%d\n", y); 
    return 0;
}