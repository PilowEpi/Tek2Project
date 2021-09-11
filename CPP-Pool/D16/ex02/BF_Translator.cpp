#include "BF_Translator.hpp"

BF_Translator::BF_Translator()
{
    translator['>'] = "ptr++;";
    translator['<'] = "ptr--;";
    translator['+'] = "mem[ptr]++;";
    translator['-'] = "mem[ptr]--;";
    translator['.'] = "putchar(mem[ptr]);";
    translator[','] = "mem[ptr]=getchar();";
    translator['['] = "while (mem[ptr]) {";
    translator[']'] = "}";
}

int BF_Translator::translate(const std::string in, const std::string out)
{
    char current = 0;
    std::fstream inFile;
    std::fstream outFile;

    inFile.open(in, std::ios::in);
    outFile.open(out, std::ios::out);

    if (!inFile || !outFile)
        return 1;
    outFile << "#include <stdio.h>" << std::endl;
    outFile << "int main(void) {" << std::endl;
    outFile << "char mem[61440] = {0};" << std::endl;
    outFile << "int ptr = 0;" << std::endl;
    while (inFile >> current) {
        if (translator.find(current) == translator.end())
            continue;
        outFile << translator[current] << std::endl;
    }
    outFile << "return 0;" << std::endl;
    outFile << "}" << std::endl;
    inFile.close();
    outFile.close();
    return 0;
}