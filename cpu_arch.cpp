/*
    Nintendo Gameboy CPU Information
        Name: Sharp SM83
        CPU size: 8-bit
        Clock speed: 4.19 Mhz
        

*/


#include <iostream>


// The CPU's registers
struct Register{
    unsigned char a; // size of unsigned char is 8 bits; 0-255 values
    unsigned char b;
    unsigned char c;
    unsigned char d;
    unsigned char e;
    unsigned char f;
    unsigned char h;
    unsigned char l;


};

int main(){

    Register reg;
    reg.a = 0x6F;
    std::cout << reg.a << std::endl;

}
