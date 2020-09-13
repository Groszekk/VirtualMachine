#include "instructions.h"

void Mov(struct CPU* cpu)
{
    //cpu->registers[cpu->bytecode[cpu->IP]] = cpu->bytecode[cpu->IP+1];
    FIRST_PARAM = SECOND_PARAM;
    printf("mov r%d, %d\n", cpu->bytecode[cpu->IP], cpu->bytecode[cpu->IP+1]);
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
    SetSP(&cpu);
    // cpu->stack[cpu->SP] = cpu->bytecode[cpu->IP];
    cpu->stack[cpu->SP] = cpu->bytecode[cpu->IP];
    cpu->IP++;
}

void Pop(struct CPU* cpu)
{
    SetSP(&cpu);
    uint counter = cpu->bytecode[cpu->IP];
    for(uint i=0; i <= counter; i++)
    {
        cpu->stack[cpu->SP--] = 0;
    }
    FIRST_PARAM = cpu->stack[cpu->SP--];
    cpu->IP++;
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

void SetSP(struct CPU** cpu)
{
    for(uint i=0; i <= sizeof((*cpu)->stack); i++)
    {
        if((*cpu)->stack[i] == 0)
        {
            (*cpu)->SP = i;
            break;
        }
    }
}