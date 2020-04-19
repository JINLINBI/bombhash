#pragma once
#include <vector>
#include <map>
#include <iostream>
#include "binary_operations.hpp"


#define TREE_ORIGINAL_TYPE 1

class RestrictTree {
    public:
        RestrictTree();
        ~RestrictTree();

    public:
        void add(uint8_t type, uint8_t value);

    public:
        size_t get_positive_bit_size(uint8_t type, bool positive = true);
        size_t get_bit_size(uint8_t type);

        size_t get_size(uint8_t type);

    public:
        uint8_t operator[](size_t index);
        void swap(uint8_t type, std::vector<uint8_t>& rhs);
        
    public:
        std::map<uint8_t, size_t> m_positive_size;
        std::map<uint8_t, std::vector<uint8_t> > m_data;
};


