#include "cpu.h"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        puts("usage ./vm <bin_file>");
        return 1;
    }
    
    puts("Virtual Machine Runing...");

    struct CPU* cpu = NewCPU();
    char* file_name = argv[1];
    if (!LoadedBytecode(file_name, cpu))
        return 2;
    Execute(cpu);
    InfoRegisters(cpu);
    InfoStack(cpu, 10);
    return 0;
}