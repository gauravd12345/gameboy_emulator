#include <iostream>

#include "cpu.h"

int main(){
    cpu.mem[0x0000] = 0x12;
    std::cout << std::hex << (int)cpu.mem[0x0000] << std::endl;

    cpu.printRegisters();
    cpu.printMemory();
}