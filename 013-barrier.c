#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL));

    #pragma omp parallel
    {
        int t = rand() % 5;
        printf("Thread %d sleeping for %d seconds\n", omp_get_thread_num(), t);
        sleep(t);
        printf("Thread %d finished sleeping\n", omp_get_thread_num());

        #pragma omp barrier
        printf("All threads finished\n");
    }


    printf("Program finished\n");

    return 0;
}
