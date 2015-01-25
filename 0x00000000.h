#pragma once

/*
* http://support.amd.com/TechDocs/25481.pdf
*/

typedef struct AMD_LARGEST_STANDARD_FUNCTION
{
    unsigned int m_LFuncStd;
}AMD_LARGEST_STANDARD_FUNCTION;

typedef struct AMD_VENDOR_NAME
{
    char m_VenderName[13];
}AMD_VENDOR_NAME;

typedef struct AMD_0x00000000
{
    struct AMD_LARGEST_STANDARD_FUNCTION m_MaxFunction;
    struct AMD_VENDOR_NAME               m_VendorName;
}AMD_0x00000000;