#include <iostream>
#include <pthread.h>

using namespace std;

#define THREAD_NUM 5

void *hello(void *args)
{
    cout << "Hello world!" << endl;
    return 0;
}

int main()
{
    pthread_t tids[THREAD_NUM];

    for(int i=0;i<THREAD_NUM;++i)
    {
        int ret = pthread_create(&tids[i],NULL,hello,NULL);
        if(ret != 0)
            cout << "error" <<endl;
        else
            cout << " thread_num : " << i << "   ";
    }

    pthread_exit(NULL);
}