#include "gtest/gtest.h"
#include "u_very_long.hpp"

TEST(LeftShift, LeftShiftTest1) {
    u_very_long x(0, 1);
    u_very_long expected(0, 2);

    EXPECT_TRUE(x << 1 == expected);

    x <<= 1;
    EXPECT_TRUE(x == expected);
}

TEST(LeftShift, LeftShiftTest2) {
    u_very_long x(0, 0b100100011);
    u_very_long expected(0, 0b10010001100);

    EXPECT_TRUE(x << 2 == expected);
    
    x <<= 2;
    EXPECT_TRUE(x == expected);
}

TEST(LeftShift, LeftShiftTest3) {
    u_very_long x(0b010101, 0b010110);
    u_very_long expected(0b010101000000, 0b010110000000);

    EXPECT_TRUE(x << 6 == expected);
    
    x <<= 6;
    EXPECT_TRUE(x == expected);
}

TEST(LeftShift, LeftShiftTest4) {
    u_very_long x(0, 0x8000000000000000);
    u_very_long expected(1, 0);

    EXPECT_TRUE(x << 1 == expected);
    
    x <<= 1;
    EXPECT_TRUE(x == expected);
}

TEST(LeftShift, LeftShiftTest5) {
    u_very_long x(0, 0x8000000000000000 + 0b01010010);
    u_very_long expected(1, 0b010100100);

    EXPECT_TRUE(x << 1 == expected);
    
    x <<= 1;
    EXPECT_TRUE(x == expected);
}

TEST(LeftShift, LeftShiftTest6) {
    u_very_long x(0b010100001010, 
        0b0100101010010010100101001010101001001010100100101001010010101010);
    u_very_long expected(0b01010000101001001010,
         0b1001001010010100101010100100101010010010100101001010101000000000);

    EXPECT_TRUE(x << 8 == expected);
    
    x <<= 8;
    EXPECT_TRUE(x == expected);
}

TEST(RightShift, RightShiftTest1) {
    u_very_long x(0, 2);
    u_very_long expected(0, 1);

    EXPECT_TRUE(x >> 1 == expected);

    x >>= 1;
    EXPECT_TRUE(x == expected);
}

TEST(RightShift, RightShiftTest2) {
    u_very_long x(0, 0b1010110101);
    u_very_long expected(0, 0b10101101);

    EXPECT_TRUE(x >> 2 == expected);
    
    x >>= 2;
    EXPECT_TRUE(x == expected);
}

TEST(RightShift, RightShiftTest3) {
    u_very_long x(0b100101010, 0b0100100010010);
    u_very_long expected(0b1001, 
        0b0101000000000000000000000000000000000000000000000000000001001000);

    EXPECT_TRUE(x >> 5 == expected);
    
    x >>= 5;
    EXPECT_TRUE(x == expected);
}

TEST(RightShift, RightShiftTest4) {
    u_very_long x(1, 0);
    u_very_long expected(0, 0x8000000000000000);

    EXPECT_TRUE(x >> 1 == expected);

    x >>= 1;
    EXPECT_TRUE(x == expected);
}

TEST(RightShift, RightShiftTest5) {
    u_very_long x(0b10101011, 0);
    u_very_long expected(0b1010101, 0x8000000000000000);

    EXPECT_TRUE(x >> 1 == expected);

    x >>= 1;
    EXPECT_TRUE(x == expected);
}

TEST(RightShift, RightShiftTest6) {
    u_very_long x(0b1010100101010001011, 0b1101010101101);
    u_very_long expected(0b1010100101, 
        0b0100010110000000000000000000000000000000000000000000000000001101);

    EXPECT_TRUE(x >> 9 == expected);

    x >>= 9;
    EXPECT_TRUE(x == expected);
}

// TEST(BitwiseAnd, BitwiseAndTest1) {
//     u_very_long x(0b010101, 0b0100);
//     u_very_long y(0b010010, 0b00101001);

//     u_very_long expected(0b10000, 0);
//     EXPECT_TRUE((x & y) == expected);
// }

// TEST(BitwiseAnd, BitwiseAndTest2) {
//     u_very_long x(0x468f, 0xb43746ca4f8fb8e7);
//     u_very_long y(0x46f, 0x8c1bae2b8cb55c2e);

//     u_very_long expected(0x40f, 0x8413060a0c851826);
//     EXPECT_TRUE((x & y) == expected);
// }

TEST(BitwiseAnd, BitwiseAndTest1) {
    u_very_long x(0b010101, 0b0100);
    u_very_long y(0b010010, 0b00101001);

    u_very_long expected(0b10000, 0);
    EXPECT_TRUE((x & y) == expected);
}

TEST(BitwiseAnd, BitwiseAndTest2) {
    u_very_long x(0x468f, 0xb43746ca4f8fb8e7);
    u_very_long y(0x46f, 0x8c1bae2b8cb55c2e);

    u_very_long expected(0x40f, 0x8413060a0c851826);
    EXPECT_TRUE((x & y) == expected);

    x &= y;
    EXPECT_TRUE(x == expected);
}

TEST(BitwiseOr, BitwiseOrTest1) {
    u_very_long x(0b010101,     0b0100);
    u_very_long y(0b010010, 0b00101001);

    u_very_long expected(0b010111, 0b101101);
    EXPECT_TRUE((x | y) == expected);

    x |= y;
    EXPECT_TRUE(x == expected);
}

TEST(BitwiseOr, BitwiseOrTest2) {
    u_very_long x(0xba3a, 0xd9ad4c7ff79772f3);
    u_very_long y(0xd15, 0x1124028d498d8c45);

    u_very_long expected(0xbf3f, 0xd9ad4effff9ffef7);
    EXPECT_TRUE((x | y) == expected);

    x |= y;
    EXPECT_TRUE(x == expected);
}

TEST(BitwiseNegation, BitwiseNegationTest1) {
    u_very_long x(0, 0xFFFFFFFF);

    u_very_long expected(0xFFFFFFFFFFFFFFFF, 0xFFFFFFFF00000000);
    EXPECT_TRUE((~x) == expected);
}

TEST(BitwiseNegation, BitwiseNegationTest2) {
    u_very_long x(0xBBBBBBBBBBBBBBBB, 0xBBBBBBBBBBBBBBBB);

    u_very_long expected(0x4444444444444444, 0x4444444444444444);
    EXPECT_TRUE((~x) == expected);
}

TEST(BitwiseXor, BitwiseXorTest1) {
    u_very_long x(0b101011, 0b010101);
    u_very_long y(0b010110, 0b001010);

    u_very_long expected(0b111101, 0b11111);
    EXPECT_TRUE((x ^ y) == expected);

    x ^= y;
    EXPECT_TRUE(x == expected);
}

TEST(BitwiseXor, BitwiseXorTest2) {
    u_very_long x(0xa8a7, 0xce5a7e822eaf6dde);
    u_very_long y(0xfe5, 0x38603c90273e4cf4);

    u_very_long expected(0xa742, 0xf63a42120991212a);
    EXPECT_TRUE((x ^ y) == expected);

    x ^= y;
    EXPECT_TRUE(x == expected);
}