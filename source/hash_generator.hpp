#pragma one
#include <iostream>
#include <vector>

#define BYTE_BIT_SIZE 8
class HashGenerator {
    private:
        HashGenerator();
        ~HashGenerator();

    public:
        static HashGenerator* get_instance();

    public:
        enum {
            generate_type_raw,
            generate_type_narrow,
        };

    public:
        bool init_hash_seed(std::string hash_seed);
        void set_size(size_t);

    public:
        bool generate_hash_data(std::vector<uint8_t>&);
        bool generate_hash_date_raw(std::vector<uint8_t>&);

    private:
        size_t m_generate_size;
        std::string m_hash_seed;

    private:
        static HashGenerator* m_instance;
};

