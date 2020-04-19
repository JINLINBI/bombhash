#include "binary_operations.hpp"

BinaryOperations::BinaryOperations() {

}

BinaryOperations::~BinaryOperations() {

}

BinaryOperations* BinaryOperations::m_instance = nullptr;
BinaryOperations* BinaryOperations::get_instance() {
    if (m_instance == nullptr) {
        m_instance = new BinaryOperations();
    }

    return m_instance;
}

static const uint8_t bit_shift[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
uint8_t BinaryOperations::get_binary_positive_count(uint8_t value, bool positive) {
    uint8_t count = 0;
    for (auto i = 0; i < 8; i++) {
        if ((value & bit_shift[i] == bit_shift[i]) == positive) {
            count++;
        }
    }

    return count;
}

std::string get_int_bdc(uint8_t ch)
{
    std::string bdc;
    switch (ch & 0x0F)
    {
    case 0x01:
        bdc = "1";
        break;
    case 0x02:
        bdc = "2";
        break;
    case 0x03:
        bdc = "3";
        break;
    case 0x04:
        bdc = "4";
        break;
    case 0x05:
        bdc = "5";
        break;
    case 0x06:
        bdc = "6";
        break;
    case 0x07:
        bdc = "7";
        break;
    case 0x08:
        bdc = "8";
        break;
    case 0x09:
        bdc = "9";
        break;
    case 0x0A:
        bdc = "A";
        break;
    case 0x0B:
        bdc = "B";
        break;
    case 0x0C:
        bdc = "C";
        break;
    case 0x0D:
        bdc = "D";
        break;
    case 0x0E:
        bdc = "E";
        break;
    case 0x0F:
        bdc = "F";
        break;
    case 0x00:
        bdc = "0";
        break;
    }

    return bdc;
}

std::string BinaryOperations::int_to_bdc(uint8_t value) {
    std::string bdc;

    bdc += get_int_bdc(value >> 4);
    bdc += get_int_bdc(value);
    return bdc;
}



// void BinaryOperations::print_hex(uint8_t c)
// {
//     __printhex(c >> 4);
//     __printhex(c);
// }

// void BinaryOperations::print_binary(uint8_t ch)
// {
//     for (int i = 7; i >= 0; --i)
//     {
//         if (ch & (1 << i))
//             cout << "1";
//         else
//             cout << "0";
//     }
// }

// int BinaryOperations::count_binary_positive(uint8_t ch, bool positive)
// {
//     int count = 0;
//     for (int i = 7; i >= 0; --i)
//     {
//         if (ch & (1 << i) == positive) {
//             count++;
//         }
            
//     }

//     return count;
// }

// void BinaryOperations::print_binary_cmp(uint8_t a, uint8_t b)
// {
//     string gray = "\033[30m";
//     string red = "\033[31m";
//     string green = "\033[32m";
//     string yellow = "\033[33m";
//     string blue = "\033[34m";
//     string endcolor = "\033[0m";
//     string color;

//     for (int i = 7; i >= 0; --i)
//     {
//         if ((a & 1 << i) == (b & 1 << i))
//         {
//             color = gray;
//         }
//         else
//         {
//             color = blue;
//         }

//         cout << color;
//         (b & 1 << i) ? cout << "1" : cout << "0";
//         cout << endcolor;
//     }
//     cout << " ";
// }

// bool BinaryOperations::cmp_binary(uint8_t a, uint8_t b, short level)
// {
//     short mistake = 0;
//     for (int i = 0; i < 8; ++i)
//     {
//         if ((a & (1 << i)) != (b & (1 << i)))
//             ++mistake;

//         if (mistake == level)
//             return false;
//     }

//     return true;
// }

// ex_binary_t BinaryOperations::analyse_binary(uint8_t *p, size_t len)
// {
//     ex_binary_t result;
//     memset(&result, 0, sizeof(result));

//     result.len = len;
//     result.black = 0;
//     result.white = 0;
//     result.most_len[0] = 1;
//     result.most_len[1] = 1;
//     result.avg_len[0] = 0;
//     result.avg_len[1] = 0;

//     bool _inblack = true, inblack = true;
//     size_t index = 0;
//     size_t most_len = 0;

//     while (index < len)
//     {
//         // FIXME: optimize code
//         for (int i = 8; i > 0; --i)
//         {
//             inblack = p[index] & 1 << (i - 1) ? true : false;
//             inblack ? ++result.black : ++result.white;
//             inblack ? cout << "1" : cout << "0";

//             //1->0 or 1->0 or block end
//             if (_inblack != inblack || (index == len - 1 && i == 0))
//             {
//                 if (result.most_len[_inblack] < most_len)
//                 {
//                     result.most_len[_inblack] = most_len;
//                 }
//                 _inblack = inblack;
//                 most_len = 1;
//             }
//             else
//             {
//                 ++most_len;
//             }
//         }
//         cout << " ";
//         if (index++ % 8 == 0)
//             cout << endl;
//     }
//     cout << endl;

//     return result;
// }
