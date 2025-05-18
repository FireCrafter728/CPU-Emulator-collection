#include <6502.hpp> 
#include <utils.hpp>
#include <fstream>

using namespace _6502;

int main(int argc, char** argv) {

    if(argc < 2) {
        std::cout << "Syntax: " << argv[0] << " <Input file>" << std::endl;
        return 1;
    }

    Args args = utils::parseArgs(argc, argv);
    std::ifstream Firmware(args.firmwareFile);
    if(!Firmware.is_open()) {
        std::cout << "Failed to open firmware file" << std::endl;
        return 2;
    }

    std::ifstream Program(args.inputFile);

    if(!Program.is_open()) {
        std::cout << "Failed to open input file" << std::endl;
        return 2;
    }

    CPU cpu;

    utils::LoadMem(Firmware, Program, &cpu);

    cpu.Run();

    utils::PrintRegs(cpu);

    return 0;
}
