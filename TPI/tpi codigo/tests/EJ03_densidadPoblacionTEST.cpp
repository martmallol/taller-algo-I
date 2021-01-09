#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(densidadPoblacionTEST, toroideDiagonal){
    vector<bool> a = { true, true, true, true };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 1.0, 0.01);
}

////
TEST(densidadPoblacionTEST, sinVivas){
    vector<bool> a = { false, false, false, false };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 0.0, 0.01);
}

TEST(densidadPoblacionTEST, toroideEquis){
    toroide t = {
            {true, false, false},
            {false, true, false},
            {false, false, true},
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    EXPECT_NEAR(densidadPoblacion(t), 0.33, 0.01);
}



