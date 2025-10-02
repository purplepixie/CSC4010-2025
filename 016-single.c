#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main()
{
    #pragma omp parallel
    {
        printf("Hello from thread %d\n", omp_get_thread_num());

        #pragma omp single nowait
        {
            printf("Hello from single thread %d\n", omp_get_thread_num());
            sleep(2);
            printf("Goodbye from single thread %d\n", omp_get_thread_num());
        }

        
        printf("Hello again from thread %d\n",omp_get_thread_num());
    }

    printf("Goodbye\n");

    return 0;
}