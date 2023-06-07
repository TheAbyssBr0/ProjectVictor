#include "u_very_long.hpp"
#include <immintrin.h>
#include <iostream>

u_very_long u_very_long::mul_helper(uint64_t x, uint64_t y) const {
    u_very_long answer;
    answer.lo = (uint64_t) _mulx_u64(x, y, (long long unsigned int*)&answer.hi);
    return answer;
}

u_very_long u_very_long::operator*(const u_very_long& a) const {
    if ((a.lo == 0 && a.hi == 0) || (lo == 0 && hi == 0)) {
        return u_very_long(0, 0);
    }

    if (a.lo == 1 && a.hi == 0) {
        return *this;
    }

    if (lo == 1 && hi == 0) {
        return a;
    }

    /** a is power of 2*/
    if ((__builtin_popcountl(a.lo) == 1 && (a.hi == 0)) ||
        (__builtin_popcountl(a.hi) == 1 && (a.lo == 0))) {
        unsigned char shift = __builtin_ctzl(a.hi) | __builtin_ctzl(a.lo);
        return *this << shift;
    }

    /** this is power of 2*/
    if ((__builtin_popcountl(lo) == 1 && (hi == 0)) ||
        (__builtin_popcountl(hi) == 1 && (lo == 0))) {
        unsigned char shift = __builtin_ctzl(hi) | __builtin_ctzl(lo);
        return a << shift;
    }

    u_very_long x2y2 = mul_helper(a.lo, lo);
    uint64_t x1y2 = a.hi * lo;
    uint64_t x2y1 = a.lo * hi;
    x2y2.hi += (x1y2 + x2y1);

    return x2y2;
}

u_very_long u_very_long::operator/(const u_very_long& a) const {
    if (a > *this) {
        return u_very_long(0, 0);
    }

    if (hi == a.hi && lo == a.lo) {
        return u_very_long(0, 1);
    }

    /* Divide by power of 2 */
    if ((__builtin_popcountl(a.lo) == 1 && (a.hi == 0)) ||
        (__builtin_popcountl(a.hi) == 1 && (a.lo == 0))) {
        unsigned char shift = __builtin_ctzl(a.hi) | __builtin_ctzl(a.lo);
        return *this >> shift;
    }

    if (a.hi == 0) {
        if (a.lo == 0) {
            throw std::overflow_error("Divide by zero exception");
        }

        /* Divide by 1 handled by divide by power of 2 */
        u_very_long m_by_c(0, UINT64_MAX / a.lo);
        u_very_long answer(0, hi);
        answer = answer * m_by_c;
        u_very_long lo_by_a_lo(0, lo / a.lo);
        answer += lo_by_a_lo;

        u_very_long calc = answer * a;
        uint64_t offset = std::abs((int64_t)(*this - calc).lo) / a.lo;
        answer.lo += offset;

        return answer;
    }

    u_very_long answer(0, hi/a.hi);

    uint64_t offset = -1;
    u_very_long calc;
    while(offset != 0) {
        calc = answer * (a);
        u_very_long difference;

        if (calc > *this) {
            difference = calc - *this;
            offset = difference.hi / a.hi;
            answer.lo -= offset;
        } else {
            difference = *this - calc;
            offset = difference.hi / a.hi;
            answer.lo += offset;
        }

        if (offset == 0 && difference.lo > a.lo) {
            if (calc > *this) answer.lo -= 1;
            else answer.lo += 1;
        }
    }

    return answer;
}

u_very_long u_very_long::operator%(const u_very_long& a) const {
    if (a.hi == 0 && a.lo == 0) {
        throw std::overflow_error("Modulo by zero exception");
    }

    u_very_long offset = (*this / a) * a;
    return *this - offset;
}

void u_very_long::operator*=(const u_very_long& a) {
    *this = *this * a;
}

void u_very_long::operator/=(const u_very_long& a) {
    *this = *this / a;
}

void u_very_long::operator%=(const u_very_long& a) {
    *this = *this % a;
}