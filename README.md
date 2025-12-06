# Gameboy Emulator

An emulator for the Nintendo Gameboy written in C++

Components

- CPU: **Sharp SM83**


## The big picture

How do we even approach building an emulator for the Gameboy? Remember that emulation is the process of developing software that models the function of some hardware component. To begin writing an emulator, a good place to start would be to emulate the CPU, the core component of any computer. 

The CPU is responsible for executing instructions that are stored in memory. To do this, it leverages small memory storage units called registers. While registers can range in size(8-bit, 16-bit, etc.), the CPU used in the Nintendo Gameboy uses 8-bit general purpose registers and 16-bit stack pointer and program counter registers. All this means is that the data stored in the general purpose registers are 8-bit and the data stored in the stack pointer and program counter registers are 16-bit. Let's suppose you wanted to perform an instruction like ADD A, B. ADD A, B is an assembly language instruction that takes the value stored in register A and register B, and stores the addition of both values in register A. For this particular instruction, the numbers would be represented in 8-bit due to the size of the register. In this way, the general purpose registers can be used for many such instructions.

This further means that the Gameboy has 16-bit addressses and 8-bit data, a feature that will be important in designing the CPU.


### The BootROM

The Boot ROM is the piece of code that tells the Gameboy how to boot up. Before the Gameboy can load the code from the game cartridge, it needs to have the device "prepared" so that it can even accept the code. This is because once the Gameboy has been powered off, there is effectively garbage stored in memory which would affect how the game would load if it references those garbage values once it powers on again. The initial reset/setup is what the BootROM provides and it includes instructions such as reseting the stack pointer, clearing the VRAM, etc. All of the instructions in the BootROM setup the Gameboy so that it can load the game's cartridge effectively. I was able to get the actual BootROM file used on the Gameboy at following link maintained by nitro2k01: https://gbdev.gg8.se/files/roms/bootroms/. 
