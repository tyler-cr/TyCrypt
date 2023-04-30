#include <iostream>
using namespace std;

void shiftplaintocipher(char &plain, int shift){
    plain = toupper(char((tolower(plain)+shift)));
    if (int(plain) > 122) plain = toupper(plain%122 + 96);
}

void shiftciphertoplain(char &cipher, int shift){
    cipher = char((tolower(cipher)-shift));
    if (int(cipher) < 97) cipher = tolower(cipher+26);
}

void entireshift(string& s, int shift, bool poc){
    for(size_t i = 0; i < s.length();i++){
        if(s[i] == char(39)) continue;
        if(isalpha(s[i])){
        if (poc==true) shiftplaintocipher(s[i], shift);
        else shiftciphertoplain(s[i], shift);
        }
    }
}