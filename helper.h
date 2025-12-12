#include <iostream>

// prints the binary value of an 8-bit number
void print8_b(int num){
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

// prints the hexadecimal value of an 8-bit number
void print8_h(int num){
    std::cout << std::hex << (int)num << std::endl;
}

// prints the binary value of an 16-bit number
void print16_b(int num){
    for(int i = 15; i >= 0; i--){
        if((num & (1 << i))){
            std::cout << 1;
        }
        else{
            std::cout << 0;
        }

    }
    std::cout << std::endl;
}

// prints the hexadecimal value of an 16-bit number
void print16_h(int num){
    std::cout << std::hex << (int)num << std::endl;
}