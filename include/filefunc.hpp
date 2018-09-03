#pragma one

typedef struct ex_binary_s{
    size_t len;
    size_t black;
    size_t white;
    short  most_len[2];
}ex_binary_t;

void _printhex(char ch);
void printhex(char ch);
void printBinary(char ch);
int countBinary(char ch);
bool cmpBinary(unsigned char a, unsigned char b, short level);
ex_binary_t analyseBinary(unsigned char*, size_t);
