#include <pthread.h>
#include <stdio.h>  
#include <stdint.h>

#define THREAD_NUMBERS 10

int sum = 0;
pthread_mutex_t mut;

void *add(void *_num) {
    int num = (intptr_t)_num;
    printf("thread num: %d, %p, %ld\n", num, &num, pthread_self());
    for (int i = 0; i < 10000; i++) {
        // pthread_mutex_lock(&mut);
        // sum++;
        // pthread_mutex_unlock(&mut);
        __sync_add_and_fetch(&sum, 1);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    /* code */
    // pthread_t t1;
    // pthread_t t2;
    // pthread_t t3;
    // pthread_t t4;
    void * thread_result;
    pthread_t threads[THREAD_NUMBERS];
    for (int i = 0; i < THREAD_NUMBERS; i++) {
        int j = i;
        // printf("thead: %d\n", j);
        pthread_create(&threads[i], NULL, add, (void *)(intptr_t)j);
    }
    
    for (int i = 0; i < THREAD_NUMBERS; i++) {
        // printf("join thead: %d\n", i);
        pthread_join(threads[i], NULL);
    }
    printf("sum = %d\n", sum);

    return 0;
}
