#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointValue( 0 ) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed( int const n ) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed( float const n ) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf( n * ( 1 << _fractionalBits ) );
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
    std::cout << "Assignation operator called" << std::endl;
    if ( this != &rhs ) {
        _fixedPointValue = rhs.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPointValue = raw;
}

float Fixed::toFloat( void ) const {
    return (float)_fixedPointValue / ( 1 << _fractionalBits );
}

int Fixed::toInt( void ) const {
    return _fixedPointValue >> _fractionalBits;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs ) {
    o << rhs.toFloat();
    return o;
}

Fixed Fixed::operator+( Fixed const & rhs ) const {
    return Fixed( toFloat() + rhs.toFloat() );
}

Fixed Fixed::operator-( Fixed const & rhs ) const {
    return Fixed( toFloat() - rhs.toFloat() );
}

Fixed Fixed::operator*( Fixed const & rhs ) const {
    return Fixed( toFloat() * rhs.toFloat() );
}

Fixed Fixed::operator/( Fixed const & rhs ) const {
    return Fixed( toFloat() / rhs.toFloat() );
}

bool Fixed::operator>( Fixed const & rhs ) const {
    return toFloat() > rhs.toFloat();
}

bool Fixed::operator<( Fixed const & rhs ) const {
    return toFloat() < rhs.toFloat();
}

bool Fixed::operator>=( Fixed const & rhs ) const {
    return toFloat() >= rhs.toFloat();
}

bool Fixed::operator<=( Fixed const & rhs ) const {
    return toFloat() <= rhs.toFloat();
}

bool Fixed::operator==( Fixed const & rhs ) const {
    return toFloat() == rhs.toFloat();
}

bool Fixed::operator!=( Fixed const & rhs ) const {
    return toFloat() != rhs.toFloat();
}

Fixed & Fixed::operator++( void ) {
    _fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++( int ) {
    Fixed tmp( *this );
    operator++();
    return tmp;
}

Fixed & Fixed::operator--( void ) {
    _fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed tmp( *this );
    operator--();
    return tmp;
}

Fixed & Fixed::min( Fixed & a, Fixed & b ) {
    return a < b ? a : b;
}

Fixed const & Fixed::min( Fixed const & a, Fixed const & b ) {
    return a < b ? a : b;
}