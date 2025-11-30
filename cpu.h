#ifndef CPU
#define CPU

#include <iostream>
#include "register.h"

class {
    public:
        Register reg;
        u_int8_t* mem = new uint8_t[0xFFFF]; // 64KB x 8bit total memory; 8-byte adresss x 1-byte data


        /* Prints the first 15 blocks in memory */
        void printMemory(){
            std::cout << "CPU MEMORY" << std::endl;
            std::cout << "===================" << std::endl;
            std::cout << "Address     Value" << std::endl;
            for(uint16_t i = 0x0; i < 0xF; i++){
                std::cout << std::hex << "0x" << std::setfill('0') << std::setw(4) << i << "  -->  " << "0x" << std::hex << std::setfill('0') << std::setw(2) << (int)mem[i] << std::endl;
            }

        }


        /* Prints the CPU registers */
        void printRegisters(){
            std::cout << "CPU REGISTERS" << std::endl;
            std::cout << "===================" << std::endl;
            std::cout << "Register AF: 0x" << std::setfill('0') << std::setw(2) << std::hex << (int)reg.a << std::setfill('0') << std::setw(2) << std::hex << (int)reg.f << std::endl;
            std::cout << "Register BC: 0x" << std::setfill('0') << std::setw(2) << std::hex << (int)reg.b << std::setfill('0') << std::setw(2) << std::hex << (int)reg.c << std::endl;
            std::cout << "Register DE: 0x" << std::setfill('0') << std::setw(2) << std::hex << (int)reg.d << std::setfill('0') << std::setw(2) << std::hex << (int)reg.e << std::endl;
            std::cout << "Register HL: 0x" << std::setfill('0') << std::setw(2) << std::hex << (int)reg.h << std::setfill('0') << std::setw(2) << std::hex << (int)reg.l << std::endl;
            std::cout << "Resister SP: 0x" << std::setfill('0') << std::setw(4) << std::hex << (int)reg.sp << std::endl;
            std::cout << "Register PC: 0x" << std::setfill('0') << std::setw(4) << std::hex << (int)reg.pc << std::endl;

        }


} cpu;



#endif