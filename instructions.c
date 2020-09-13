#include "instructions.h"

void Mov(struct CPU* cpu)
{
    //cpu->registers[cpu->bytecode[cpu->IP]] = cpu->bytecode[cpu->IP+1];
    FIRST_PARAM = SECOND_PARAM;
    printf("mov r%d, %d\n", cpu->bytecode[cpu->IP], cpu->bytecode[cpu->IP+1]);
    printf("IP -> %d\n", cpu->IP);
    cpu->IP+=2;
}

void Sub(struct CPU* cpu)
{
    FIRST_PARAM += SECOND_PARAM;
    cpu->IP+=2;
}

void Add(struct CPU* cpu)
{
    FIRST_PARAM -= SECOND_PARAM;
    cpu->IP+=2;
}

void Dec(struct CPU* cpu)
{
    FIRST_PARAM--;
    cpu->IP++;
}

void Inc(struct CPU* cpu)
{
    FIRST_PARAM++;
    cpu->IP++;
}

void Mul(struct CPU* cpu)
{
    FIRST_PARAM *= SECOND_PARAM;
    cpu->IP+=2;
}

void Div(struct CPU* cpu)
{
    FIRST_PARAM /= SECOND_PARAM;
    cpu->IP+=2;
}

void Push(struct CPU* cpu)
{
    cpu->stack[cpu->SP] = cpu->bytecode[cpu->IP];
    cpu->IP++;
    cpu->SP++;
}

void Pop(struct CPU* cpu)
{
    FIRST_PARAM = cpu->stack[cpu->SP-1];
    cpu->IP++;
    cpu->SP--;
}

void Ptb(struct CPU* cpu)
{
    printf("%d\n", cpu->registers[cpu->bytecode[cpu->IP]]);
    cpu->IP++;
}

void Xor(struct CPU* cpu)
{
    FIRST_PARAM ^= SECOND_PARAM;
    cpu->IP+=2;
}

void Call(struct CPU* cpu)
{
    cpu->stack[cpu->SP] = cpu->bytecode[cpu->IP]; // stack[SP] = IP position
    cpu->IP = (cpu->bytecode[cpu->IP])-1; // change IP to calling label
    cpu->SP++;
    cpu->IP++;
}