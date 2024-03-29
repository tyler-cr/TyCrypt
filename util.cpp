#include <iostream>
#include <fstream>
#include <string>


//simple function that removes all non alphanumeric values in string, and changes original string to it
void stringstrip(std::string &str){
    std::string retstr;
    for(size_t i = 0; i< str.length();i++){
        if (isalnum(str[i])) retstr += str[i];
    }
    str = retstr;
}

//simple function that removes all non alphanumeric values in string, and returns new string with changes
std::string newstringstrip(std::string str){
    std::string retstr;
    for(size_t i = 0; i< str.length();i++){
        if (isalnum(str[i])) retstr += str[i];
    }
    return retstr;
}

//simple function for converting txt files to strings
std::string filetostring(std::string filelocation){
    std::ifstream examplefile; examplefile.open(filelocation);
    std::string retstr;
    while (examplefile.good()){
        retstr += examplefile.get();
    }
    return retstr;
}