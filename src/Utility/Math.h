#pragma once

#include <cmath>

class Math
{
   public:
    static double RadToDeg() { return 180 / M_PI; };
    static double RadToDeg(double angle) { return angle * RadToDeg(); };
    static double DegToRad() { return M_PI / 180; };
    static double DegToRad(double angle) { return angle * DegToRad(); };

    static double IsEqual(double a, double b, double precision = 1E-7)
    {
        return fabs(a - b) < precision;
    }

   private:
    Math() = delete;
};
