#include <iostream>
#include "LinearInterpolation.h"

using namespace std;

int main()
{
    Interpolation *l = new LinearInterpolation({0, 75, 150, 200, 250, 300}, {20, 75, 100, 105, 75, 0});


    cout << l->getFunction(0.1) << endl;

    return 0;
}
