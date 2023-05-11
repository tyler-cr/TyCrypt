#include <iostream>

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