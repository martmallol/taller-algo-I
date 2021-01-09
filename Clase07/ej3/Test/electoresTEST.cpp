#include "../electores.h"
#include "gtest/gtest.h"

//Tests de datos invalidos...
TEST(ElectoresTest, MesInvalido) {
    // setup
    int a = 2000;
    int m = 13;
    int d = 2;
    //exercise
    int  votante = validarVotante(a,m,d);
    bool result = ( votante == ERROR);
    // check
    EXPECT_TRUE(result);
}

TEST(ElectoresTest, AñoInvalido) {
    // setup
    int a = 2030;
    int m = 5;
    int d = 16;
    //exercise
    int  votante = validarVotante(a,m,d);
    bool result = ( votante == ERROR);
    // check
    EXPECT_TRUE(result);
}

TEST(ElectoresTest, DiaInvalido) {
    // setup
    int a = 1995;
    int m = 8;
    int d = 32;
    //exercise
    int  votante = validarVotante(a,m,d);
    bool result = ( votante == ERROR);
    // check
    EXPECT_TRUE(result);
}

TEST(ElectoresTest, AñoNoBisiesto) {
    // setup
    int a = 1997;
    int m = 2;
    int d = 29;
    //exercise
    int  votante = validarVotante(a,m,d);
    bool result = ( votante == ERROR);
    // check
    EXPECT_TRUE(result);
}

//Tests de no votos...
TEST(ElectoresTest, NoVotaPorUnDia) {
    // setup
    int a = 2004;
    int m = 10;
    int d = 23;
    //exercise
    int  votante = validarVotante(a,m,d);
    bool result = ( votante == NO_VOTA);
    // check
    EXPECT_TRUE(result);
}

TEST(ElectoresTest, MuyJoven) {
    // setup
    int a = 2010;
    int m = 12;
    int d = 31;
    //exercise
    int  votante = validarVotante(a,m,d);
    bool result = ( votante == NO_VOTA);
    // check
    EXPECT_TRUE(result);
}

//Tests de votos opcionales...
TEST(ElectoresTest, PuedeVotarJusto) {
    // setup
    int a = 2004;
    int m = 10;
    int d = 22;
    //exercise
    int  votante = validarVotante(a,m,d);
    bool result = ( votante == OPCIONAL_MENOR);
    // check
    EXPECT_TRUE(result);
}

TEST(ElectoresTest, DePedoOpcional) {
    // setup
    int a = 2002;
    int m = 10;
    int d = 23;
    //exercise
    int  votante = validarVotante(a,m,d);
    bool result = ( votante == OPCIONAL_MENOR);
    // check
    EXPECT_TRUE(result);
}

TEST(ElectoresTest, JustoViejo) {
    // setup
    int a = 1950;
    int m = 10;
    int d = 22;
    //exercise
    int  votante = validarVotante(a,m,d);
    bool result = ( votante == OPCIONAL_MAYOR);
    // check
    EXPECT_TRUE(result);
}

TEST(ElectoresTest, ViejoCienAños) {
    // setup
    int a = 1920;
    int m = 6;
    int d = 30;
    //exercise
    int  votante = validarVotante(a,m,d);
    bool result = ( votante == OPCIONAL_MAYOR);
    // check
    EXPECT_TRUE(result);
}

//Tests de votos validos...
TEST(ElectoresTest, ViejoCienAños) {
    // setup
    int a = 1964;
    int m = 9;
    int d = 4;
    //exercise
    int  votante = validarVotante(a,m,d);
    bool result = ( votante == OBLIGATORIO);
    // check
    EXPECT_TRUE(result);
}