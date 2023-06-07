#include "gtest/gtest.h"
#include "u_very_long.hpp"

TEST(EqualToTest, EqualToTest1) {
    u_very_long x(0, 0);
    ASSERT_TRUE(x == x);
}

TEST(EqualToTest, EqualToTest2) {
    u_very_long x(0, 0);
    u_very_long y(0, 1);
    ASSERT_FALSE(y == x);
}

TEST(EqualToTest, EqualToTest3) {
    u_very_long x(0, 0);
    u_very_long y(1, 0);
    ASSERT_FALSE(y == x);
}

TEST(EqualToTest, EqualToTest4) {
    u_very_long x(123, 42);
    u_very_long y(123, 42);

    ASSERT_TRUE(x == y);
}

TEST(NotEqualToTest, NotEqualToTest1) {
    u_very_long x(0, 0);
    ASSERT_FALSE(x != x);
}

TEST(NotEqualToTest, NotEqualToTest2) {
    u_very_long x(0, 0);
    u_very_long y(0, 1);
    ASSERT_TRUE(y != x);
}

TEST(NotEqualToTest, NotEqualToTest3) {
    u_very_long x(0, 0);
    u_very_long y(1, 0);
    ASSERT_TRUE(y != x);
}

TEST(NotEqualToTest, NotEqualToTest4) {
    u_very_long x(123, 42);
    u_very_long y(123, 42);

    ASSERT_FALSE(x != y);
}

TEST(LessThanTest, LessThanTest1) {
    u_very_long a(0, 0), b(0, 0);
    ASSERT_FALSE(a < b);
    ASSERT_FALSE(b < a);
}

TEST(LessThanTest, LessThanTest2) {
    u_very_long a(0, 1), b(0, 0);
    ASSERT_FALSE(a < b);
    ASSERT_TRUE(b < a);
}

TEST(LessThanTest, LessThanTest3) {
    u_very_long a(1, 0), b(0, 0);
    ASSERT_FALSE(a < b);
    ASSERT_TRUE(b < a);
}

TEST(LessThanTest, LessThanTest4) {
    u_very_long a(1, 1), b(1, 0);
    ASSERT_FALSE(a < b);
    ASSERT_TRUE(b < a);
}

TEST(LessThanTest, LessThanTest5) {
    u_very_long a(2, 2), b(2, 1);
    ASSERT_FALSE(a < b);
    ASSERT_TRUE(b < a);
}

TEST(LessThanTest, LessThanTest6) {
    u_very_long a(2, 2), b(3, 2);
    ASSERT_TRUE(a < b);
    ASSERT_FALSE(b < a);
}

TEST(GreaterThanTest, GreaterThanTest1) {
    u_very_long a(0, 0), b(0, 0);
    ASSERT_FALSE(a > b);
    ASSERT_FALSE(b > a);    
}

TEST(GreaterThanTest, GreaterThanTest2) {
    u_very_long a(0, 1), b(0 ,0);    
    ASSERT_TRUE(a > b);    
    ASSERT_FALSE(b > a);    
}

TEST(GreaterThanTest, GreaterThanTest3) {
   u_very_long a(1 ,0), b(0 ,0);    
   ASSERT_TRUE(a > b);    
   ASSERT_FALSE(b > a);    
}

TEST(GreaterThanTest, GreaterThanTest4) {    
   u_very_long a(1 ,1), b(1 ,0);    
   ASSERT_TRUE(a > b);    
   ASSERT_FALSE(b > a);    
}

TEST(GreaterThanTest, GreaterThanTest5) {    
   u_very_long a(2 ,2), b(2 ,1);    
   ASSERT_TRUE(a > b);    
   ASSERT_FALSE(b > a);    
}

TEST(GreaterThanTest, GreaterThanTest6) {    
   u_very_long a(2 ,2), b(3 ,2);    
   ASSERT_FALSE(a > b);    
   ASSERT_TRUE(b > a);    
}

TEST(LessThanEQLTTest, LessThanEqualToTest1) {    
   u_very_long a(0 ,0), b(0 ,0);    
   ASSERT_TRUE(a <= b);    
   ASSERT_TRUE(b <= a);    
}

TEST(LessThanEQLTTest , LessThanEqualToTest2) {    
   u_very_long a(0 ,1), b(0 ,0);    
   ASSERT_FALSE(a <= b);    
   ASSERT_TRUE(b <= a);    
}

TEST(LessThanEQLTTest , LessThanEqualToTest3) {    
   u_very_long a(1 ,0), b(0 ,0);    
   ASSERT_FALSE(a <= b);    
   ASSERT_TRUE(b <= a);    
}

TEST(LessThanEQLTTest , LessThanEqualToTest4) {    
   u_very_long a(1 ,1), b(1 ,0);    
   ASSERT_FALSE(a <= b);    
   ASSERT_TRUE(b <= a);    
}

TEST(LessThanEQLTTest , LessThanEqualToTest5) {    
   u_very_long a(2 ,2), b(2 ,1);    
   ASSERT_FALSE(a <= b);    
   ASSERT_TRUE(b <= a);    
}

TEST(LessThanEQLTTest , LessThanEqualToTest6) {    
   u_very_long a(2 ,2), b(3 ,2);    
   ASSERT_TRUE(a <= b);    
   ASSERT_FALSE(b <= a);    
}

TEST(GreaterThanEQLTTest , GreaterThanEqualToTest1) {    
   u_very_long a(0 ,0), b(0 ,0);    
   ASSERT_TRUE(a >= b);    
   ASSERT_TRUE(b >= a);    
}

TEST(GreaterThanEQLTTest , GreaterThanEqualToTest2) {    
   u_very_long a(0 ,1), b(0 ,0);    
   ASSERT_TRUE(a >= b);    
   ASSERT_FALSE(b >= a);    
}

TEST(GreaterThanEQLTTest , GreaterThanEqualToTest3) {    
   u_very_long a(1 ,0), b(0 ,0);    
   ASSERT_TRUE(a >= b);    
   ASSERT_FALSE(b >= a);    
}

TEST(GreaterThanEQLTTest , GreaterThanEqualToTest4) {    
   u_very_long a(1 ,1), b(1 ,0);    
   ASSERT_TRUE(a >= b);    
   ASSERT_FALSE(b >= a);    
}

TEST(GreaterThanEQLTTest , GreaterThanEqualToTest5) {   
    u_very_long a(2, 2), b(2, 1);
    ASSERT_TRUE(a >= b);
    ASSERT_FALSE(b >= a);
}

TEST(GreaterThankEQLTTest, GreaterThanEqualToTest6) {
    u_very_long a(2, 2), b(3, 2);
    ASSERT_FALSE(a >= b);
    ASSERT_TRUE(b >= a);
}
