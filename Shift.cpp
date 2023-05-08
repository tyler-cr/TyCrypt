/*
SHIFT CIPHER
by: Tyler Crimando
*/

#include <iostream>

// Given a character and an integer representing how much to shift, changing character to new character.
void shiftplaintocipher(char &plain, int shift){
    plain = toupper(char((tolower(plain)+shift)));
    if (int(plain) > 122) plain = toupper(plain%122 + 96);
}

// Same as above, but the other way around.
void shiftciphertoplain(char &cipher, int shift){
    cipher = char((tolower(cipher)-shift));
    if (int(cipher) < 97) cipher = tolower(cipher+26);
}

/*
Utilizing the above two functions, given a string, an integer representing the shift, and a bool deciding whether to go
from plain to cipher or cipher to plain, does just that. Currently avoids apostrophe, But am plainning on removing in favor
of a 'strip' function that removes all non alphabetic characters from a string.
*/
void entireshift(std::string& s, int shift, bool poc){
    for(size_t i = 0; i < s.length();i++){
        if(s[i] == char(39)) continue;
        if(isalpha(s[i])){
        if (poc==true) shiftplaintocipher(s[i], shift);
        else shiftciphertoplain(s[i], shift);
        }
    }
}