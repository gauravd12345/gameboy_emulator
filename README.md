# Gameboy Emulator

An emulator for the Nintendo Gameboy written in C++

Components

- CPU: **Sharp SM83**


## The big picture

Where do we even begin thinking about emulating a Gameboy? A good place to start would be to emulate the CPU:


### The BootROM

The Boot ROM is the piece of code that tells the Gameboy how to boot up. Before the Gameboy can load the game's code
