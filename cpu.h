#ifndef CPU_H
#define CPU_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

struct CPU
{
    u_int32_t registers[8];  // 7 general purpose registers
    u_int32_t stack[0x4000]; // 8 kB
    u_char bytecode[0x1000]; // 4 kB
    uint IP;
    uint SP;
    bool power;
};

bool LoadedBytecode(const char* file, struct CPU* cpu);
struct CPU* NewCPU(void);
void Execute(struct CPU* cpu);
void InfoRegisters(struct CPU* cpu);
void InfoStack(struct CPU* cpu, uint max_memory);

#endif