#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>

// Using tdvchar instead of the long typed out std::vector... Saves space, and will likely be used moving forward with this project
using tdvchar = std::vector<std::vector<char> >;

// A function that creates the tdvchar object, given an integer of the size of one side.
tdvchar tdsquarevector(int size){
    return std::vector<std::vector<char>>(size, std::vector<char>(size, '0'));
}

/*
Given a nihilist cipher and a letter character, will return a string in XX format corresponding with the location of the letter 
on the key. Currently returns the cipher value as it's own new string.
*/
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

/*
Utilizing the above function, will loop through the given string, changing each individual char into an integer string representing
the location of the letter on the given key 2d vector. Returns a new string representing the encrypred version of the given string.
Am considering changint to changing the string itself using its address, or making a similar function that does it so there's two options.
*/
std::string stringplaintociph(tdvchar key, std::string plain){
    std::string retstr;
    for (size_t i = 0; i <plain.length();i++){
        retstr+=plaintociph(key,plain[i])+' ';
    }
    return retstr;
}
/*
With a cipher and a string representing the location of a certain character, returns the character in the given position.
*/
char ciphtoplain(tdvchar key, std::string number){
    int row = number[0] - '0';
    int col = number[1] - '0';
    return key[row][col];
}

/*
Given a nihilist key and a string of xx formated numbers, returns a new string that's the decrypted message.
Am considering changint to changing the string itself using its address, or making a similar function that does it so there's two options.
*/
std::string stringciphtoplain(tdvchar key, std::string numbers){
    std::string retstr;
    for (size_t i = 0; i<numbers.length();i++){
        if (numbers[i+1] != ' ' && numbers[i] != ' ') {
            retstr += ciphtoplain(key, numbers.substr(i,2));
        }
    }
    return retstr;
} 

/*
Generates a random hill cipher given int size of one side. This is useful for testing strings and general stuff to do with the basic
cryptography repo.
*/
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

/*
A function not currently being used. Given a nihilist key, returns a vector that holds the location of each '0' character.
Does it in a different implementation than the encryption and decryption does. XY: X is the xth row, and Y is the yth column.
For other functions, the 'XX' index thing I do is 'reading style', where it goes 1,2,3 |NEW ROW| 4,5,6. For sake of possibly 
Implementation later, will keep in near future.
*/
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

/*
A simple for loop function that creates a string that represents a one dimensional vector when printed out to the console.
NOTE: In older versions of c++, using auto in a function argument isn't allowed. If your computer or IDE don't allow for that,
I recommend switching it to char, and possible copying another version with int as well.
*/
std::string printodvector(std::vector<auto> vec){
    std::string retstr;
    for (size_t i= 0; i < vec.size(); i++){
        retstr+= std::to_string(vec[i]);
        retstr+= " ";
    }
    retstr += "\n";
    return retstr;
}

//Same as before, but for a two dimensional vector.
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

/*
Some testing for Nihilist cipher. If you plan on using, above functions, please remember to remove this!
*/