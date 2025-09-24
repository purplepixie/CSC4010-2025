#include <stdio.h>
#include <omp.h>

int main()
{
    int counter = 0;
    #pragma omp parallel
    {
        int tc = counter;
        //printf("Thread %d has tc=%d\n", omp_get_thread_num(), tc);
        tc++;
        counter = tc;
    }
    printf("The counter is %d\n", counter);
    return 0;
}
