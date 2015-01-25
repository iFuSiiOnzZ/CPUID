#include <stdio.h>
#include <stdlib.h>

#include "cpu_info.h"
#include "0x00000000.h"
#include "0x00000001.h"

int main(int argc, char *argv[])
{
    if(1 == GetIsCPUIDAvailable()){ printf("CPUID Available!\n\n"); }
    else{ printf("CPUID Not Available!\n\n"); fflush(stdin); getchar(); return(EXIT_SUCCESS); }

    AMD_0x00000000 amd0 = { 0, 0 };
    GetCpuId
    (
        0x00000000,
        &amd0.m_MaxFunction.m_LFuncStd,
        (unsigned int *) &amd0.m_VendorName.m_VenderName[0],
        (unsigned int *) &amd0.m_VendorName.m_VenderName[7],
        (unsigned int *) &amd0.m_VendorName.m_VenderName[3]
    );
    
    printf("OPCODE 0x00000000 INFO\n");
    printf("MaxFuncStd: %d\n", amd0.m_MaxFunction.m_LFuncStd);
    printf("Vendor Name: %s\n", amd0.m_VendorName.m_VenderName);
    printf("===\n\n");


    AMD_0x00000001 amd1 = { 0, 0, 0, 0 };
    GetCpuId
    (
        0x00000001, 
        (unsigned int *) &amd1.m_FamilyModelStepping, 
        (unsigned int *) &amd1.m_ApiThreadCountClflush, 
        (unsigned int *) &amd1.m_Id1, 
        (unsigned int *) &amd1.m_Id2
    );
    printf("OPCODE 0x00000001 INFO\n");
    printf("Base Family: %xh\n", amd1.m_FamilyModelStepping.m_BaseFamily);
    printf("Base Model: %xh\n", amd1.m_FamilyModelStepping.m_BaseModel);
    printf("Ext Family: %xh\n", amd1.m_FamilyModelStepping.m_ExtFamily);
    printf("Ext Model: %xh\n", amd1.m_FamilyModelStepping.m_ExtModel);
    printf("Stepping: %xh\n\n", amd1.m_FamilyModelStepping.m_Stepping);

    printf("ClFLush: %d\n", amd1.m_ApiThreadCountClflush.m_ClFlush);
    printf("Brand Id: %d\n", amd1.m_ApiThreadCountClflush.m_BrandId);
    printf("Local Apic Id: %d\n", amd1.m_ApiThreadCountClflush.m_LocalApicId);
    printf("Threads Count: %d\n", amd1.m_ApiThreadCountClflush.m_ThreadsCount);
    printf("===\n\n");

    fflush(stdin); getchar();
    return(EXIT_SUCCESS);
}
