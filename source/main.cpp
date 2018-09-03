#include <iostream>
#include <cstring>
#include <iomanip>
#include <openssl/sha.h>
#include <stdlib.h>
#include "filefunc.hpp"
#include "hashfunc.hpp"
using namespace std;

int main(int argc, char* argv[]){
    unsigned char b[SHA_DIGEST_LENGTH] = {0x34, 0xfe, 0x78, 0x8f, 0x32,
                                        0x23, 0xe0, 0xb6, 0x78, 0xb2,
                                        0x6a, 0xc2, 0x44, 0x22, 0xd6,
                                        0x22, 0x7a, 0xa1, 0x89, 0x9c};
    unsigned char a[SHA_DIGEST_LENGTH] = {0};
    unsigned char *p;

    size_t blackCount = 0;
    for(int i = 0; i < SHA_DIGEST_LENGTH; ++i){
        blackCount += countBinary(b[i]);
    }

    bool pass = false;
    srand(423432423);
    while(!pass){
        p = EXHASH(rand(), SHA_DIGEST_LENGTH, blackCount);
        if(p){
            bool enough = true;
            for(size_t i = 0; i < SHA_DIGEST_LENGTH; ++i){
                if(!cmpBinary(p[i], b[i], 1))
                    enough = false;
                printBinary(p[i]);
                cout << " >> ";
                printBinary(b[i]);
                cout << endl;
            }
            cout << "--------------------------------------------------" << endl;

            if(enough)
                pass = true;

            delete []p;
            //for(int i = 0; i < 1024; ++i)
            //    cout << "successfully found specific key! :" << hex << (int)a[i] << endl;
        }
    }

    return 0;
}
