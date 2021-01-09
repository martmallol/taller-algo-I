#include "../llenarTaxis.h"
#include "gtest/gtest.h"

TEST(TaxiTest, TodasIguales) {
    // setup
    int g1 = 5;
    int g2 = 5;
    int g3 = 5;
    //exercise
    int result1 = llenarTaxis1(g1,g2,g3);
    int result2 = llenarTaxis2(g1,g2,g3);
    int result3 = llenarTaxis3(g1,g2,g3);
    bool response = (result1 == result2 == result3);
    // check
    EXPECT_TRUE(response);
}

TEST(TaxiTest, G2ParTest) {
    // setup
    int g1 = 3;
    int g2 = 4;
    int g3 = 0;
    //exercise
    int result1 = llenarTaxis1(g1,g2,g3);
    int result2 = llenarTaxis2(g1,g2,g3);
    int result3 = llenarTaxis3(g1,g2,g3);
    bool response = (result1 == result2 == result3);
    // check
    EXPECT_TRUE(response);
}

TEST(TaxiTest, G2ImparI) {
    // setup
    int g1 = 3;
    int g2 = 1;
    int g3 = 2;
    //exercise
    int result1 = llenarTaxis1(g1,g2,g3);
    int result2 = llenarTaxis2(g1,g2,g3);
    int result3 = llenarTaxis3(g1,g2,g3);
    bool response = (result1 == result2 == result3);
    // check
    EXPECT_TRUE(response);
}

TEST(TaxiTest, G2ImparII) {
    // setup
    int g1 = 0;
    int g2 = 1;
    int g3 = 2;
    //exercise
    int result1 = llenarTaxis1(g1,g2,g3);
    int result2 = llenarTaxis2(g1,g2,g3);
    int result3 = llenarTaxis3(g1,g2,g3);
    bool response = (result1 == result2 == result3);
    // check
    EXPECT_TRUE(response);
}

TEST(TaxiTest, TodoCero) {
    // setup
    int g1 = 0;
    int g2 = 0;
    int g3 = 0;
    //exercise
    int result1 = llenarTaxis1(g1,g2,g3);
    int result2 = llenarTaxis2(g1,g2,g3);
    int result3 = llenarTaxis3(g1,g2,g3);
    bool response = (result1 == result2 == result3);
    // check
    EXPECT_TRUE(response);
}

TEST(TaxiTest, AlgunoNegativo) {
    // setup
    int g1 = -2;
    int g2 = 1;
    int g3 = 3;
    //exercise
    int result1 = llenarTaxis1(g1,g2,g3);
    int result2 = llenarTaxis2(g1,g2,g3);
    int result3 = llenarTaxis3(g1,g2,g3);
    bool response = (result1 == result2 == result3);
    // check
    EXPECT_TRUE(response);
}