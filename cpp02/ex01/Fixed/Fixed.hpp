#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <ostream>

class Fixed {
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
    public:
        Fixed( void );
        Fixed( Fixed const & src );
        Fixed( int const n );
        Fixed( float const n );
        ~Fixed( void );
        Fixed & operator=( Fixed const & rhs );
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs );

#endif

