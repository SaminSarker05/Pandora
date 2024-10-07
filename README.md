# Pandora
will create a 32 bit cpu
easy to implement since most computers have 32-bit systems and 4 byte allocation for integers

- implemented ALU, registers, memory, and Control Unit with OOP principes to emulate CPU 
- wrote program instructions to generate FIbb numbers
- implementation of ISA instruction sets and FDE cycle algoroirthm for instruction sets

[CONTROL_UNIT]
- fetch instructions from RAM, decode and send signals to ALU via bus
- direct ALU work and use registers for storage

[ALU]
- logical operations (NOT, AND, XOR, OR, BIT SHIFT)
- arithemtic operations
- takes commands control unit

[BUS]
- enables communication between CPU, MEMORY, Registers

[MEMORY] Working...
- registers
- memory; place for program instructions; similar to assembly code
- primary or temporary data

[project directory structure]

src/ - source files .cpp
include/ - header files .h
bin/ - executables: machine code created by compiler
