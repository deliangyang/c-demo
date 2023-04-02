#include <pthread.h>
#include <stdio.h>  

int sum = 0;
pthread_mutex_t mut;

void *add(void *args) {
    for (int i = 0; i < 10000; i++) {
        // pthread_mutex_lock(&mut);
        // sum++;
        // pthread_mutex_unlock(&mut);
        __sync_add_and_fetch(&sum, 1);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;

    pthread_create(&t1, NULL, add, NULL);
    pthread_create(&t2, NULL, add, NULL);
    pthread_create(&t3, NULL, add, NULL);
    pthread_create(&t4, NULL, add, NULL);
    getchar();
    printf("sum = %d\n", sum);
    return 0;
}
