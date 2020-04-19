#include "hash_generator.hpp"

HashGenerator* HashGenerator::m_instance = nullptr;


HashGenerator* HashGenerator::get_instance() {
    if (m_instance == nullptr) {
        m_instance = new HashGenerator();
    }

    return m_instance;
}