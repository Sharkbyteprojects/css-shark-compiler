#include "cssshark.hpp"
#include <fstream>
#include <string>
#include <map>

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

void cssd(const char* filename, const char* out){
    std::ofstream outfile;
    std::ifstream infile;
    infile.open(filename, std::ios::in);
    outfile.open(out, std::ios::out | std::ios::trunc);

    std::map<std::string, std::string> variables;
    std::string line {""};
    bool rstate { false },
     bsta { false };
    std::string lastr {""};
    while (std::getline(infile, line)) {
        if(line==""){ continue; }
        if (line.find("[comment]") != std::string::npos) { continue; }
        if (line.find("[vars]") != std::string::npos) {
            bsta = true;
        } else if (line.find("[lines]") != std::string::npos) {
            bsta = false;
        } else {
            if(bsta){
                if(!rstate){
                    lastr = line;
                }else{
                    variables[lastr] = line;
                }
                rstate = !rstate;
            }else{
                for(std::map<std::string, std::string>::iterator it = variables.begin(); it != variables.end(); ++it) {
                   replace(line, it->first, it->second);
                }
                while(replace(line, "  ", " "));
                while(replace(line, "\t", " "));
                outfile << line;
            }
        }
    }

    outfile << std::flush;
    outfile.close();
    infile.close();
}
