#include "../puntaje.h"
#include "gtest/gtest.h"

TEST(PuntajeTest, MenorYMultiplo) {
    // setup
    int n = 9;
    //exercise
    int result = puntaje(n);
    bool response = (result == n*2+10);
    // check
    EXPECT_TRUE(response);
}

TEST(PuntajeTest, MenorYNoMultiplo) {
    // setup
    int n = 5;
    //exercise
    int result = puntaje(n);
    bool response = (result == n*2-10);
    // check
    EXPECT_TRUE(response);
}

TEST(PuntajeTest, MayorNoMultiplo) {
    // setup
    int n = 10;
    //exercise
    int result = puntaje(n);
    bool response = (result == n-10);
    // check
    EXPECT_TRUE(response);
}

TEST(PuntajeTest, MayorMultiplo) {
    // setup
    int n = 300;
    //exercise
    int result = puntaje(n);
    bool response = (result == n+10);
    // check
    EXPECT_TRUE(response);
}

TEST(PuntajeTest, CasoBorde) {
    // setup
    int n = 0;
    //exercise
    int result = puntaje(n);
    bool response = (result == n*2+10);
    // check
    EXPECT_TRUE(response);
}
