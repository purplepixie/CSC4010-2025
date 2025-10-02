#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    #pragma omp parallel
    {
        int sleep = rand() % 3;

        if (omp_get_thread_num() == 5)
        {
            sleep = 10;
        }


        printf("Hello from thread %d, I will sleep for %d seconds\n",
            omp_get_thread_num(),sleep);

        #pragma omp for schedule(dynamic)
        for(int i=0; i<50; ++i)
        {
            nanosleep((const struct timespec[]){{sleep,0}},NULL);
            printf("i=%d in thread %d\n",i,omp_get_thread_num());
        }

        printf("All threads finished\n");
    }

    printf("Parallel region finished\n");

    return 0;
}