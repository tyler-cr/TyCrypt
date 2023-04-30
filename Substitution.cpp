#include <iostream>
#include <regex>
using namespace std;

char plainNciph(string key, char let, bool tocorp){
        if (key.length() != 26){
            cout<< "key is not long enough";
            return '\0';
        }
        if (tocorp == true){
            return toupper(key[int(let)%96-1]);
        }
        else{
            return char(key.find(tolower(let))+97);
        }
}

string strplainNciph(string key, string corp, bool tocorp){
    string ret;
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
    cout << strplainNciph("qwertyuioplkjhgfdsazxcvbnm", "bigman", true);
    cout << strplainNciph("qwertyuioplkjhgfdsazxcvbnm", "WOUJQH", false);
    return 5;
}