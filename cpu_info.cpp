#include "./cpu_info.h"

unsigned int GetIsCPUIDAvailable(void)
{
    unsigned int isAvailable = 1;

    __asm
    {
        push eax                // Push eax register to queue
        pushfd                  // Push flags, status register, to queue
        pop eax                 // Move flags, status register, to eax

        xor eax, 0x00200000     // Set bit 21 to 1, says if CPUID is available
        push eax                // Push flags, status register, to queue
        popfd                   // Restore flags, status register

        push ebx                // Push ebx register to queue
        pushfd                  // Push flags, status register, to queue
        pop ebx                 // Move flags, status register, to ebx
 
        xor ebx, eax            // Compare eax and ebx => xor of bots registers should be zero
        jnz  ncpuid             // if xor operation is not zero jump to ncpuid
        jmp end                 // jump to end

ncpuid: mov isAvailable, 0      // set isAvailable to zero, CPUID not available

end:    pop ebx                 // Restore ebx register
        pop eax                 // Restore eax register
        
    }

    return isAvailable;
}

void GetCpuId(unsigned int opcode, unsigned int *a, unsigned int *b, unsigned int *c, unsigned int *d)
{
    __asm
    {
        push    eax             // Push eax register to queue
        push    ebx             // Push ebx register to queue
        push    ecx             // Push ecx register to queue
        push    edx             // Push edx register to queue

        mov     eax, opcode     // eax = opcode
        cpuid                   // Get vendor id

l_eax:  push    eax             // Push eax register to queue
        mov     eax,   a        // eax = a
        cmp     eax  , 0        // Compare with zero (NULL pointer)
        pop     eax             // Restore eax register
        jz      l_ebx           // If pointer is zero jump if (a == NULL) jmp
        mov     edi  , a        // edi = a
        mov     [edi], eax      // *a = eax

l_ebx:  push    eax             // Push eax register
        mov     eax,   b        // eax = b
        cmp     eax  , 0        // Compare with zero (NULL pointer)
        pop     eax             // Restore eax register
        jz      l_ecx           // If pointer is zero jump if (b == NULL) jmp
        mov     edi  , b        // edi = b
        mov     [edi], ebx      // *b = ebx

l_ecx:  push    eax             // Push eax register to queue
        mov     eax,   c        // ecx = c
        cmp     eax  , 0        // Compare with zero (NULL pointer)
        pop     eax             // Restore eax register
        jz      l_edx           // If pointer is zero jump if (c == NULL) jmp
        mov     edi  , c        // edi = c
        mov     [edi], ecx      // *c = ecx

l_edx:  push    eax             // Push eax register to queue
        mov     eax,   d        // edx = d
        cmp     eax  , 0        // Compare with zero (NULL pointer)
        pop     eax             // Restore eax register
        jz      end             // If pointer is zero jump if (d == NULL) jmp
        mov     edi  , d        // edi = d
        mov     [edi], edx      // *d = edx

end:    pop     edx             // Restore edx register
        pop     ecx             // Restore ecx register
        pop     ebx             // Restore ebx register
        pop     eax             // Restore eax register
    }
}
