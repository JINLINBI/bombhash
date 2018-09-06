#include <iostream>
#include <cstring>
#include <iomanip>
#include <openssl/sha.h>
#include <stdlib.h>
#include "macros.hpp"

using namespace std;

bool doHash(uint8_t* a, uint8_t* b){
    static int callTime = 0;
    uint8_t enstr[1024];
    int rand = 0;

    for(int i = 0; i < 16; ++i){
        while(!rand) rand = random();
        enstr[i] = (uint8_t)rand;
        rand = 0;
    }

    //SHA1((uint8_t*)enstr, 16, a);
    cout << "CALL " << dec << callTime << " TIMES: ";

    for(int i = 0; i < 16; ++i){
        switch(enstr[i] & 0xF0){
            case 0x10: cout << "1"; case 0x20: cout << "2"; case 0x30: cout << "3"; case 0x40: cout << "4";
            case 0x50: cout << "5"; case 0x60: cout << "6"; case 0x70: cout << "7"; case 0x80: cout << "8";
            case 0x90: cout << "9"; case 0xA0: cout << "A"; case 0xB0: cout << "B"; case 0xC0: cout << "C";
            case 0xD0: cout << "D"; case 0xE0: cout << "E"; case 0xF0: cout << "F"; }
        switch(enstr[i] & 0x0F){
            case 0x01: cout << "1"; case 0x02: cout << "2"; case 0x03: cout << "3"; case 0x04: cout << "4";
            case 0x05: cout << "5"; case 0x06: cout << "6"; case 0x07: cout << "7"; case 0x08: cout << "8";
            case 0x09: cout << "9"; case 0x0A: cout << "A"; case 0x0B: cout << "B"; case 0x0C: cout << "C";
            case 0x0D: cout << "D"; case 0x0E: cout << "E"; case 0x0F: cout << "F";
        }
    }
    cout << " >> ";
    for(int i = 0; i < SHA_DIGEST_LENGTH; ++i){
        cout << hex << (int)a[i];
    }

    bool hit = true;
    for(int i = 0; i < SHA_DIGEST_LENGTH; ++i){
        if((a[i] & 0xFE) !=  (b[i] & 0xFE)){
            hit = false;
        }
    }
    cout << endl;
    ++callTime;

    return hit;
}

bool parsehash(const uint8_t* hash, int index){
    int result;
    for(int i = 0; i < BLOCK; ++i){
        result += (hash[i] >> 4 | ~hash[i]);
        if( result &= hash[i] ){
            result ^= index ^ 3433;
        }
        else
            result ^= index ^ 3343;
    }

    return result << index % 3;
}


uint8_t* EXHASH(uint8_t* hash, size_t len, size_t black){
    size_t white = len - black;
    uint8_t* p = new uint8_t[len];

    if(!p)
        return NULL;

    int index = 0;
    bool blackColor = false;

    for(size_t i = 0; i < len; ++i){
        for(int bit = 7; bit >= 0; --bit){
            blackColor = parsehash(hash, index);

            if(blackColor && black){
                p[index] |= 1 << bit;
                --black;
            }
            if(blackColor && !black){
                p[index] &= ~(1 << bit);
                --white;
            }
            else if(!blackColor && white){
                p[index] &= ~(1 << bit);
                --white;
            }
            else if(!blackColor && !white){
                p[index] |= 1 << bit;
                --black;
            }
        }
        ++index;
    }

    return p;
}

uint8_t* RANDEXHASH(size_t len, size_t black){
    size_t white = len - black;
    uint8_t* p = new uint8_t[len];

    if(!p)
        return NULL;

    int index = 0;
    bool blackColor = false;

    for(size_t i = 0; i < len; ++i){
        for(int bit = 7; bit >= 0; --bit){
            blackColor = (rand() + 3333) % 2;

            if(blackColor && black){
                p[index] |= 1 << bit;
                --black;
            }
            if(blackColor && !black){
                p[index] &= ~(1 << bit);
                --white;
            }
            if(!blackColor && white){
                p[index] &= ~(1 << bit);
                --white;
            }
            if(!blackColor && !white){
                p[index] |= 1 << bit;
                --black;
            }
        }
        ++index;
    }

    return p;
}
