#include "../baldosasDelPiso.h"
#include "gtest/gtest.h"

TEST(BaldosasDelPisoTest, MyNDivisiblesPorB) {
    // setup
    int M = 8;
    int N = 6;
    int B = 2;
    //exercise
    int cantBaldosas = baldosasDelPiso(M,N,B);
    bool result = (cantBaldosas == 12);
    // check
    EXPECT_TRUE(result);
}

TEST(BaldosasDelPisoTest, MDivisiblePorB) {
    // setup
    int M = 8;
    int N = 5;
    int B = 4;
    //exercise
    int cantBaldosas = baldosasDelPiso(M,N,B);
    bool result = (cantBaldosas == 4);
    // check
    EXPECT_TRUE(result);
}

TEST(BaldosasDelPisoTest, NDivisiblePorB) {
    // setup
    int M = 2;
    int N = 9;
    int B = 3;
    //exercise
    int cantBaldosas = baldosasDelPiso(M,N,B);
    bool result = (cantBaldosas == 6);
    // check
    EXPECT_FALSE(result);
}

TEST(BaldosasDelPisoTest, NingunoDivisiblePorB) {
    // setup
    int M = 4;
    int N = 5;
    int B = 7;
    //exercise
    int cantBaldosas = baldosasDelPiso(M,N,B);
    bool result = (cantBaldosas == 1);
    // check
    EXPECT_TRUE(result);
}