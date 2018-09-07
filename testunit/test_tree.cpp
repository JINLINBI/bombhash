#include "restrict_tree.hpp"


int main(int argc, char* argv[]){
    uint8_t c = 0x34;
    restrict_tree tree;
    tree.add(c);
    tree.add(0x77);
    tree.dec(c);
    tree.print();

    return 0;
}
