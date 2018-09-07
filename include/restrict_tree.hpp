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
        restrict_node root;

    public:
        restrict_tree();
        ~restrict_tree();
        bool add(uint8_t);
        bool dec(uint8_t);
        size_t count();
        void print();

    private:
        bool deletechild(restrict_node*);
        bool deleteable(restrict_node*);
        void traversal(vector<int>&, restrict_node*);
};
