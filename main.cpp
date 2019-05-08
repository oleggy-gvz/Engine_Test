#include <iostream>
#include "LinearInterpolation.h"

using namespace std;

int main()
{
    Interpolation *l = new LinearInterpolation;

    l->addPoint(1, 1);
    l->addPoint(3, 2);
    cout << l->getF(4) << endl;

    return 0;
}
