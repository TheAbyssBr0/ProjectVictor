#ifndef U_VERY_LONG_HPP
#define U_VERY_LONG_HPP

#include <cstdint>
#include <stdexcept>

struct u_very_long {
private:
    /// Multiplies two unsigned 64-bit ints and stores result
    /// in a u_very_long data type
    /// @params x one of the operands
    /// @params y the other operand
    /// @returns x * y as an unsigned very long value
    u_very_long mul_helper(uint64_t x, uint64_t y) const;

    /// 
    double to_double() const;

public:
    /// Higher order 64 bits
    uint64_t hi;
    /// Lower order 64 bits
    uint64_t lo;

    /// Constructor for datatype unsigned very long. Default value is 0
    /// @params hi the higher order 64-bits (as an unsigned 64-bit int)
    ///         lo the lower order 64-bits (as an unsigned 64-bit int)
    /// @returns an unsigned very long datatype which was constructed
    u_very_long(uint64_t hi = 0, uint64_t lo = 0)
        : hi(hi), lo(lo) {}

    /// Cast unsigned 64-bit int (or anything shorter) into a u_very_long
    u_very_long(uint64_t a)
        : hi(0), lo(a) {}

    /// Cast u_very_long datatype into a double
    operator double() const;

    /// Sets the current value to given value
    /// @params a given value
    u_very_long& operator=(const u_very_long& a) {
        hi = a.hi;
        lo = a.lo;
        return *this;
    }

    /// Adds one unsigned very long value to another
    /// @param a The value to add to the current unsigned very long
    /// @returns The sum of the two values
    u_very_long operator+(const u_very_long& a) const;

    /// Subtracts one unsigned very long value from another
    /// @param a The value to subtract from the current unsigned very long
    /// @returns The difference of the two values
    u_very_long operator-(const u_very_long& a) const;

    /// Negates the given unsigned very long.
    /// @returns The negative of the given value
    u_very_long operator-() const;

    /// Multiplies current unsigned very long value with given value
    /// @param a given unsigned very long value
    /// @returns the unsigned very long result of the multiplication
    u_very_long operator*(const u_very_long& a) const;

    /// Integer division of current unsigned very long value by the given
    /// value.
    /// @params a the given value
    /// @returns the result of the division operation
    u_very_long operator/(const u_very_long& a) const;

    /// Mod current value by given value
    /// @params a the value to mod the current value by
    /// @returns current value modulus a
    u_very_long operator%(const u_very_long& a) const;

    /// Test if current value is equal to given value
    /// @param a the given value
    /// @returns true if they're equal, false if they're not
    bool operator==(const u_very_long& a) const;

    /// Test if current value is not equal to given value
    /// @param a the given value
    /// @returns true if they're not equal, false if they're equal
    bool operator!=(const u_very_long& a) const;

    /// Test if current value is less than given value
    /// @param a the given value
    /// @returns true if current is less than given, false otherwise
    bool operator<(const u_very_long& a) const;

    /// Test if current value is greater than given value
    /// @param a the given value
    /// @returns true if current is greater than given, false otherwise
    bool operator>(const u_very_long& a) const;

    /// Test if current value is less than or equal to the given value
    /// @param a the given value
    /// @returns true if current is less than or equal to given, false 
    /// otherwise
    bool operator<=(const u_very_long& a) const;

    /// Test if current value is greater than or equal to given value
    /// @param a the given value
    /// @returns true if current is greater than or equal to given, false
    /// otherwise
    bool operator>=(const u_very_long& a) const;

    /// Shift current value left by given number of bits
    /// @param a the given value
    /// @returns the current value left shifted a times
    u_very_long operator<<(const unsigned char& a) const;

    /// Shift current value right by given number of bits
    /// @param a the given value
    /// @returns the current value right shifted a times
    u_very_long operator>>(const unsigned char& a) const;

    /// Returns bitwise and of current value and given value
    /// @param a given value
    /// @returns bitwise and '&' of the two values
    u_very_long operator&(const u_very_long& a) const;

    /// Returns bitwise or of current value and given value
    /// @param a given value
    /// @returns bitwise or '|' of the two values
    u_very_long operator|(const u_very_long& a) const;

    /// Returns bitwise negation of current value, i.e. not current value
    u_very_long operator~() const;

    /// Returns bitwise xor of current value and given value
    /// @param a given value
    /// @returns bitwise xor '^' of the two values
    u_very_long operator^(const u_very_long& a) const;

    /// Current unsigned very long is set to current value 
    /// plus argument value
    /// @param a The value to add to the current unsigned very long
    /// @side-effect The sum of the two values
    void operator+=(const u_very_long& a);

    /// Current unsigned very long is set to current value 
    /// minus argument value
    /// @param a The value to subtract from the current unsigned very long
    /// @side-effect The difference of the two values
    void operator-=(const u_very_long& a);

    /// Sets current value to result of current value multiplied by given 
    /// value
    /// @params a the given value
    void operator*=(const u_very_long& a);

    /// Sets current value to the result of current value divided by given 
    /// value
    /// @params a the given value
    void operator/=(const u_very_long& a);

    /// Sets the current value to current value mod given value
    /// @params a the given value
    void operator%=(const u_very_long& a);

    /// Sets the current value to current value bit shifted left a times
    /// @param a The value to shift the current value by
    void operator<<=(const unsigned char& a);

    /// Sets the current value to current value bit shifted right a times
    /// @param a The value to shift the current value by
    void operator>>=(const unsigned char& a);

    /// Sets the current value to the current value bitwise and (&)
    /// given value
    /// @param a the given value to bitwise and current value with
    void operator&=(const u_very_long& a);

    /// Sets the current value to the current value bitwise xor (^)
    /// given value
    /// @param a the given value to bitwise xor current value with
    void operator^=(const u_very_long& a);

    /// Sets the current value to the current value bitwise or (|)
    /// given value
    /// @param a the given value to bitwise or current value with
    void operator|=(const u_very_long& a);
};

#endif
