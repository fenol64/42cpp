/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenol64 <fenol64@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:50:27 by mroux             #+#    #+#             */
/*   Updated: 2024/12/20 17:59:54 by fenol64          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <string>

template <class T>
class Array
{
	public:
		Array();
		Array(unsigned int i);
		~Array();
		Array(Array<T> const&);
		Array<T>&		operator=(Array<T> const&);
		T&				operator[](unsigned int i);
        bool		operator!=(Array<T> const& cl);
        bool		operator==(Array<T> const& cl);

		void			display(std::ostream& stream) const;
		unsigned int	size() const;

	protected:
		T				*_arr;
		unsigned int	_size;
};

template <class T>
std::ostream&	operator<<(std::ostream& stream, Array<T>const& cl);

template <class T>
Array<T>::Array()
{
	_arr = new T[0];
	_size = 0;
}

template <class T>
Array<T>::Array(unsigned int l)
{
	T*	init = new T();

	_size = l;
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
	{
		_arr[i] = *init;
	}
	delete init;
}

template <class T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <class T>
Array<T>::Array(Array const& cl)
{
	_arr = NULL;
	operator=(cl);
}

template <class T>
Array<T>&	Array<T>::operator=(Array<T> const& cl)
{
	if (_arr != NULL)
		delete[] _arr;
	_size = cl._size;
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = cl._arr[i];
	return (*this);
}

template <class T>
T&			Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::exception();
	return _arr[i];
}

template <class T>
void		Array<T>::display(std::ostream& stream) const
{
	unsigned int i;
	if (_size == 0)
		return;
	for (i = 0; i < _size - 1; i++)
		stream << _arr[i] << " - ";
	if (i == _size - 1)
		stream << _arr[i];
}

template <class T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

template <class T>
std::ostream&	operator<<(std::ostream& stream, Array<T>const& cl)
{
	cl.display(stream);
	return (stream);
}

template <class T>
bool		Array<T>::operator!=(Array<T> const& cl)
{
    if (_size != cl._size)
        return (true);
    for (unsigned int i = 0; i < _size; i++)
    {
        if (_arr[i] != cl._arr[i])
            return (true);
    }
    return (false);
}

template <class T>
bool		Array<T>::operator==(Array<T> const& cl)
{
    if (_size != cl._size)
        return (false);
    for (unsigned int i = 0; i < _size; i++)
    {
        if (_arr[i] != cl._arr[i])
            return (false);
    }
    return (true);
}

#endif