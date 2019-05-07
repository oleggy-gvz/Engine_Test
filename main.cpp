#include <iostream>
#include "LinearInterpolation.h"

using namespace std;

int main()
{
    Interpolation *l = new LinearInterpolation;

    l->addPoint(0, 1);
    l->addPoint(3, 2);
    cout << l->getY(3) << endl;

    return 0;
}
