#ifndef BEZIERMETHODHEADERDEF
#define BEZIERMETHODHEADERDEF

#include <iostream>
#include "GramSchmidt.h"



class BezierMethod
{
private:


    double m_step;
    double m_BoundaryOne;
    double m_BoundaryTwo;
    double* results;
    double* TValues_zero;
    double* TValues_one;
    double* TValues_two;
    double* CollocationPoints;


public:
    BezierMethod(double Boundary_one = 0, double Boundary_two = 0);
    ~BezierMethod();
    double SecondDerivative(double t);
    double FirstDerivative(double t);
    double m_Function(double t);
    double RightHandSide(double t);
    double* Evaluate(double t);
    void  getPoints();
    double BinomialCoefficient(int n, int i);
    void Solve();
    void MakeMatrices();  
    void Print();  
};


#endif