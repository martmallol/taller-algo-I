#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(evolucionToroideTEST, toroideDiagonalTresPorTresUnPaso){
    toroide t = { {true, false, false}, {false, true, false}, {false, false, true} };
    //1*0 0 1*0
    //0 1 0 0 1
    //0 0 1 0 0
    //1 0 0 1 0
    //0*1 0 0*1
    toroide evo_t = { {true, true, true}, {true, true, true}, {true, true, true} };
    //  1 1 1
    //  1 1 1
    //  1 1 1
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, esteLaPalma){
    toroide t = { {true, true, false}, {false, false, false}, {false, false, false} };
    //  1 1 0
    //  0 0 0
    //  0 0 0
    toroide evo_t = { {false, false, false}, {false, false, false}, {false, false, false} };
    //  0 0 0
    //  0 0 0
    //  0 0 0
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, evoMorales){
    toroide t = { {true, true, false}, {false, true, true}, {false, false, false} };
    //  0 0 0 0 0
    //  0 1 1 0 1
    //  1 0 1 1 0
    //  0 0 0 0 0
    //  0 1 1 0 1
    toroide evo_t = { {true, true, false}, {false, true, true}, {false, false, false} };
    //  1 1 0
    //  0 1 1
    //  0 0 1
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, evoReturns){
    toroide t = { {true, false, false}, {false, false, true}, {true, false, false} };
    //  0 1 0 0 1
    //  0 1 0 0 1
    //  1 0 0 1 0
    //  0 1 0 0 1
    //  0 1 0 0 1
    toroide evo_t = { {true, true, true}, {true, true, true}, {true, true, true} };
    //  1 1 1
    //  1 1 1
    //  1 1 1
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}