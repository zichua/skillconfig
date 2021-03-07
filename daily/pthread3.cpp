#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define THREAD_NUM 5

void *wait(void *t)
{
    int i;
    long tid = (long)t;

    sleep(1);

    cout << "sleeping in thread " << endl;
    cout << "thread_id : " << tid << "exiting..." << endl;;

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[THREAD_NUM];
    pthread_attr_t attr;
    void *status;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

    int i;
    for(i=0;i<THREAD_NUM;++i)
    {
        cout << "main create thread " << i << endl;
        if(pthread_create(&threads[i],NULL,wait,(void *)&i));
        {
            cout << "error 1" << endl;
            exit(-1);
        }
    }

    pthread_attr_destroy(&attr);
    for(int i=0;i<THREAD_NUM;i++)
    {
        if(pthread_join(threads[i],&status))
        {
            cout << "error 2" <<endl;
            exit(-1);
        }
        cout << " main complete thread " << endl;
        cout << "exiting with sttus : " << status << endl;
    }

    cout << "main exiting ..." << endl;

    pthread_exit(NULL);
}