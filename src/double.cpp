#include "u_very_long.hpp"

double u_very_long::to_double() const {
    double a = 0;
    a += hi;
    a = a * (double)(UINT64_MAX)+a;
    a += lo;
    return a;
}

u_very_long::operator double() const {
    return to_double();
}