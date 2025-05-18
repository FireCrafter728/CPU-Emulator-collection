# CEC(CPU Emulator Collection)

## Content table

- CEC-6502: 6502 CPU Emulator
- CEC-65C02: 6502 CMOS Version Emulator
- CEC-CX16: Commander X16 Emulator
- CEC-8086: 8086 CPU Emulator
- CEC-i386: Intel 386 CPU Emulator
- CEC-x86_64: x86_64 CPU Emulator

## CEC-6502

- Under developement
- Firmware: firmware/6502.fd
- Program: output/bin/cec-6502

### Disclaimers

- The Cycle counting is not fully implemented, missing or too much cycles on some instructions
- The emulator exits after encountering an illegal instruction or a RTS instruction with the stack being clear
- The emulator is experimental, may contain bugs.

# Other CPU's not mentioned are NOT implemented or under developement
