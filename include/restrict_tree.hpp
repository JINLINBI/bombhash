#pragma once
#include <vector>
#include <iostream>
using namespace std;

class restrict_node{
    public:
        restrict_node* left;
        restrict_node* right;
        int value;

    public:
    restrict_node();
    ~restrict_node();
};


class restrict_tree{
    public:
        size_t        _size;
        restrict_node root;

    public:
        restrict_tree();
        ~restrict_tree();
        bool add(uint8_t);
        bool dec(uint8_t);
        size_t count() const;
        void print();
        void clear();
        uint8_t getrandom(unsigned);
        size_t size() const {return _size;};

    private:
        bool deletechild(restrict_node*);
        bool deleteable(restrict_node*);
        void traversal(vector<int>&, restrict_node*);
};
