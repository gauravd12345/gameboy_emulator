#include "cpu.h"


CPU::CPU(){
    this->reg.pc = 0x0000; // Set program counter to 0x0000
    load_bootROM(); // Load the bootROM upon initializing the CPU

}


/* Prints the first 15 blocks in memory */
void CPU::printMemory(){
    std::cout << "CPU MEMORY" << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Address     Value" << std::endl;
    for(uint16_t i = 0x0; i < 0xFF; i++){
        std::cout << std::hex << "0x" << std::setfill('0') << std::setw(4) << i << "  -->  " << "0x" << std::hex << std::setfill('0') << std::setw(2) << (int)mem[i] << std::endl;
    }

}

/* Prints the CPU registers */
void CPU::printRegisters(){
    std::cout << "CPU REGISTERS" << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Register AF: 0x" << std::setfill('0') << std::setw(2) << std::hex << (int)reg.a << std::setfill('0') << std::setw(2) << std::hex << (int)reg.f << std::endl;
    std::cout << "Register BC: 0x" << std::setfill('0') << std::setw(2) << std::hex << (int)reg.b << std::setfill('0') << std::setw(2) << std::hex << (int)reg.c << std::endl;
    std::cout << "Register DE: 0x" << std::setfill('0') << std::setw(2) << std::hex << (int)reg.d << std::setfill('0') << std::setw(2) << std::hex << (int)reg.e << std::endl;
    std::cout << "Register HL: 0x" << std::setfill('0') << std::setw(2) << std::hex << (int)reg.h << std::setfill('0') << std::setw(2) << std::hex << (int)reg.l << std::endl;
    std::cout << "Resister SP: 0x" << std::setfill('0') << std::setw(4) << std::hex << (int)reg.sp << std::endl;
    std::cout << "Register PC: 0x" << std::setfill('0') << std::setw(4) << std::hex << (int)reg.pc << std::endl;

}

/* Loads the Boot ROM onto the CPU memory */
void CPU::load_bootROM(){
    std::ifstream bootROM;
    bootROM.open("dmg_boot.bin", std::ios::in | std::ios::binary);

    char* bootROM_buffer = new char[0xFF];
    bootROM.read(bootROM_buffer, 0xFF);

    for(uint8_t i = 0; i < 0xFF; i++){
        this->mem[i] = bootROM_buffer[i];
    }
    
}

/* Fetch's the next instruction from memory */
uint8_t CPU::fetch(){
    uint16_t pc_address = this->reg.pc; 
    this->reg.pc += 1; // Increments the program counter

    return this->mem[pc_address];
}