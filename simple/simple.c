#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 4

struct thread_arg
{
    int num;
};

void *thread_func (void *varg)
{
    struct thread_arg *arg = varg;
    
    printf("I am thread %d\n", arg->num);
    
    for (;;) {
        sleep (1);
    }
}

int main (int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    struct thread_arg thread_args[NUM_THREADS];
    int i;
    
    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i].num = i;
        pthread_create (&threads[i], NULL, thread_func, &thread_args[i]);
    }
    
    
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
        
}
