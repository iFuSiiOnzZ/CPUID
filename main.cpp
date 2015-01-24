#include <stdio.h>
#include <stdlib.h>

#include "cpu_info.h"

int main(int argc, char *argv[])
{
    printf("IsCPUIDAvailable: %d\n", GetIsCPUIDAvailable());

    fflush(stdin); getchar();
    return(EXIT_SUCCESS);
}
