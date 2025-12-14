#include <iostream>
#include <fstream>
#include "cpu.h"

int main(){
    CPU cpu;

    bool status = true;
    while(status && cpu.reg.pc < 0x00FF){
        uint8_t instruction = cpu.fetch();
        status = cpu.execute(instruction);

    }
  
    cpu.printRegisters();

}