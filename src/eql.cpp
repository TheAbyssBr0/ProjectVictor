#include "u_very_long.hpp"

bool u_very_long::operator==(const u_very_long& a) const {
    return (hi == a.hi && lo == a.lo);
}

bool u_very_long::operator!=(const u_very_long& a) const {
    return hi != a.hi || lo != a.lo;
}

bool u_very_long::operator<(const u_very_long& a) const {
    return (hi <= a.hi) && ((hi < a.hi) || (lo < a.lo));
}

bool u_very_long::operator>(const u_very_long& a) const {
    /* Same as < but opposite and used distributive law */
    return (hi > a.hi) || ((lo > a.lo) && (hi >= a.hi));
}

bool u_very_long::operator<=(const u_very_long& a) const {
    return (hi < a.hi) || ((lo <= a.lo) && (hi <= a.hi));
}

bool u_very_long::operator>=(const u_very_long& a) const {
    return (hi > a.hi) || ((lo >= a.lo) && (hi >= a.hi));
}