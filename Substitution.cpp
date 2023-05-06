#include <iostream>
#include <regex>

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

std::string strplainNciph(std::string key, std::string corp, bool tocorp){
    std::string ret;
    if (key.length() != 26){
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

int main(){
    std::cout << strplainNciph("qwertyuioplkjhgfdsazxcvbnm", "bigman", true);
    std::cout << strplainNciph("qwertyuioplkjhgfdsazxcvbnm", "WOUJQH", false);
    return 5;
}