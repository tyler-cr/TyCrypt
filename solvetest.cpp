/*
SOLVE TEST
by: Tyler Crimando
*/

#include "Nihilist.cpp"
#include <iostream>
#include "Shift.cpp"

/*
WORK IN PROGRESS
Given a string representing a text file, returns a string representing the text, removing newline characcters, all punctuation, and 
converting each letter to lowercase. Considering just returning the string as is, and making a seperate 'string' function that removes
punctuation and non alphanumeric(maybe just alphabetic) characters.
*/
std::string readFileAsString(const std::string& filename) {
    std::ifstream infile(filename);
    std::string file_contents;
    std::string line;
    while (getline(infile, line)) {
        // Remove newline characters from the line
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());

        // Remove all punctuation from the line
    line.erase(remove_if(line.begin(), line.end(), [](char c) {
        return ispunct(c) && c != 0x27;
    }), line.end());

        // Convert the line to lowercase
        transform(line.begin(), line.end(), line.begin(), [](unsigned char c) {
            return tolower(c);
        });

        file_contents += line;
    }
    return file_contents;
}

/*
WORK IN PROGRESS
Given a key, allows user to insert 'XX:char' format string 'guessing' location in nihilist key represented a specific letter.
*/
bool nihcharsolve(std::vector<std::vector<char>> key) {
    std::string pin;
    std::cout << "Insert possible key char combo (KEY:char) \n";
    std::cin >> pin;
    std::cout<< key[0][0]<< "\n";
    int a,b;
    a = int(pin[0]) - '0';
    b = int(pin[1]) - '0';

    std::cout<< a << " "<< b<<"\n";
    if (key[a][b] == *pin.rbegin()) {
        std::cout << "TRUE\n";
        return true;
    }
    else {
        std::cout << "FALSE\n";
        return false;
    }
}

//Very simple function that basically returns true if shift key integer is same as user input.
bool shiftsolve(int key){
    char pin;
    std::cout << "Insert possible key value:\n";
    std::cin >> pin;
    if (int(pin)-'0' == key) return true;
    return false;
}