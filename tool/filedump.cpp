#include <iostream>
#include <fstream>
#include <cstring>
#include "binary_operations.hpp"
#include "restrict_tree.hpp"

#define TREE_ORIGINAL_TYPE 1
#define TREE_HASH_TYPE 2


#define BYTE_BIT_SIZE 8
int main(int argc, char *argv[])
{

    char *file = argv[1];
    if (argc < 2)
    {
        std::cout << "usage: " << file << " filename\n";
        exit(0);
    }

    std::fstream fin(file);
    uint8_t c;
    RestrictTree tree;
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin >> c;
            tree.add(TREE_ORIGINAL_TYPE, c);
        }
    }

    // size_t len = tree.get_size(TREE_ORIGINAL_TYPE);
    // for (size_t i = 0; i < len; i++) {
    //     std::string bdc = BinaryOperations::get_instance()->int_to_bdc(tree[i]);
    //     std::cout << bdc;
    //     if (i % BYTE_BIT_SIZE == BYTE_BIT_SIZE - 1) {
    //         std::cout << std::endl;
    //     }
    // }
    fin.close();

    std::cout << std::endl;
    std::cout << "file positive bit size: " << tree.get_positive_bit_size(TREE_ORIGINAL_TYPE) << std::endl;
    std::cout << "file bit size: " << tree.get_bit_size(TREE_ORIGINAL_TYPE) << std::endl;

    return 0;
}
