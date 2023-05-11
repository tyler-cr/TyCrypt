/*
SUBSTITUTION CIPHER
by: Tyler Crimando
*/
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>

/*
Given a string representing a substitution cipher key, returns a new character given character 'let', either changing it to
cipher text (in caps) if tocorp bool is true, or to plaintext (in lower) if false.
*/
char plainNciph(std::string key, char let, bool tocorp){
        if (key.length() != 26){
            std::cout<< "key is not long enough";
            return '\0';
        }
        if (tocorp == true){
            return toupper(key[int(let)%96-1]);
        }
        else{
            return char(key.find(tolower(let))+97);
        }
}

// Same as above, but for a whole string instead of a single character.
std::string strplainNciph(std::string key, std::string corp, bool tocorp){
    std::string ret;
    if (key.length() != 26){
        std::cout<< "key is not long enough";
        return NULL;
    }
    for (int i = 0; i < corp.length(); i++){
        if (corp[i]== ' '){
            continue;
        }
        ret += plainNciph(key, corp[i], tocorp);
    }
    return ret;
}

//simple string generator for testing substitution ciphers.
std::string generaterandomsubscipher(){
    srand(time(0));
    static std::vector<int> ascii{97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,
            117,118,119,120,121,122};
    std::string retstr;
    shuffle(ascii.begin(),ascii.end(), std::default_random_engine(rand()));
    for (size_t i = 0; i < ascii.size();i++){
        retstr+= char(ascii[i]);
    }
    return retstr;

}