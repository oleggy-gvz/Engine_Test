#include <iostream>
#include <memory>
#include "../EngineTest/Interpolation/Interpolation.h"
#include "../EngineTest/Interpolation/LinearInterpolation.h"
#include "../EngineTest/Interpolation/CubicSplineInterpolation.h"

using namespace std;

int main()
{
    //shared_ptr<Interpolation> i(new LinearInterpolation({0, 75, 150, 200, 250, 300}, {20, 75, 100, 105, 75, 0}));
    //shared_ptr<Interpolation> i (new LinearInterpolation{{0, 20}, {75, 75}, {150, 100}, {200, 105}, {250, 75}, {300, 0}}); // OR
    shared_ptr<Interpolation> ci(new CubicSplineInterpolation{{-1, 0.756802495},
                                                              {-0.5, -0.909297427},
                                                              {0, 0},
                                                              {0.5, 0.909297427},
                                                              {1, -0.756802495}});

    double x;
    x = -0.99;
    cout << "x = " << x << ", f(x) = " << ci->getFunction(x) << endl;
    x = -0.49;
    cout << "x = " << x << ", f(x) = " << ci->getFunction(x) << endl;
    x = 0.4;
    cout << "x = " << x << ", f(x) = " << ci->getFunction(x) << endl;
    x = 0.99;
    cout << "x = " << x << ", f(x) = " << ci->getFunction(x) << endl;

    system("pause");
    return 0;
}
