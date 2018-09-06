#include <iostream>
#include <fstream>
#include <cstring>
#include "filefunc.hpp"
using namespace std;

int main(int argc, char* argv[]){

    int line = 8;
    char* file = argv[1];

    if(argc == 3 &&  *argv[1] == '-'){
        if(strcmp(argv[1], "-x") == 0){
            line = 16;
            file = argv[2];
        }
        else{
            cout << "usage: ./test [-x] filename\n";
            exit(0);
        }
    }

    if(argc < 2){
        cout << "usage: ./test [-x] filename\n";
        //cout << "    n: bytes displayed each line\n";
        exit(0);
    }

    fstream myfile(file);
    uint8_t c;
    int count = 0;
    int bytes = 0;
    if(myfile.is_open()){
        int index = 0;
        while(!myfile.eof()){
            myfile >> c;
            printBinaryCmp(c, c);
            ++bytes;
            if(bytes % line == 0) cout << endl;
        }
    }

    //cout << count << " '1' in " << bytes << " BYTE." <<" TOTAL " << (float)count / (8 * (float)bytes) * 100<< "%" << endl;
    return 0;
}
