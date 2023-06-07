#include "u_very_long.hpp"

u_very_long u_very_long::operator<<(const unsigned char& a) const {
    u_very_long answer;
    answer.lo = lo << a;
    answer.hi = (hi << a) | (lo >> (64 - a));
    return answer;
}

u_very_long u_very_long::operator>>(const unsigned char& a) const {
    u_very_long answer;
    answer.hi = hi >> a;
    answer.lo = (lo >> a) | (hi & ((uint64_t)1 << a) - 1) << (64 - a);
    return answer;
}

u_very_long u_very_long::operator&(const u_very_long& a) const {
    return u_very_long(hi & a.hi, lo & a.lo);
}

u_very_long u_very_long::operator|(const u_very_long& a) const {
    return u_very_long(hi | a.hi, lo | a.lo);
}

u_very_long u_very_long::operator~() const {
    return u_very_long(~hi, ~lo);
}

u_very_long u_very_long::operator^(const u_very_long& a) const {
    return u_very_long(hi ^ a.hi, lo ^ a.lo);
}

void u_very_long::operator<<=(const unsigned char& a) {
    *this = *this << a;
}

void u_very_long::operator>>=(const unsigned char& a) {
    *this = *this >> a;
}

void u_very_long::operator&=(const u_very_long& a) {
    *this = *this & a;
}

void u_very_long::operator^=(const u_very_long& a) {
    *this = *this ^ a;
}

void u_very_long::operator|=(const u_very_long& a) {
    *this = *this | a;
}