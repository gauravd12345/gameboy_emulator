#ifndef CPU_DEF
#define CPU_DEF

#include <iostream>
#include <fstream>
#include "register.h"

class CPU{
    public:
        Register reg;
        u_int8_t* mem = new uint8_t[0xFFFF]; // 64KB x 8bit total memory; 8-byte adresss x 1-byte data
        
        CPU(); // Constructor

        void printMemory();
        void printRegisters();
        void load_bootROM();

        u_int8_t fetch();
} ;



#endif