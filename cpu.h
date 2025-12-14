#ifndef CPU_DEF
#define CPU_DEF

#include <iostream>
#include <fstream>
#include "register.h"


class CPU{
    public:
        Register reg;
        u_int8_t* mem; // 64KB x 8bit total memory; 8-byte adresss x 1-byte data
        
        CPU(); // Constructor

        void printStack();
        void printMemory();
        void printRegisters();
        void load_bootROM();
        void load_header();

        uint8_t fetch();
        uint8_t read8();
        uint16_t read16();

        void push(uint8_t val);

        bool execute(uint8_t opcode);
        void prefixedExecute(uint8_t opcode);
        void regFlagCheck(uint8_t opcode);
} ;



#endif