/*
SUBSTITUTION CIPHER
by: Tyler Crimando
*/
#include <iostream>

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