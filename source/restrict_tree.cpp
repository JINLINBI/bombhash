#include <iostream>
#include <vector>
#include "restrict_tree.hpp"
using namespace std;

restrict_node::restrict_node(){
    left = NULL;
    right = NULL;
    value = 0;
}


restrict_node::~restrict_node(){
}

/////////////////////////////////////////////////////////////////////////////
//restrict_tree   functions
restrict_tree::restrict_tree(){
    root.left = NULL;
    root.right = NULL;
}


restrict_tree::~restrict_tree(){
    deletechild(&root);
}


bool restrict_tree::add(uint8_t c){
    restrict_node* node = &root;
    restrict_node* next;

    for(int i = 7; i >= 0; --i){
        next = (c & 1 << i)? node->left: node->right;
        if(next == NULL){
            next = new restrict_node;
            if(next == NULL) return false;
            (c & 1 << i)? node->left = next: node->right = next;
            node = next;
        }
        else{
            node = next;
        }

        if(i == 0){
            ++node->value;
        }
    }

    return true;
}


bool restrict_tree::dec(uint8_t c){
    restrict_node* node = &root;
    restrict_node* next;

    for(int i = 7; i >= 0; --i){
        next = (c & 1 << i)? node->left: node->right;
        if(next == NULL){
            return false;
        }
        else{
            if(next->value == 1){
                //delete c
                node = &root;
                next = NULL;
                for(int i = 7; i >= 0; --i){
                    next = (c & 1 << i)? node->left: node->right;
                    if(deleteable(next)){
                        (c & 1 << i)? node->left = NULL: node->right = NULL;
                        node = next;
                        delete next;
                    }
                }
                break;
            }
            else if(next->value > 1){
                --next->value;
                break;
            }
            node = next;
            continue;
        }
    }

    return true;
}


size_t restrict_tree::count(){

    return true;
}

void restrict_tree::print(){
    vector<int> v;
    if(root.right){
        v.push_back(0);
        traversal(v, root.right);
        v.pop_back();
    }

    if(root.left){
        v.push_back(1);
        traversal(v, root.left);
        v.pop_back();
    }
}

bool restrict_tree::deletechild(restrict_node* child){
    if(child->value > 0){
        return true;
    }

    if(child->right){
        deletechild(child->right);
        delete child->right;
    }

    if(child->left){
       deletechild(child->left);
       delete child->left;
    }

    return false;
}

void restrict_tree::traversal(vector<int>& v, restrict_node* node){
    if(v.size() == 8){
        for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
            cout << *it;
        }
        cout << " ";
        return;
    }

    if(node->right){
        v.push_back(0);
        traversal(v, node->right);
        v.pop_back();
    }

    if(node->left){
        v.push_back(1);
        traversal(v, node->left);
        v.pop_back();
    }

    return;
}

bool restrict_tree::deleteable(restrict_node* child){
    if(child->right && child->left)
        return false;

    if(child->right == NULL && child->left == NULL)
        return true;

    if(child->right && child->left == NULL)
        return deleteable(child->right);

    if(child->left && child->right == NULL)
        return deleteable(child->left);

    return true;
}
