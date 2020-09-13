#include "cpu.h"
#include "instructions.h"

struct CPU* NewCPU()
{
    struct CPU* cpu = malloc(sizeof(cpu));
    return cpu;
}

bool LoadedBytecode(const char* file_name, struct CPU* cpu)
{
    memset(cpu->bytecode, 0xff, sizeof(cpu->bytecode));

    FILE* file = fopen(file_name, "rb");
    if(!file)
        return false;

    fread(cpu->bytecode, 1, 0x1000, file);

    fclose(file);

    return true;
}

void Execute(struct CPU* cpu)
{
    struct CPU* _cpu = cpu;
    cpu->power = false;
    cpu->IP = 0;
    cpu->SP = 0;

    // clear the VM stack and registers
    memset(cpu->stack, 0, sizeof(cpu->stack));
    memset(cpu->registers, 0, sizeof(cpu->registers));

    while(!cpu->power && cpu->IP < 0x1000)
    {
        cpu->IP++;

        switch(cpu->bytecode[cpu->IP-1])
        {
            case 0x90:
            {
                Mov(_cpu);
                break;
            }

            case 0x91:
            {
                Sub(_cpu);
                break;
            }

            case 0x92:
            {
                Add(_cpu);
                break;
            }

            case 0x093:
            {
                Dec(_cpu);
                break;
            }

            case 0x94:
            {
                Inc(_cpu);
                break;
            }
            
            case 0x95:
            {
                Mul(_cpu);
                break;
            }

            case 0x96:
            {
                Div(_cpu);
                break;
            }

            case 0x97:
            {
                Push(_cpu);
                break;
            }

            case 0x98:
            {
                Pop(_cpu);
                break;
            }

            case 0x99:
            {
                Ptb(_cpu);
                break;
            }

            case 0x9a:
            {
                Xor(_cpu);
                break;
            }
        }
    }
}

void InfoRegisters(struct CPU* cpu)
{
    puts("registers info:");
    printf("r0: %d | r4: %d\nr1: %d | r5: %d\nr2: %d | r6: %d\nr3: %d | r7: %d\n",
    cpu->registers[0], cpu->registers[4],
    cpu->registers[1], cpu->registers[5],
    cpu->registers[2], cpu->registers[6],
    cpu->registers[3], cpu->registers[7]);
}

void InfoStack(struct CPU* cpu, uint max_memory)
{
    puts("stack info:");
    
    for(uint i=0; i < max_memory; i++)
    {
        printf("[%d]", cpu->stack[i]);
    }
}