#include <iostream>
#include <fstream>
#include "cpu.h"




int main(){
    CPU cpu;

    //cpu.printMemory();
    bool status = true;
    while(status && cpu.reg.pc != 0xff){
        uint8_t instruction = cpu.fetch();
        status = cpu.execute(instruction);

    }
    
    cpu.printRegisters();

    // uint8_t instruction = cpu.fetch();
    // std::cout << "Instruction: 0x" << std::hex << (int)instruction << std::endl;
    // cpu.execute(instruction);


}


