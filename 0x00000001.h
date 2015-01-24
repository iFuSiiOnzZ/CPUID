#pragma once

/*
* http://support.amd.com/TechDocs/25481.pdf
*/

typedef struct AMD_FAMILY_MODEL_STEPPING
{
    unsigned int m_Stepping         :   4;
    unsigned int m_BaseModel        :   4;
    unsigned int m_BaseFamily       :   4;
    unsigned int m_Reserved1        :   4;
    unsigned int m_ExtModel         :   4;
    unsigned int m_ExtFamily        :   8;
    unsigned int m_Reserved2        :   4;
}AMD_FAMILY_MODEL_STEPPING;

typedef struct AMD_APICID_THREADCOUNT_CLFLUSH
{
    unsigned int m_BrandId          :   8;
    unsigned int m_ClFlush          :   8;
    unsigned int m_ThreadsCount     :   8;
    unsigned int m_LocalApicId      :   8;
}AMD_APICID_THREADCOUNT_CLFLUSH;

typedef struct AMD_FEATURES_IDENTIFIERS_1
{
    unsigned int m_Ss3              :   1;
    unsigned int m_Pclmul           :   1;
    unsigned int m_Reserved1        :   1;
    unsigned int m_Monitor          :   1;
    unsigned int m_Reserved2        :   4;
    unsigned int m_Sss3             :   1;
    unsigned int m_Reserved3        :   2;
    unsigned int m_Fma              :   1;
    unsigned int m_Cmpxchg16b       :   1;
    unsigned int m_Reserved4        :   5;
    unsigned int m_Sse41            :   1;
    unsigned int m_Sse42            :   1;
    unsigned int m_Reserved5        :   2;
    unsigned int m_Popcnt           :   1;
    unsigned int m_Reserved6        :   1;
    unsigned int m_Aes              :   1;
    unsigned int m_Xsave            :   1;
    unsigned int m_Osxsave          :   1;
    unsigned int m_Avx              :   1;
    unsigned int m_H16f             :   1;
    unsigned int m_Reserved7        :   1;
    unsigned int m_Raz              :   1;
}AMD_FEATURES_IDENTIFIERS_1;

typedef struct AMD_FEATURES_IDENTIFIERS_2
{
    unsigned int m_Fpu              :   1;
    unsigned int m_Vme              :   1;
    unsigned int m_De               :   1;
    unsigned int m_Pse              :   1;
    unsigned int m_Tsc              :   1;
    unsigned int m_Msr              :   1;
    unsigned int m_Pae              :   1;
    unsigned int m_Mce              :   1;
    unsigned int m_Cmpxchg8b        :   1;
    unsigned int m_Apic             :   1;
    unsigned int m_Reserved1        :   1;
    unsigned int m_SysEnterExit     :   1;
    unsigned int m_Mtrr             :   1;
    unsigned int m_Pge              :   1;
    unsigned int m_Mca              :   1;
    unsigned int m_Cmov             :   1;
    unsigned int m_Pat              :   1;
    unsigned int m_Pse36            :   1;
    unsigned int m_Reserved2        :   1;
    unsigned int m_Clfsh            :   1;
    unsigned int m_Reserved3        :   3;
    unsigned int m_Mmx              :   1;
    unsigned int m_Fxsr             :   1;
    unsigned int m_Sse              :   1;
    unsigned int m_Sse2             :   1;
    unsigned int m_Reserved4        :   1;
    unsigned int m_htt              :   1;
    unsigned int m_Reserved5        :   3;
}AMD_FEATURES_IDENTIFIERS_2;

typedef struct AMD_0x00000001
{
    struct AMD_FEATURES_IDENTIFIERS_1       m_Id1;                      // ECX
    struct AMD_FEATURES_IDENTIFIERS_2       m_Id2;                      // EDX
    struct AMD_FAMILY_MODEL_STEPPING        m_FamilyModelStepping;      // EAX
    struct AMD_APICID_THREADCOUNT_CLFLUSH   m_ApiThreadCountClflush;    // EBX
}AMD_0x00000001;
