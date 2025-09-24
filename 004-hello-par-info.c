#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        printf("Hello from thread %d\n", omp_get_thread_num());
    }

    printf("Goodbye\n");
    return 0;
}