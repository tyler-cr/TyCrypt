#include "Nihilist.cpp"
#include <iostream>
#include<string>
#include "Shift.cpp"
using namespace std;

string readFileAsString(const string& filename) {
    ifstream infile(filename);
    string file_contents;
    string line;
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
bool nihcharsolve(vector<vector<char>> key) {
    string pin;
    cout << "Insert possible key char combo (KEY:char) \n";
    cin >> pin;
    cout<< key[0][0]<< "\n";
    int a,b;
    a = int(pin[0]) - '0';
    b = int(pin[1]) - '0';

    cout<< a << " "<< b<<"\n";
    if (key[a][b] == *pin.rbegin()) {
        cout << "TRUE\n";
        return true;
    }
    else {
        cout << "FALSE\n";
        return false;
    }
}

bool shiftsolve(int key){
    char pin;
    cout << "Insert possible key value:\n";
    cin >> pin;
    if (int(pin)-'0' == key) return true;
    return false;
}

void changecharinstring(string& s, int loc, char ch){
    s[loc] = ch;
}

int main(){
    srand(time(0));
    string test = "Dear self, If you read this you're still here. But right now, I don't know the chances of that. When you sit in your room you mope and are bitter of the world, as though it owes you anything. And when you try to be better and push yourself to work hard on whatever it is you want to, you look internally, and are even more bitter at yourself. I don't know what you expect of yourself, but you never seem to find it. And life without any sort of that satisfaction doesn't seem like much of a life to live. Even writing this you'd expected this to come off better. Anyway, let me know if anything did get better, if you do read this. Finding a job has been difficult. But at least you haven't settled yet. It may seem like it more often than not, but the hand you've been dealt in the past isn't your fault, and you've tried your hardest making the most of it. You still have family. You still have friends. But even then, I hope the loneliness escapes you, whether through working through it internally and reaching out to someone. Everyone says to everyone that they're loved, so it may not mean much if at all, but it doesn't mean it isn't true. At least for you. Hope you have a good rest of your day if this finds you. September 22.";
    cout<<test;
    cout<<'\n'<<char(39);
    entireshift(test,5,true);
    cout<<test;
    entireshift(test,5,false);
    cout<<test;

    
    return 0;    
}