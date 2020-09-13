#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "cpu.h"
#define FIRST_PARAM cpu->registers[cpu->bytecode[cpu->IP]]
#define SECOND_PARAM cpu->bytecode[cpu->IP+1]

// CPU instructions
void Mov(struct CPU* cpu);
void Sub(struct CPU* cpu);
void Add(struct CPU* cpu);
void Dec(struct CPU* cpu);
void Inc(struct CPU* cpu);
void Mul(struct CPU* cpu);
void Div(struct CPU* cpu);
void Push(struct CPU* cpu);
void Pop(struct CPU* cpu);
void Ptb(struct CPU* cpu);
void Xor(struct CPU* cpu);
void Call(struct CPU* cpu);

// other functions for cleanup code
void SetSP(struct CPU** cpu);

#endif