#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


void _printhex(char ch);
void printhex(char ch);
void printBinary(char ch);
int countBinary(char ch);

int main2(int argc, char* argv[]){
    if(argc < 2){
        cout << "usage: ./test filename";
        exit(0);
    }
    fstream myfile(argv[1]);
    char ch;
    int count = 0;
    int bytes = 0;
    if(myfile.is_open()){
        int index = 0;
        while(!myfile.eof()){
            myfile >> ch;
            //printBinary(ch);
            count += countBinary(ch);
            ++bytes;

//            cout << " ";
//
//            if(index++ == 8){
//                cout << endl;
//                index = 0;
//            }

        }
    }

    cout << count << " '1' in " << bytes << " BYTE." <<" TOTAL " << (float)count / (8 * (float)bytes) * 100<< "%" << endl;
    return 0;
}

void _printhex(char ch){
    switch(ch & 0x0F){
        case 0x01: cout << "1"; break;
        case 0x02: cout << "2"; break;
        case 0x03: cout << "3"; break;
        case 0x04: cout << "4"; break;
        case 0x05: cout << "5"; break;
        case 0x06: cout << "6"; break;
        case 0x07: cout << "7"; break;
        case 0x08: cout << "8"; break;
        case 0x09: cout << "9"; break;
        case 0x0A: cout << "A"; break;
        case 0x0B: cout << "B"; break;
        case 0x0C: cout << "C"; break;
        case 0x0D: cout << "D"; break;
        case 0x0E: cout << "E"; break;
        case 0x0F: cout << "F"; break;
        case 0x00: cout << "0"; break;
    }
}

void printhex(char ch){
    _printhex(ch >> 4);
    _printhex(ch);
}


void printBinary(char ch){
    for(int i = 7; i >= 0; --i){
        if(ch & (1 << i))
            cout << "1";
        else
            cout << "0";
    }
}


int countBinary(char ch){
    int count = 0;
    for(int i = 7; i >= 0; --i){
        if(ch & (1 << i))
            count++;
    }

    return count;
}
