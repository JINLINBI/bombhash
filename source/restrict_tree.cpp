#include "restrict_tree.hpp"
#include "binary_operations.hpp"


RestrictTree::RestrictTree() {

}

RestrictTree::~RestrictTree() {

}

void RestrictTree::add(uint8_t type, uint8_t value) {
    m_data[type].push_back(value);
    m_positive_size[type] += BinaryOperations::get_instance()->get_binary_positive_count(value);
}

size_t RestrictTree::get_positive_bit_size(uint8_t type, bool positive) {
    if (positive) {
        return m_positive_size[type];
    }

    return get_size(type) - m_positive_size[type];
}

size_t RestrictTree::get_bit_size(uint8_t type) {
    return m_data[type].size() * 8;
}

size_t RestrictTree::get_size(uint8_t type) {
    return m_data[type].size();
}

uint8_t RestrictTree::operator[](size_t index) {
    return m_data[TREE_ORIGINAL_TYPE][index];
}

void RestrictTree::swap(uint8_t type, std::vector<uint8_t>& rhs) {
    m_data[type].swap(rhs);
}