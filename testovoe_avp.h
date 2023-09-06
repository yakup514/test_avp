//
//  testovoe_avp.hpp
//  test
//
//  Created by mcbk on 05.09.2023.
//

#ifndef testovoe_avp_h
#define testovoe_avp_h

#include <stdio.h>
//----------------------------1-------------------------------------
short getdata(char *buf, int start, int len);
void putdata(char *buf, int start, int len, short value);

//----------------------------2--------------------------------------

class Parser {
    char* data_;
    
public:
    Parser(char* data) : data_{data}{};
    Parser( Parser& p, int shift) : data_{p.data_ + shift}{};
    char* GetHead() {return data_;}
    char* GetFix() {return data_ + 10;}
    char* GetVar() {return data_ + 16;}
    short getdata(int start, int len);
    void putdata(int start, int len, short value);
    
};



void print_data (char* buf);
#endif /* testovoe_avp_hpp */
