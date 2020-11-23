#include "BezierMethod.h"
#include <cmath>

int main(int argc, char const *argv[])
{
    double e = exp(1);
    BezierMethod B(1,e);
    B.Print();
    return 0;
}
