/* 
    CPU registers:

        a. Flags register is lower 8 bits of AF
            Bit 4 -> Carry Flag
            Bit 5 -> Half Carry Flag(BCD)
            Bit 6 -> Subtraction Flag(BCD)
            Bit 7 -> Zero Flag

*/

#ifndef REGISTER
#define REGISTER

#include <iostream>
#include <iomanip>
#include <cstdint>

struct Register{
    union {
        uint16_t af;
        struct {uint8_t f; uint8_t a;} ;
        
    } ;

    union {
        uint16_t bc;
        struct {uint8_t c; uint8_t b;} ;
        
    } ;

    union {
        uint16_t de;
        struct {uint8_t e; uint8_t d;} ;
        
    } ;

    union {
        uint16_t hl;
        struct {uint8_t l; uint8_t h;} ;
        
    } ;

    uint16_t sp; // stack pointer
    uint16_t pc; // program counter

    // flags
    bool zf = 0;
    bool nf = 0;
    bool hf = 0;
    bool cf = 0;

};



#endif