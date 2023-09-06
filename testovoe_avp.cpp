//
//  testovoe_avp.cpp
//  test
//
//  Created by mcbk on 05.09.2023.
//
#include <iostream>
#include "testovoe_avp.h"
short getdata(char *buf, int start, int len) {
    short result = 0;
    if (len > 16)
        throw std::length_error("bad length");
    if (buf ) {
        //byte index
        int i = start / 8;
        //buf bit index
        int buff_i = start % 8;
        //result bit index
        int res_i = 0;
        for (int counter = 0; counter < len - 1; ++counter) {
            if (buf[i] & (1 << buff_i))
                result |= (1 << res_i);
            ++res_i;
            ++buff_i;
            if (buff_i > 7) {
                buff_i = 0;
                ++i;
            }
        }
        if (buf[i] & (1 << buff_i))
            result *= -1;
    }
    return result;
}
void putdata(char *buf, int start, int len, short value) {
    if (buf) {
        //byte index
        int i = start / 8;
        //buf bit index
        int buff_i = start % 8;
        //value bit index
        int val_i = 0;
        bool neg_flag = false;
        if (value < 0) {
            neg_flag = true;
            value *= -1;
        }
        for (int counter = 0; counter < len - 1; ++counter) {
            
            if (value & (1 << val_i))
                buf[i] |= (1 << buff_i);
            ++buff_i;
            ++val_i;
            if (buff_i > 7) {
                buff_i = 0;
                ++i;
            }
        }
        if (neg_flag) {
            buf[i] |= (1 << buff_i);
        }
    }
}

//----------------------------2--------------------------------------


short Parser::getdata(int start, int len) {
    short result = 0;
    if (len > 16)
        throw std::length_error("bad length");
    if (data_ ) {
        //byte index
        int i = start / 8;
        //buf bit index
        int buff_i = start % 8;
        //result bit index
        int res_i = 0;
        for (int counter = 0; counter < len - 1; ++counter) {
            if (data_[i] & (1 << buff_i))
                result |= (1 << res_i);
            ++res_i;
            ++buff_i;
            if (buff_i > 7) {
                buff_i = 0;
                ++i;
            }
        }
        if (data_[i] & (1 << buff_i))
            result *= -1;
    }
    return result;
}


void Parser::putdata(int start, int len, short value) {
    if (data_) {
        //byte index
        int i = start / 8;
        //buf bit index
        int buff_i = start % 8;
        //value bit index
        int val_i = 0;
        bool neg_flag = false;
        if (value < 0) {
            neg_flag = true;
            value *= -1;
        }
        for (int counter = 0; counter < len - 1; ++counter) {
            
            if (value & (1 << val_i))
                data_[i] |= (1 << buff_i);
            ++buff_i;
            ++val_i;
            if (buff_i > 7) {
                buff_i = 0;
                ++i;
            }
        }
        if (neg_flag) {
            data_[i] |= (1 << buff_i);
        }
    }
}

void print_data (char* buf) {
    for (int i = 31; i >= 0; --i) {
        (buf[i / 8] & (1 << i % 8)) ? std::cout << '1' : std::cout << '0';
        if (i % 8 == 0)
            std::cout << ' ';
    }
    std::cout <<'\n';
}

