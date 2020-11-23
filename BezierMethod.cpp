#include "BezierMethod.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>


BezierMethod::BezierMethod(double Boundary_one, double Boundary_two)
{

    m_step = 0.1;
    CollocationPoints = new double[3];
    results = new double[3];
    TValues_one = new double[3];
    TValues_two = new double[3];
    TValues_zero = new double[3];
    m_BoundaryOne = Boundary_one;
    m_BoundaryTwo = Boundary_two;
}
BezierMethod::~BezierMethod()
{
    delete[] CollocationPoints;
    delete[] TValues_one;
    delete[] TValues_two;
    delete[] TValues_zero;
    delete[] results;

}
double BezierMethod::SecondDerivative(double t)
{
    return 1;
}
double BezierMethod::FirstDerivative(double t)
{
    return 0;
}
double BezierMethod::m_Function(double t)
{
    return -1;
}
double BezierMethod::RightHandSide(double t)
{
    return 0;
}

void BezierMethod::getPoints()
{
    double* results;
    results = Evaluate(0.5);

    
    CollocationPoints[0] = m_BoundaryOne;
    CollocationPoints[1] = ((results[0]*m_BoundaryOne) + (results[2]*m_BoundaryTwo)-RightHandSide(0))/-results[1];
    CollocationPoints[2] = m_BoundaryTwo;
    
}


double BezierMethod::BinomialCoefficient(int n, int i)
{
    if(n == i or i == 0)
    {
        return 1;
    }
    return BinomialCoefficient(n-1,i-1) + BinomialCoefficient(n-1,i);
    
}
double* BezierMethod::Evaluate(double t)
{
    double* myValues = new double[3];

    
    TValues_two[0] = SecondDerivative(t)*2;
    TValues_two[1] = SecondDerivative(t)*-4;
    TValues_two[2] = SecondDerivative(t)*2;

    TValues_one[0] = FirstDerivative(t)*(-2+(2*t));
    TValues_one[1] = FirstDerivative(t)*(2-(4*t));
    TValues_one[2] = FirstDerivative(t)*(2*t);


    TValues_zero[0] = m_Function(t)*BinomialCoefficient(2,0)*pow(1-t,2);
    TValues_zero[1] = m_Function(t)*BinomialCoefficient(2,1)*(1-t)*t;
    TValues_zero[2] = m_Function(t)*BinomialCoefficient(2,2)*pow(t,2);

    
    for (int i = 0; i < 3; i ++)
    {
        myValues[i] = TValues_two[i] + TValues_one[i] + TValues_zero[i];

    }

    
    return myValues;

}
void BezierMethod::Solve()
{

    getPoints();
}
void BezierMethod::Print()
{
    Solve();
    double step = 0;
    std::ofstream myFile;
    myFile.open("data.dat");


    while (step < 1)
    {
        
        myFile << step << "\t" << CollocationPoints[0]*BinomialCoefficient(2,0)*pow(1-step,2) +
        CollocationPoints[1]*BinomialCoefficient(2,1)*(1-step)*(step) +
        CollocationPoints[2]*BinomialCoefficient(2,2)*pow(step,2)<< "\t" << exp(step) << "\n";
        step += m_step;
    }
}

