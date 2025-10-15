#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int x = 30;
    int y = 50;

    #pragma omp parallel for schedule(dynamic)
    for(int outer = 0; outer < x; ++outer)
    {
        for (int inner = 0; inner<y; ++inner)
        {
            printf("outer=%d inner=%d\n",outer,inner);
            usleep(20000);
        }
    }

    return 0;
}