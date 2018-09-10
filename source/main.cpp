#include <iostream>
#include <cstring>
#include <iomanip>
#include <openssl/sha.h>
#include <stdlib.h>
#include <ctime>
#include <sys/time.h>
#include "macros.hpp"
#include "filefunc.hpp"
#include "hashfunc.hpp"
#include "restrict_tree.hpp"
using namespace std;

int main(int argc, char* argv[]){
    unsigned char b[] = {0x34, 0xfe, 0x78, 0x8f, 0x32,
                                        0x23, 0xe0, 0xb6, 0x78, 0xb2,
                                        0x6a, 0xc2, 0x44, 0x22, 0xd6,
                                        0x22, 0x7a, 0xa1, 0x89, 0x9c};
    unsigned char a[BLOCK] = {0};
    unsigned char *p;

    size_t blackCount = 0;
    restrict_tree tree;
    for(int i = 0; i < BLOCK; ++i){
        blackCount += countBinary(b[i]);
        tree.add(b[i]);
    }


    //ex_binary_t analyse = analyseBinary(b, BLOCK);

    //cout << "analyse.len  : " << analyse.len << endl;
    //cout << "analyse.black: " << analyse.black << endl;
    //cout << "analyse.white: " << analyse.white << endl;
    //cout << "analyse.most_len[0]: " << analyse.most_len[0] << endl;
    //cout << "analyse.most_len[1]: " << analyse.most_len[1] << endl;
    //cout << "analyse.avg_len[0]: " << analyse.avg_len[0] << endl;
    //cout << "analyse.avg_len[1]: " << analyse.avg_len[1] << endl;

    bool pass = false;
    unsigned randnum = 34343;
    srand(randnum);

    int count = 0;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned start = tv.tv_sec;
    while(!pass){
        bool enough = true;
        for(size_t i = 0; i < BLOCK; ++i){
            uint8_t temp_c = tree.getrandom(randnum);
            if(!cmpBinary(temp_c, b[i], 0)){
                enough = false;
                break;
            }
            printBinaryCmp(temp_c, b[i]);
        }
        cout << endl;

        for(int i = 0; i < BLOCK; ++i){
            tree.add(b[i]);
        }
        //count++;
        //if(count == 1000000) break;
        //p = RANDEXHASH(BLOCK, blackCount);
        //p = RANDEXHASH((uint8_t*)"hasdfaserowerw", BLOCK, blackCount);
        //if(p){
        //    bool enough = true;
        //    int index = 0;
        //    for(size_t i = 0; i < BLOCK; ++i){
        //        if(!cmpBinary(p[i], b[i], 2))
        //            enough = false;
        //        printBinaryCmp(p[i], b[i]);
        //        index++;
        //    }

        if(enough){
            pass = true;
            for(size_t i = 0; i < BLOCK; ++i){
                uint8_t temp_c = tree.getrandom(randnum);
                printBinaryCmp(temp_c, b[i]);
            }
            gettimeofday(&tv, NULL);
            unsigned end = tv.tv_sec;
            cout << endl << " using " << end << " seconds." << endl;
            cout << "random = " << randnum << endl;
        }
        //    delete []p;
        //    //for(int i = 0; i < 1024; ++i)
        //    //    cout << "successfully found specific key! :" << hex << (int)a[i] << endl;
        //}
    }

    return 0;
}
