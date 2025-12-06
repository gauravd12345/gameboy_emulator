#include <iostream>
#include <fstream>
#include "cpu.h"

int main(){
    CPU cpu;

    for(int i = 0; i < 0xF; i++){
        uint8_t instruction = cpu.fetch();
        std::cout << std::hex << (int)instruction << std::endl;
    }
    //cpu.printMemory();
    //cpu.printRegisters();


}