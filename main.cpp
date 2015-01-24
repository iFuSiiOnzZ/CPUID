#include <stdio.h>
#include <stdlib.h>

#include "cpu_info.h"
#include "0x00000001.h"

int main(int argc, char *argv[])
{
    printf("IsCPUIDAvailable: %d\n", GetIsCPUIDAvailable());

    AMD_0x00000001 amd;
    GetCpuId
    (
        0x00000001, 
        (unsigned int *) &amd.m_FamilyModelStepping, 
        (unsigned int *) &amd.m_ApiThreadCountClflush, 
        (unsigned int *) &amd.m_Id1, 
        (unsigned int *) &amd.m_Id2
    );

    printf("Threads Count: %d\n", amd.m_ApiThreadCountClflush.m_ThreadsCount);

    fflush(stdin); getchar();
    return(EXIT_SUCCESS);
}
