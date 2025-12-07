#include "cpu.h"

#define OFF 0xFF00

CPU::CPU(){
    this->reg.pc = 0x0000; // Set program counter to 0x0000
    load_bootROM(); // Load the bootROM upon initializing the CPU

}


/* Prints the first 15 blocks in memory */
void CPU::printMemory(){
    std::cout << "CPU MEMORY" << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Address     Value" << std::endl;
    for(uint16_t i = 0x0; i < 0x2F; i++){
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
    std::cout << "REGISTER FLAGS" << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Flag Z: " << std::hex << (int)reg.zf << std::endl;
    std::cout << "Flag N: " << std::hex << (int)reg.nf << std::endl;
    std::cout << "Flag H: " << std::hex << (int)reg.hf << std::endl;
    std::cout << "Flag C: " << std::hex << (int)reg.cf << std::endl;


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

uint8_t CPU::read8(){
    uint8_t n8 = fetch();
    return n8;
}

uint16_t CPU::read16(){
    uint8_t low = fetch();
    uint8_t high = fetch();

    uint16_t n16 = (high << 8) | (low);
    
    return n16;
}


void CPU::execute(uint8_t opcode){
    switch (opcode){
        case 0xc:{
            reg.c += 1;
            break;
                
        }

        case 0xe:{
            uint8_t n8 = read8();
            reg.c = n8;
            break;
                
        }

        case 0x20:{
            if(reg.zf == 0){
                int8_t s8 = (int8_t)read8();
                reg.pc = (uint16_t)(reg.pc + s8);

            }
            else{
                read8();
            }

            break;
                
        }

        case 0x21:{
            uint16_t n16 = read16();
            reg.hl = n16;
            break;
        }

        case 0x31:{
            uint16_t n16 = read16();
            reg.sp = n16;
            break;
        }

        case 0x32:{
            mem[reg.hl] = reg.a;
            reg.hl -= 1;
            break;
        }

        case 0x3e:{
            uint8_t n8 = read8();
            reg.a = n8;
            break;
                
        }

        case 0x7c:{
            reg.a = reg.h;
            break;
        }

        case 0x77: {
            mem[reg.hl] = reg.a;
            break;

        }

        case 0xaf:{
            reg.a = reg.a ^ reg.a;
            break;
        }


        case 0xcb: {
            uint8_t opcode = read8();
            prefixedExecute(opcode);
            break;

        }

        case 0xe2: {
            mem[OFF + reg.c] = reg.a;
            break;

        }


        default: {
            std::cout << "Opcode 0x" << std::hex << (int)opcode << " is not recognized" << std::endl;
            std::cout << "PC: 0x" << std::setfill('0') << std::setw(4) << std::hex << (int)reg.pc << std::endl;
            break;
        }

    }

    regFlagCheck();
}

void CPU::prefixedExecute(uint8_t opcode){
    switch (opcode){
        case 0x7c: {
            int test = (reg.h >> 7) & 1;
            reg.zf = (reg.zf & ~(1 << 7)) | ((!test) << 7);
            break;
        }

        
        default: {
            std::cout << "Opcode 0xCB" << std::hex << (int)opcode << " is not recognized" << std::endl;
            break;
        }

    }
}

void CPU::regFlagCheck(){
    // zero flag check
    if(reg.a == 0 || reg.b == 0 || reg.c == 0 || reg.d == 0 || reg.h == 0 || reg.l == 0){
        reg.f = reg.f | (1 << 7);
    }

    // bool zf = f & (1 << 7);
    // bool nf = f & (1 << 6);
    // bool hf = f & (1 << 5);
    // bool cf = f & (1 << 4);
    
}