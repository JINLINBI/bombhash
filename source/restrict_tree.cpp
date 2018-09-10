#include <iostream>
#include <vector>
#include <ctime>
#include <sys/time.h>
#include "restrict_tree.hpp"
using namespace std;

restrict_node::restrict_node(){
    left = NULL;
    right = NULL;
    value = 0;
}


restrict_node::~restrict_node(){
    if(left){
        delete left;
        left = NULL;
    }

    if(right){
        delete right;
        right = NULL;
    }
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

    ++_size;
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
            if(i == 0 && next->value == 1){
                //delete c
                node = &root;
                next = NULL;
                for(int i = 7; i >= 0; --i){
                    next = (c & 1 << i)? node->left: node->right;
                    if(deleteable(next)){
                        (c & 1 << i)? node->left = NULL: node->right = NULL;
                    }

                    if(node->right == NULL && node->left == NULL && node != &root){
                        delete node;
                    }

                    node = next;
                }
                --_size;
            }
            else if(i == 0 && next->value > 1){
                --next->value;
                --_size;
            }
            else{
                node = next;
                continue;
            }
        }
    }

    return true;
}


size_t restrict_tree::count() const{
    return true;
}


void restrict_tree::clear() {
    return;
}


uint8_t restrict_tree::getrandom(unsigned name){
    uint8_t result = 0;
    size_t color;

    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand((unsigned)tv.tv_usec);
    restrict_node* node = &root;
    for(int i = 7; i >= 0; --i){
        color = rand() % 2;
        if(color){
            if(node->left){
                result |= 1 << i;
                node = node->left;
            }
            else if(node->right){
                node = node->right;
            }
            else{
                return 0;
            }
        }
        else{
            if(node->right){
                node = node->right;
            }
            else if(node->left){
                result |= 1 << i;
                node = node->left;
            }
            else{
                return 0;
            }
        }
    }
    dec(result);

    return result;
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
