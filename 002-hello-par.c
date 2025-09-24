#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        printf("Hello world\n");
    }

    printf("Goodbye\n");
    return 0;
}