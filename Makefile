OBJECTS = cpu.o instructions.o
VM_INPUT = myasm_bin
VM = vm
all: ${OBJECTS}
	gcc main.c ${OBJECTS} -o ${VM}

cpu.o:cpu.c
	gcc cpu.c -c -o cpu.o

instructions.o:instructions.c
	gcc instructions.c -c -o instructions.o

run: ${OBJECTS}
	gcc main.c ${OBJECTS} -o ${VM}
	./${VM} ${VM_INPUT}

asm:
	nasm main.myasm -o ${VM_INPUT}