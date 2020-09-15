# Virtual Machine

# Specification

## Memory
- 8kB stack
- 4kB for bytecode
- boolean power
## Registers
- 7 general purpose registers (r0 - r7)
- IP (Instruction Pointer)
- SP (Stack Pointer)
## Instructions
- _mov **reg**, **imm32** | (**req** -> **imm32**)
- _sub **reg**, **imm32** | (**req** += **imm32**)
- _add **reg**, **imm32** | (**req** -= **imm32**)
- _dec **req**            | (**req** -= 1)
