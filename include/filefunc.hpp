#pragma one

typedef struct ex_binary_s{
    size_t len;
    size_t black;
    size_t white;
    short  most_len[2];
    short  avg_len[2];
}ex_binary_t;

void _printhex(uint8_t);
void printhex(uint8_t);
void printBinary(uint8_t);
void printBinaryCmp(uint8_t, uint8_t);
int countBinary(uint8_t);
bool cmpBinary(uint8_t, uint8_t, short);
ex_binary_t analyseBinary(uint8_t*, size_t);
