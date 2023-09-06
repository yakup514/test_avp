//
//  test.cpp
//  test3
//
//  Created by mcbk on 06.09.2023.
//

#include <iostream>


#include "gtest/gtest.h"
#include "testovoe_avp.h"


TEST(getdata, test1) {
    char* buf = new char(5);
    for (int i = 0; i < 5; i++)
        buf[i] = 0;
    try {
         getdata(buf, 0, 17);
    } catch (const std::length_error& ex) {
        EXPECT_STREQ(ex.what(), "bad length");
    }
    delete buf;
}

TEST(getdata, test2) {
    char* buf = new char(5);
    for (int i = 0; i < 5; i++)
        buf[i] = 0;
    buf[0] = 113;
    short res = getdata(buf, 0, 8);
    EXPECT_EQ(res, 113);
    delete buf;
}

TEST(getdata, test3) {
    char* buf = new char(5);
    for (int i = 0; i < 5; i++)
        buf[i] = 0;
    buf[0] = 113;
    short res = getdata(buf, 0, 7);
    EXPECT_EQ(res, -49);
    delete buf;
}

TEST(getdata, test4) {
    char* buf = new char(5);
    for (int i = 0; i < 5; i++)
        buf[i] = 0;
    buf[0] = 113;
    buf[1] = 113;
    short res = getdata(buf, 4, 5);
    EXPECT_EQ(res, -7);
    delete buf;
}

TEST(putdata, test1) {
    char* buf = new char(5);
    for (int i = 0; i < 5; i++)
        buf[i] = 0;
    buf[0] = 113;
    putdata(buf, 1, 4, 7);
    EXPECT_EQ((int)buf[0], 127);
    delete buf;
}

TEST(putdata, test2) {
    char* buf = new char(5);
    for (int i = 0; i < 5; i++)
        buf[i] = 0;
    putdata(buf, 7, 4, 7);
    EXPECT_EQ((int)buf[0], -128);
    EXPECT_EQ((int)buf[1], 3);
    delete buf;
}
TEST(putdata, test3) {
    char* buf = new char(5);
    for (int i = 0; i < 5; i++)
        buf[i] = 0;
    putdata(buf, 7, 5, -7);
    EXPECT_EQ((int)buf[0], -128);
    EXPECT_EQ((int)buf[1], 11);
    delete buf;
}
TEST(constructor, test1) {
    char* buf = new char(5);
    Parser p(buf);
    delete buf;
}

TEST(constructor, test2) {
    char* buf = new char(5);
    Parser p(buf);
    Parser(p, 1);
    delete buf;
}

TEST(parser_getdata, test1) {
    char* buf = new char(5);
    for (int i = 0; i < 5; i++)
        buf[i] = 0;
    
    Parser p(buf);
    p.putdata(0, 8, 113);
    short res = p.getdata(0, 8);
    EXPECT_EQ(res, 113);
    delete buf;
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

