#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int in,out,err;
    open("/dev/stdin",O_CREAT,S_IRUSR|S_IXOTH);
    open("/dev/stdou",O_CREAT,S_IRUSR|S_IXOTH);
    open("/dev/stderr",O_CREAT,S_IRUSR|S_IXOTH);

    if(write(1,"HERE IS SOME DATA\n",18) != 18)
    {
        write(2,"A WRITE ERROR HAS OCCURRED",26);
    }

    exit(0);
}