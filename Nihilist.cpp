#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include<vector>
#include <regex>
#include <numeric>
#include <random>
#include <algorithm>
using namespace std;

vector<vector<char> > tdsquarevector(int size){
    return vector<vector<char>>(size, vector<char>(size, '0'));
}

string plaintociph(vector<vector<char> > key, char letter){
    for (size_t i = 0; i<key.size();i++){
        for (size_t j = 0; j<key.size();j++){
            if (key[i][j] == letter){
            return to_string(i)+to_string(j);
            }
        }
    }
    return "ERROR: failed to encrypt";
}

string stringplaintociph(vector<vector<char> > key, string plain){
    string retstr;
    for (size_t i = 0; i <plain.length();i++){
        retstr+=plaintociph(key,plain[i])+' ';
    }
    return retstr;
}

char ciphtoplain(vector<vector<char> > key, string number){
    int row = number[0] - '0';
    int col = number[1] - '0';
    return key[row][col];
}

string stringciphtoplain(vector<vector<char> > key, string numbers){
    string retstr;
    for (size_t i = 0; i<numbers.length();i++){
        if (numbers[i+1] != ' ' && numbers[i] != ' ') {
            retstr += ciphtoplain(key, numbers.substr(i,2));
        }
    }
    return retstr;
} 

vector<vector<char> > generaterandomcipher(int size){
    static vector<int> ascii{97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,
                117,118,119,120,121,122};
    static vector<int> ciph(size*size);
    iota(ciph.begin(),ciph.end(),0);
    vector<vector<char> > retvec = tdsquarevector(size); // initialize size of retvec to size*size
    shuffle(ascii.begin(),ascii.end(), default_random_engine(rand()));
    shuffle(ciph.begin(),ciph.end(), default_random_engine(rand()));
    for (size_t i = 0; i<ascii.size();i++){
        retvec[ciph[i]/size][ciph[i]%size] = static_cast<char>(ascii[i]);
    }
    return retvec;
}

vector<int> zeroindexvec(vector<vector<char> >key){
    static vector<int> retvec(key.size()*key.size()-26);
    int k = 0;
    for (size_t i=0; i<key.size(); i++){
        for (size_t j=0; j<key.size();j++){
            if (key[i][j] == '0') retvec[k]= i*10+j;
            k+=1;
        }
    }
    return retvec;
}

string printodvector(vector<auto> vec){
    string retstr;
    for (size_t i= 0; i < vec.size(); i++){
        retstr+= to_string(vec[i]);
        retstr+= " ";
    }
    retstr += "\n";
    return retstr;
}
string printtdvector(vector<vector<auto> > vec){
    string retstr;
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