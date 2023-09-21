#pragma once

#include <cmath>
#include <exception>

namespace Math
{
    static double RadToDeg() { return 180 / M_PI; };
    static double RadToDeg(double angle) { return angle * RadToDeg(); };
    static double DegToRad() { return M_PI / 180; };
    static double DegToRad(double angle) { return angle * DegToRad(); };

    static double IsEqual(double a, double b, double precision = 1E-7)
    {
        return fabs(a - b) < precision;
    }

    static double SetPrecision(double value, int decimals = 1)
    {
        if (decimals >= 0)
        {
            int factor = std::pow(10, decimals);
            return std::round(value * factor) / factor;
        }
        throw std::invalid_argument("Can't have negative decimals");
    }

    static double ClampAngleToUnitCircle(double angle)
    {
        if (abs(angle) >= 2 * M_PI)
        {
            angle = fmod(angle, 2 * M_PI);
        }
        if (angle < 0)
        {
            angle = 2 * M_PI + angle;
        }
        return angle;
    }
};
