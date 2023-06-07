#include "gtest/gtest.h"
#include "u_very_long.hpp"

TEST(AddTest, AddLo1) {
    u_very_long x(0, 0);
    u_very_long y(0, 1);

    ASSERT_TRUE(x + y == y);
    x += y;
    ASSERT_TRUE(x == y);
}

TEST(AddTest, AddLo2) {
    u_very_long x(0, 14);
    u_very_long y(0, 12936);

    u_very_long expected_res(0, 12950);
    ASSERT_TRUE(x + y == expected_res);
    x += y;
    ASSERT_TRUE(x == expected_res);
}

TEST(AddTest, AddHi1) {
    u_very_long x(1, 0);
    u_very_long y(2, 0);

    u_very_long expected_res(3, 0);
    ASSERT_TRUE(x + y == expected_res);
    x += y;
    ASSERT_TRUE(x == expected_res);
}

TEST(AddTest, AddHi2) {
    u_very_long x(14, 0);
    u_very_long y(256, 0);

    u_very_long expected_res(270, 0);
    ASSERT_TRUE(x + y == expected_res);
    x += y;
    ASSERT_TRUE(x == expected_res);
}

TEST(AddTest, AddMix1) {
    u_very_long x(0, -1);
    u_very_long y(0, 1);

    u_very_long expected_res(1, 0);
    ASSERT_TRUE(x + y == expected_res);
    x += y;
    ASSERT_TRUE(x == expected_res);
}

TEST(AddTest, AddMix2) {
    u_very_long x(500, (-2));
    u_very_long y(0, 3);

    u_very_long expected_res(501, 1);
    ASSERT_TRUE(x + y == expected_res);
    x += y;
    ASSERT_TRUE(x == expected_res);
}

TEST(AddTest, DefinedOverflowBehaviour1) {
    u_very_long x(-1, -1);
    u_very_long y(0, 1);

    u_very_long expected_res(0, 0);
    ASSERT_TRUE(x + y == expected_res);
    x += y;
    ASSERT_TRUE(x == expected_res);    
}

TEST(AddTest, DefinedOverflowBehaviour2) {
   u_very_long x(-1, -2);    
   u_very_long y (0 ,2);    
   
   u_very_long expected_res(0 ,0);    
   ASSERT_TRUE(x + y == expected_res);    
   x += y;    
   ASSERT_TRUE(x == expected_res);    
}


TEST(SubTest, SubLo1) {
    u_very_long x(0, 1);
    u_very_long y(0, 1);

    u_very_long expected_res(0, 0);
    ASSERT_TRUE(x - y == expected_res);
    x -= y;
    ASSERT_TRUE(x == expected_res);
}

TEST(SubTest, SubLo2) {
    u_very_long x(0, 321);
    u_very_long y(0, 21);
    
    u_very_long expected_res(0, 300);
    ASSERT_TRUE(x - y == expected_res);
    x -= y;
    ASSERT_TRUE(x == expected_res);
}

TEST(SubTest, SubLo3) {
    u_very_long x(0, 1);
    u_very_long y(0, 0);

    u_very_long expected_res(0, 1);
    ASSERT_TRUE(x - y == expected_res);
    x -= y;
    ASSERT_TRUE(x == expected_res);
}

TEST(SubTest, SubHi1) {
    u_very_long x(1, 0);
    u_very_long y(1, 0);

    u_very_long expected_res(0, 0);
    ASSERT_TRUE(x - y == expected_res);
    x -= y;
    ASSERT_TRUE(x == expected_res);
}

TEST(SubTest, SubHi2) {
   u_very_long x(432 ,0);    
   u_very_long y(32 ,0);    
   
   u_very_long expected_res(400 ,0);    
   ASSERT_TRUE(x - y == expected_res);    
   x -= y;    
   ASSERT_TRUE(x == expected_res);    
}

TEST(SubTest , SubHi3 ) {    
   u_very_long x(1 ,0);    
   u_very_long y(0 ,0);    
   
   u_very_long expected_res(1 ,0);    
   ASSERT_TRUE(x - y == expected_res);    
   x -= y;    
   ASSERT_TRUE(x == expected_res);    
}

TEST(SubTest , SubMix1 ) {    
   u_very_long x(-1 ,-1);    
   u_very_long y(0 ,2);    
   
   u_very_long expected_res(-1 ,-3);    
   ASSERT_TRUE(x - y == expected_res);    
   x -= y;    
   ASSERT_TRUE(x == expected_res);    
}

TEST(SubTest , SubMix2 ) {    
   u_very_long x(1 ,0);    
   u_very_long y(0 ,1);    
   
   u_very_long expected_res(0 ,-1);    
   ASSERT_TRUE(x - y == expected_res);    
   x -= y;    
   ASSERT_TRUE(x == expected_res);    
}

TEST(SubTest , DefinedOverflowBehaviour ) {    
   u_very_long x(0 ,0);    
   u_very_long y(0 ,1);    
   
   u_very_long expected_res(-1 ,-1);    
   ASSERT_TRUE(x - y == expected_res);    
   x -= y;    
   ASSERT_TRUE(x == expected_res);    
}

TEST(UnaryTest , UnaryTest1 ) {   
    u_very_long x(0, 1);
    u_very_long expected(-1, -1);

    ASSERT_TRUE(-x == expected);
}

TEST(UnaryTest , UnaryTest2 ) {   
    u_very_long x(0, 42);
    u_very_long expected(-1, -42);

    ASSERT_TRUE(-x == expected);
}

TEST(UnaryTest , UnaryTest3 ) {   
    u_very_long x(0, 0);
    u_very_long expected(0, 0);

    ASSERT_TRUE(-x == expected);
}

TEST(UnaryTest , UnaryTest4 ) {   
    u_very_long x(-1, -1);
    u_very_long expected(0, 1);

    ASSERT_TRUE(-x == expected);
}

TEST(AddSubTest, AddSubMixedTest1) {
    u_very_long x(0, 42);
    u_very_long y(0, 958);
    u_very_long expected(0, 1000);

    ASSERT_TRUE(x + y == expected);
}

TEST(AddSubTest, AddSubMixedTest2) {
    u_very_long x(0, 42);
    u_very_long y(0, 958);

    x += y;
    y = u_very_long(0, 500);
    ASSERT_TRUE(x - y == u_very_long(0, 500));
}

TEST(AddSubTest, AddSubMixedTest3) {
    u_very_long x(0, 42);
    u_very_long y(0, 958);

    x += y;  
    y = u_very_long(1, 0);
    y -= x;
    u_very_long expected(0, -1000);
    ASSERT_TRUE(y == expected);
}
