#include <iostream>
#include "cssshark.hpp"
#include <string>

int main(int argc, char* argv[]){
    for(int c = 1; c < argc; c++){
        cssd(argv[c], (std::string(argv[c]) + std::string(".out.css")).c_str());
    }
    return 0;
}
