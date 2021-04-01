#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define M 32

int in = 0;
int out = 0;
int buf[M] = {0};

sem_t empty_sem;
sem_t full_sem;
pthread_mutex_t mutex;

void print()
{
    for(int i=0;i<M;i++)
    {
        printf("%d ",buf[i]);
    }
    printf("\n");
}

void *producer_1()
{
    for(;;)
    {
        sleep(1);

        sem_wait(&empty_sem);
        pthread_mutex_lock(&mutex);

        in = in % M;
        printf("(+) produce  ：  ");
        buf[in] = 1;
        print();
        ++in;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty_sem);
    }
}


void *custerom_1()
{
    for(;;)
    {
        sleep(2);

        sem_wait(&empty_sem);
        pthread_mutex_lock(&mutex);

        out = out % M;
        printf("(-) custerom :   ");
        buf[out] = 0;
        print();
        ++out;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty_sem);
    }
}


void sem_mutex_init()
{
    int init_1 = sem_init(&empty_sem,0,M);
    int init_2 = sem_init(&full_sem,0,0);

    if( (init_1 != 0) && (init_2 != 0))
    {
        printf("sem init failed \n");
        exit(1);
    }

    int init_3 = pthread_mutex_init(&mutex,NULL);

    if(init_3 != 0)
    {
        printf("mutex init failed \n");
        exit(1);
    }
}

int main()
{
    pthread_t id_1[10];
    pthread_t id_2[10];
    int i,ret;
    void *retval[10];

    sem_mutex_init();

    for(int i =0;i<10;i++)
    {
        ret = pthread_create(&id_1[i],NULL,producer_1,NULL);
        if(ret != 0)
        {
            printf(" producer create failed \n");
            exit(1);
        }
    }

    for(int i=0;i<10;i++)
    {
        ret = pthread_create(&id_2[i],NULL,custerom_1,NULL);
        if(ret != 0)
        {
            printf("custerom create failed \n");
            exit(1);
        }
    }

    for(int i=0;i<10;i++)
    {
         pthread_join(id_1[i],&retval[i]);
    }
    for(int i=0;i<10;i++)
    {
         pthread_join(id_2[i],&retval[i]);
    }


    exit(0);
}
