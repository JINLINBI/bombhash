#pragma once
#include <vector>
#include <map>
#include <iostream>
#include <string>
using namespace std;



class BinaryOperations{
    private:
        BinaryOperations();
        ~BinaryOperations();
    public:
        static BinaryOperations* get_instance();

    public:
        uint8_t get_binary_positive_count(uint8_t value, bool positive = true);

    public:
        std::string int_to_bdc(uint8_t value);
        // void __printhex(uint8_t);
        // void print_hex(uint8_t);
        // void print_binary(uint8_t);
        // void print_binary_cmp(uint8_t, uint8_t);
        // bool cmp_binary(uint8_t, uint8_t, short);
        // int count_binary_positive(uint8_t, bool positive = true);

    public:
    //  analyse_binary(uint8_t *p, size_t len);

    private:
        size_t m_size;
        std::map<uint8_t, std::vector<uint8_t> > m_data;

    private:
        static BinaryOperations* m_instance;
};
