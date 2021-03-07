#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

struct thread_data
{
    int thread_id;
    char *message;
};

void *hello(void *threadarg)
{
    struct thread_data *my_data;

    my_data = (struct thread_data *)threadarg;

    cout << "thread_id : " << my_data->thread_id << "   ";
    cout << "thread_message : " << my_data->message << endl;

    pthread_exit(NULL);
}

#define THREAD_NUM 5
int main()
{
    pthread_t threads[THREAD_NUM];
    struct thread_data td[THREAD_NUM];
    
    for(int i=0;i<THREAD_NUM;++i)
    {
        cout << "main create thread " << i << endl;
        td[i].thread_id = i;
        td[i].message = (char *)"hello world";

        if(pthread_create(&threads[i],NULL,hello,(void *)&td[i]))
        {
            cout << "error" << endl;
            exit(-1);
        }
    }

    pthread_exit(NULL);
}