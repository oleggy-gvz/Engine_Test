#include <iostream>
#include "LinearInterpolation.h"

using namespace std;

int main()
{
    Interpolation *l = new LinearInterpolation(new vector<double>{0, 75, 150, 200, 250, 300}, new vector<double>{20, 75, 100, 105, 75, 0});
    cout << l->getFunction(0) << endl;

    delete l;

    return 0;
}
