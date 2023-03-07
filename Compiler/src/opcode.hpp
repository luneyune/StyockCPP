#ifndef STYOCKCPP_COMPILER_SRC_OPCODE_HPP_
#define STYOCKCPP_COMPILER_SRC_OPCODE_HPP_

enum Opcode {
    STOP, JMP, JS, JL, JLE, JG, JGE, JE, // Programm control opcodes
    READD, READC, READS, PRINTD, PRINTC, PRINTS, // I/O opcodes
    ADD, SUB, DIV, MOD, MUL, CMP, // Math operations opcodes
    PUSH, POP // Data operation opcodes
};

#endif
