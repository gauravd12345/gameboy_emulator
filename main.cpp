#include <iostream>
#include <fstream>
#include "cpu.h"


void print8bit(int num){
    for(int i = 7; i >= 0; i--){
        if((num & (1 << i))){
            std::cout << 1;
        }
        else{
            std::cout << 0;
        }

    }
    std::cout << std::endl;
}

int main(){
    CPU cpu;

    for(int i = 0; i < 0x6010; i++){
        uint8_t instruction = cpu.fetch();
        cpu.execute(instruction);


    }
    cpu.printMemory();
    cpu.printRegisters();


    // uint8_t instruction = cpu.fetch();
    // std::cout << "Instruction: 0x" << std::hex << (int)instruction << std::endl;
    // cpu.execute(instruction);


}


