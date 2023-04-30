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

char ciphtoplain(vector<vector<char> > key, string number){
    int row = number[0] - '0';
    int col = number[1] - '0';
    return key[row][col];
}

string plaintociph(vector<vector<char> > key, char letter){
    for (int i = 0; i<key.size();i++){
        auto place = find(key[i].begin(), key[i].end(), letter);
        if (place != key[i].end()){
            return to_string(i) + to_string(key[i][*place]);
        }
    }
    return "LL";
}

string stringciphtoplain(vector<vector<char> > key, string numbers){
    string retstr;
    for (size_t i = 0; i+1<numbers.length();i++){
        if (numbers[i+1] != ' ' && numbers[i] != ' ') {
            retstr += ciphtoplain(key, numbers.substr(i,2));
        }
    }
    return retstr;
} 

string stringplaintociph(vector<vector<char> > key, string plain){
    string retstr;
    for (size_t i = 0; i <plain.length();i++){
        retstr+=plaintociph(key,plain[i])+' ';
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
        cout<<"Attempting to place letter "<<static_cast<char>(ascii[i])<<" into location "<<ciph[i]/10<<ciph[i]%10<<endl;
        retvec[ciph[i]/size][ciph[i]%size] = static_cast<char>(ascii[i]);
    }
    return retvec;
}


int main(){
    srand(time(0));
    vector<vector<char> > ah=generaterandomcipher(6);
    for (size_t i = 0; i < ah.size(); i++)
    {
        for (size_t j = 0; j < ah[i].size(); j++)
        {
            cout << ah[i][j];
        }
    }
    return 0;
}