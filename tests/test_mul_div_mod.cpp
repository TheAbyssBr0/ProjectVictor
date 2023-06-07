#include "gtest/gtest.h"
#include "u_very_long.hpp"

TEST(MulTest, MulTest1) {
    u_very_long x(0, 0);
    u_very_long y(123, 456);

    u_very_long expected(0, 0);
    EXPECT_TRUE(x * y == expected);
    x *= y;
    EXPECT_TRUE(x == expected);
}

TEST(MulTest, MulTest2) {
    u_very_long x(0, 1);
    u_very_long y(123, 456);

    EXPECT_TRUE(x * y == y);
    x *= y;
    EXPECT_TRUE(x == y);
}

TEST(MulTest, MulTest3) {
    u_very_long x(0, 2);
    u_very_long y(123, 456);

    u_very_long expected(246, 912);
    EXPECT_TRUE(x * y == expected);
    x *= y;
    EXPECT_TRUE(x == expected);
}

TEST(MulTest, MulTest4) {
    u_very_long x(0, 8);
    u_very_long y(123, 456);

    u_very_long expected(984, 3648);
    EXPECT_TRUE(x * y == expected);
}

TEST(MulTest, MulTest5) {
    u_very_long x(0xF0, 0x01234F2A9C8DB234);
    u_very_long y(0, 0x2193);

    u_very_long expected(0x1F79F6, 0x347AF3A6295607DC);
    EXPECT_TRUE(x * y == expected);
}

TEST(MulTest, MulTest6) {
    u_very_long x(0, 0x1234212335);
    u_very_long y(0, 0x1234272395);

    u_very_long expected(0x14B, 0x5FB3ADA6002CBCD9);
    EXPECT_TRUE(x * y == expected);
}

TEST(DivTest, DivTest1) {
    u_very_long x(1, 12329232);
    u_very_long y(0, 1);

    u_very_long z = x / y;
    EXPECT_TRUE(z == x);
}

TEST(DivTest, DivTest2) {
    u_very_long x(12, 1234);
    u_very_long y(12, 1234);

    u_very_long expected(0, 1);
    EXPECT_TRUE(x / y == expected);
}

TEST(DivTest, DivTest3) {
    u_very_long x(0b0100101, 0b01011);
    u_very_long y(0, 2);

    u_very_long expected(0b010010, 
        0b1000000000000000000000000000000000000000000000000000000000000101);
    EXPECT_TRUE(x / y == expected);
}

TEST(DivTest, DivTest4) {
    u_very_long x(0b0100101, 0b01011);
    u_very_long y(0, 8);

    u_very_long expected(0b0100, 
        0b1010000000000000000000000000000000000000000000000000000000000001);
    EXPECT_TRUE(x / y == expected);
}

TEST(DivTest, DivTest5) {
    u_very_long x(123, 456);
    u_very_long y(789, 0);

    u_very_long expected(0, 0);
    EXPECT_TRUE(x/y == expected);
}

TEST(DivTest, DivTest6) {
    u_very_long x(0, 123);
    u_very_long y(1, 0);

    u_very_long expected(0, 0);
    EXPECT_TRUE(x/y == expected);
}

TEST(DivTest, DivTest7) {
    u_very_long x(0x10c9, 0x52eb01580f241cf3);
    u_very_long y(0, 0x7546516c8d7c);

    u_very_long expected(0, 0x24a4ab2f);
    EXPECT_TRUE(x/y == expected);
}

TEST(DivTest, DivTest8) {
    u_very_long x(0x3d97, 0x3b92af365bef47db);
    u_very_long y(0, 0xcb60c6474f34);

    u_very_long expected(0, 0x4d86d798);
    EXPECT_TRUE(x/y == expected);
}

TEST(DivTest, DivTest9) {
    u_very_long x(0x9b45385a, 0xea598100dced438b);
    u_very_long y(0xb5, 0x53be99f3771ceeaf);

    u_very_long expected(0, 0xdb3677);
    EXPECT_TRUE(x/y == expected);
}

TEST(DivTest, DivTest10) {
    u_very_long x(0x107cdf09, 0x7fcdf1db36fa9be6);
    u_very_long y(0xbe, 0xf1904a85dbc5c0af);

    u_very_long expected(0, 0x161af7);
    EXPECT_TRUE(x/y == expected);
}

TEST(DivTest, DivTest11) {
    u_very_long x(0x1fe9991a, 0x5008ef1ba55a6ea7);
    u_very_long y(0x43, 0x4c8f864dc62f66ce);

    u_very_long expected(0, 0x796477);
    EXPECT_TRUE(x / y == expected);
}