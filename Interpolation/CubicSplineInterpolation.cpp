#include "CubicSplineInterpolation.h"

CubicSplineInterpolation::CubicSplineInterpolation(std::initializer_list<double> x, std::initializer_list<double> y)
{
    setPoints(x, y);
}

CubicSplineInterpolation::CubicSplineInterpolation(initializer_list<pair<double, double>> p)
{
    setPoints(p);
}

void CubicSplineInterpolation::calculateRatios()
{
    if (points.size() > 1)
    {
        // clean old ratios
        a.clear(); // clean a[i]
        b.clear(); // clean b[i]
        c.clear(); // clean b[i]
        d.clear(); // clean b[i]
        segments.clear(); // clean segments[i]

        auto it_p1 = points.begin();
        auto it_p2 = it_p1;
        ++it_p2;
        double a_cur, b_cur, c_cur, d_cur;
        for (unsigned int i = 0; it_p2 != points.end(); ++it_p1, ++it_p2, i++)
        {
            a_cur = (it_p2->second - it_p1->second) / (it_p2->first - it_p1->first);
            b_cur = it_p1->second - a_cur * it_p1->first;

            a.push_back(a_cur); // a[i]
            b.push_back(b_cur); // b[i]
            c.push_back(c_cur); // c[i]
            d.push_back(d_cur); // d[i]
            segments[it_p2->first] = i; // segment[i]
        }
    }
}

double CubicSplineInterpolation::getFunction(double x)
{
    if (points.size() < 2)
    {
        throw Exception(Exception::NO_POINTS);
    }
    else
    {
        if (x < points.begin()->first)
        {
            throw Exception(Exception::LESS_LOWER_BOUND);
        }
        if (x > points.rbegin()->first)
        {
            throw Exception(Exception::MORE_UPPER_BOUND);
        }
        auto it = points.find(x);
        if (it != points.end()) // if the point is in table
        {
            return it->second;
        }
        else // else, calculate independently
        {
            auto it_n = segments.upper_bound(x);
            double x_xi = (x - it_n->first); // x - x[i]
            return a[it_n->second] + b[it_n->second] * x_xi + c[it_n->second] * x_xi * x_xi + d[it_n->second] * x_xi * x_xi * x_xi;
        }
    }
}

// РАЗОБРАТЬ !!!!!!!!!!

/*
class knot{
public:
    double x,f;

    void Add(double arg,double func)
    {
        x=arg;
        f=func;
    }

    knot(){}
};

class vector{
public:
    double* x;

    void Add(int m)
    {
        x = new double[m];
    }
    vector()
    {
    }
};

knot* KnotArray;
int n;
double** Coef;
double* b;

//Решение системы уравнений с трехдиагональной матрицей
void SolveTriDiag(double** TDM, double* F)
{
    double* alph = new double[n-1];
    double* beta = new double[n-1];

    int i;

    alph[0] = - TDM[2][0]/TDM[1][0];
    beta[0] = F[0]/TDM[1][0];

    for (i=1; i<n-1; i++)
    {
        alph[i] = -TDM[2][i]/(TDM[1][i] + TDM[0][i]*alph[i-1]);
        beta[i] = (F[i]-TDM[0][i]*beta[i-1])/(TDM[1][i] + TDM[0][i]*alph[i-1]);
    }
    b[n-1] = (F[n-1]-TDM[0][n-1]*beta[n-2])/(TDM[1][n-1] + TDM[0][n-1]*alph[n-2]);

    for (i=n-2; i>-1; i--)
    {
        b[i] = b[i+1] * alph[i] + beta[i];
    }
}

//Построение таблицы коэффициентов кубического сплайна
int BuildSpline()
{
    double* a = new double[n-1];
    double* c = new double[n-1];
    double* d = new double[n-1];
    double* delta = new double[n-1];
    double* h = new double[n-1];
    double** TriDiagMatrix = new double*[3];

    b = new double[n];

    TriDiagMatrix[0] = new double[n];
    TriDiagMatrix[1] = new double[n];
    TriDiagMatrix[2] = new double[n];

    double* f = new double[n];
    double x3,xn;
    int i;

    if (n<3)
        return -1;

    x3 = KnotArray[2].x - KnotArray[0].x;
    xn = KnotArray[n-1].x - KnotArray[n-3].x;

    for (i=0; i<n-1; i++)
    {
        a[i] = KnotArray[i].f;
        h[i] = KnotArray[i+1].x - KnotArray[i].x;
        delta[i] = (KnotArray[i+1].f - KnotArray[i].f)/h[i];
        TriDiagMatrix[0][i] = i>0?h[i]:x3;
        f[i] = i>0?3*(h[i]*delta[i-1] + h[i-1]*delta[i]):0;
    }
    TriDiagMatrix[1][0] = h[0];
    TriDiagMatrix[2][0] = h[0];
    for (int i=1; i<n-1;i++)
    {
        TriDiagMatrix[1][i] = 2*(h[i] + h[i-1]);
        TriDiagMatrix[2][i] = h[i];
    }
    TriDiagMatrix[1][n-1] = h[n-2];
    TriDiagMatrix[2][n-1] = xn;
    TriDiagMatrix[0][n-1] = h[n-2];


    i = n-1;
    f[0] = ((h[0]+2*x3)*h[1]*delta[0] + powf(h[0],2)*delta[1])/x3;
    f[n-1]=(powf(h[i-1],2)*delta[i-2]+(2*xn+h[i-1])*h[i-2]*delta[i-1])/xn;

    SolveTriDiag(TriDiagMatrix,f);

    Coef = new double*[4];
    Coef[0] = new double[n-1];
    Coef[1] = new double[n-1];
    Coef[2] = new double[n-1];
    Coef[3] = new double[n-1];
    int j;
    for (j=0; j<n-1; j++)
    {
        d[j] = (b[j+1]+b[j]-2*delta[j])/(h[j]*h[j]);
        c[j] = 2*(delta[j]-b[j])/h[j]-(b[j+1]-delta[j])/h[j];

        Coef[j][0] = a[j];
        Coef[j][1] = b[j];
        Coef[j][2] = c[j];
        Coef[j][3] = d[j];
    }
}
*/
