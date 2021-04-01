#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int in,out,err;
    open("/dev/stdin",O_CREAT,S_IRUSR|S_IXOTH);
    open("/dev/stdou",O_CREAT,S_IRUSR|S_IXOTH);
    open("/dev/stderr",O_CREAT,S_IRUSR|S_IXOTH);

    char buf[20];
    int n_read;
    n_read = read(0,buf,128);

    if(n_read == -1)
    {
        write(2,"A READ ERROR HAS OCCURRED\n",26);
    }

    if(write(1,buf,n_read) != n_read)
    {
        write(2,"A WRITE ERROR HAS OCCURRED\n",27);
    }

    exit(0);
}