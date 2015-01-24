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
