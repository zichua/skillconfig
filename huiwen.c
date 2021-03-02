#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    scanf("%d",&x);
    if(x < 0)
    {
        printf("false");
    }
    else
    {
        int num = 0;
        int temp;
        int t = x;
        while(t>0)
        {
           
            temp = t%10;
            num += temp;
            if(t>=10)
                num *= 10;
            t = t/10;
        }
        if(num == x)
            printf("true");
        else
            printf("false");
    }

    return 0;
}