#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#include "macros.hpp"
#include "filefunc.hpp"
using namespace std;


void inprinthex(uint8_t ch);
void printhex(uint8_t ch);
void printBinary(uint8_t ch);
void printBinaryCmp(uint8_t, uint8_t);
int  countBinary(uint8_t ch);
bool cmpBinary( uint8_t a,  uint8_t b, short level);


void inprinthex(uint8_t ch){
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

void printhex(uint8_t c){
    inprinthex(c >> 4);
    inprinthex(c);
}


void printBinary(uint8_t ch){
    for(int i = 7; i >= 0; --i){
        if(ch & (1 << i))
            cout << "1";
        else
            cout << "0";
    }
}

int countBinary(uint8_t ch){
    int count = 0;
    for(int i = 7; i >= 0; --i){
        if(ch & (1 << i))
            count++;
    }

    return count;
}

void printBinaryCmp(uint8_t a, uint8_t b){
    string gray     = "\033[30m";
    string red      = "\033[31m";
    string green    = "\033[32m";
    string yellow   = "\033[33m";
    string blue     = "\033[34m";
    string endcolor = "\033[0m";
    string color;

    for(int i = 7; i >= 0; --i){
        if((a & 1 << i) == (b & 1 << i)){
            color = gray;
        }
        else{
            color = blue;
        }

        cout << color;
        (b & 1 << i)? cout << "1": cout<< "0";
        cout << endcolor;
    }
    cout << " ";

}

bool cmpBinary(uint8_t a, uint8_t b, short level){
    short mistake = 0;
    for(int i = 0; i < 8; ++i){
        if((a &= (1 << i)) !=  (b &= (1<< i)))
            ++mistake;

        if(mistake == level)
            return false;
    }

    return true;
}


ex_binary_t analyseBinary(uint8_t* p, size_t len){
    ex_binary_t result;
    memset(&result, 0, sizeof(result));

    result.len = len;
    result.black = 0;
    result.white = 0;
    result.most_len[0] = 1;
    result.most_len[1] = 1;
    result.avg_len[0] = 0;
    result.avg_len[1] = 0;

    bool _inblack = true, inblack = true;
    size_t index = 0;
    size_t most_len = 0;

    while( index < len ){
        // FIXME: optimize code
        for(int i = 8; i > 0; --i){
            inblack = p[index] & 1 << (i - 1)? true: false;
            inblack? ++result.black: ++result.white;
            inblack? cout << "1": cout << "0";

            //1->0 or 1->0 or block end
            if(_inblack != inblack || (index == len - 1 && i == 0)){
                if(result.most_len[_inblack] < most_len){
                    result.most_len[_inblack] = most_len;
                }
                _inblack = inblack;
                most_len = 1;
            }
            else{
                ++most_len;
            }

        }
        cout << " ";
        if(index++ % 8 == 0)cout << endl;
    }
    cout << endl;

    return result;
}
