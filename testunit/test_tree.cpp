#include "restrict_tree.hpp"


int main(int argc, char* argv[]){
    uint8_t c = 0x34;
    restrict_tree tree;
    tree.add(c);
    tree.add(0x77);
    tree.add(0x67);
    //tree.dec(c);
    //tree.dec(0x67);
    tree.print();

    return 0;
}
