#include <iostream>
#include <fstream>
#include <string>

std::string filetostring(std::string filelocation){
    std::ifstream examplefile; examplefile.open(filelocation);
    std::string retstr;
    while (examplefile.good()){
        retstr += examplefile.get();
    }
    return retstr;
}