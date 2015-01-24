#pragma once

/***
* http://en.wikipedia.org/wiki/CPUID
* http://en.wikipedia.org/wiki/FLAGS_register
* http://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture
***/

void GetCpuId(unsigned int opcode, unsigned int *a, unsigned int *b, unsigned int *c, unsigned int *d);
unsigned int GetIsCPUIDAvailable(void);
