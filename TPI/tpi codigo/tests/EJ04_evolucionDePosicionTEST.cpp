#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(evolucionDePosicionTEST, toroideDiagonalTresPorTres){
    toroide t = { {true, false, false}, {false, true, false}, {false, false, true} };
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, NoRevivePorCincoVecinosVivos){
    toroide t = { {false, true, true}, {false, true, false}, {false, true, true}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,0)));
}

///////
TEST(evolucionDePosicionTEST, esquinaSuperiorComoEnTPE){
    toroide t = { {true, false, false, true},
                  {false, false, true, true},
                  {false, false, false, false},
                  {true, false, true, true}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(0,3)));
}

TEST(evolucionDePosicionTEST, esquinaSuperiorPeroVive){
    toroide t = { {true, false, false, true},
                  {false, false, false, true},
                  {false, false, false, false},
                  {false, false, false, true}};
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(0,3)));
}

TEST(evolucionDePosicionTEST, deMuertaAViva){
    toroide t = { {true, false, false, true},
                  {true, false, true, true},
                  {false, false, false, false},
                  {false, false, false, true}};
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(1,1)));
}