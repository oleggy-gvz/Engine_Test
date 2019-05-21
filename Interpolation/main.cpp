#include <iostream>
#include <memory>
#include "../EngineTest/Interpolation/Interpolation.h"
#include "../EngineTest/Interpolation/LinearInterpolation.h"
//#include "../EngineTest/Interpolation/CubicSplineInterpolation.h"

using namespace std;

int main()
{
    shared_ptr<Interpolation> l (new LinearInterpolation({0, 75, 150, 200, 250, 300}, {20, 75, 100, 105, 75, 0}));
    //shared_ptr<Interpolation> l (new LinearInterpolation{{0, 20}, {75, 75}, {150, 100}, {200, 105}, {250, 75}, {300, 0}}); // OR

    cout << "f(x) = " << l->getFunction(0) << endl;
    return 0;
}
