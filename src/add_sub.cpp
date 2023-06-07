#include "u_very_long.hpp"

u_very_long u_very_long::operator+(const u_very_long& a) const {
    u_very_long answer;
    answer.lo = lo + a.lo;
    answer.hi = a.hi + hi + ((__UINT64_MAX__ - a.lo) < lo);
    return answer;
}

u_very_long u_very_long::operator-(const u_very_long& a) const {
    u_very_long answer;
    answer.lo = lo - a.lo;
    answer.hi = hi - a.hi - (a.lo > lo);
    return answer;
}

u_very_long u_very_long::operator-() const {
    u_very_long answer;
    answer.lo = ~(lo);
    answer.hi = ~(hi);
    u_very_long one(0, 1);

    answer = answer + one;
    return answer;
}

void u_very_long::operator+=(const u_very_long& a) {
    *this = *this + a;
}

void u_very_long::operator-=(const u_very_long& a) {
    *this = *this - a;
}