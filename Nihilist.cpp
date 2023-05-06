#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <regex>
#include <numeric>
#include <random>
#include <algorithm>

using tdvchar = std::vector<std::vector<char> >;

tdvchar tdsquarevector(int size){
    return std::vector<std::vector<char>>(size, std::vector<char>(size, '0'));
}

std::string plaintociph(tdvchar key, char letter){
    for (size_t i = 0; i<key.size();i++){
        for (size_t j = 0; j<key.size();j++){
            if (key[i][j] == letter){
            return std::to_string(i)+std::to_string(j);
            }
        }
    }
    return "ERROR: failed to encrypt";
}

std::string stringplaintociph(tdvchar key, std::string plain){
    std::string retstr;
    for (size_t i = 0; i <plain.length();i++){
        retstr+=plaintociph(key,plain[i])+' ';
    }
    return retstr;
}

char ciphtoplain(tdvchar key, std::string number){
    int row = number[0] - '0';
    int col = number[1] - '0';
    return key[row][col];
}

std::string stringciphtoplain(tdvchar key, std::string numbers){
    std::string retstr;
    for (size_t i = 0; i<numbers.length();i++){
        if (numbers[i+1] != ' ' && numbers[i] != ' ') {
            retstr += ciphtoplain(key, numbers.substr(i,2));
        }
    }
    return retstr;
} 

tdvchar generaterandomcipher(int size){
    static std::vector<int> ascii{97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,
                117,118,119,120,121,122};
    static std::vector<int> ciph(size*size);
    iota(ciph.begin(),ciph.end(),0);
    tdvchar retvec = tdsquarevector(size); // initialize size of retvec to size*size
    shuffle(ascii.begin(),ascii.end(), std::default_random_engine(rand()));
    shuffle(ciph.begin(),ciph.end(), std::default_random_engine(rand()));
    for (size_t i = 0; i<ascii.size();i++){
        retvec[ciph[i]/size][ciph[i]%size] = static_cast<char>(ascii[i]);
    }
    return retvec;
}

std::vector<int> zeroindexvec(tdvchar key){
    static std::vector<int> retvec(key.size()*key.size()-26);
    int k = 0;
    for (size_t i=0; i<key.size(); i++){
        for (size_t j=0; j<key.size();j++){
            if (key[i][j] == '0') retvec[k]= i*10+j;
            k+=1;
        }
    }
    return retvec;
}

std::string printodvector(std::vector<auto> vec){
    std::string retstr;
    for (size_t i= 0; i < vec.size(); i++){
        retstr+= std::to_string(vec[i]);
        retstr+= " ";
    }
    retstr += "\n";
    return retstr;
}
std::string printtdvector(std::vector<std::vector<auto> > vec){
    std::string retstr;
    for (size_t i = 0; i < vec.size(); i++)
{
    for (size_t j = 0; j < vec[i].size(); j++)
    {
        retstr += vec[i][j];
        retstr += " ";
    }
    retstr += "\n";
}
return retstr;
}

int main(){
    srand(time(NULL));
    std::string test = "ayoololtest";
    tdvchar cipher = generaterandomcipher(6);
    std::cout<<printtdvector(cipher);
    std::cout<<test;
    test = stringplaintociph(cipher, test);
    std::cout<<test;
    test = stringciphtoplain(cipher, test);
    std::cout<<test;


    return 0;
}