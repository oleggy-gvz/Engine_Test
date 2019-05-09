#include <iostream>
#include "Interpolation\LinearInterpolation.h"

using namespace std;

int main()
{
    Interpolation *V_M = new LinearInterpolation({0, 75, 150, 200, 250, 300}, {20, 75, 100, 105, 75, 0});
    //Interpolation *V_M = new LinearInterpolation{{0, 20}, {75, 75}, {150, 100}, {200, 105}, {250, 75}, {300, 0}};


    cout << V_M->getFunction(75) << endl;

    return 0;
}
