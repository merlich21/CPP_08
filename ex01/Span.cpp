/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:40:46 by merlich           #+#    #+#             */
/*   Updated: 2022/11/07 20:06:25 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span( void ) : _N(0)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span( unsigned int n ) : _N(n)
{
	std::cout << "Span custom constructor called" << std::endl;
}

Span::Span( Span const & obj )
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = obj;
}

Span::~Span( void )
{
	std::cout << "Span destructor called" << std::endl;
}

Span & Span::operator=( Span const & rhs )
{
	this->_arr = rhs._arr;
	this->_N = rhs._N;
	return (*this);
}

std::vector<int>	Span::getArr( void ) const
{
	return (this->_arr);
}

unsigned int	Span::getN( void ) const
{
	return (this->_N);
}

const char	*Span::OverflowException::what( void ) const throw()
{
	return ("Overflow!");
}

const char	*Span::NoSpanException::what( void ) const throw()
{
	return ("Too few values!");
}

void	Span::addNumber( int num )
{
	if (this->_arr.size() == this->_N)
		throw Span::OverflowException();
	this->_arr.push_back(num);
}

int		Span::shortestSpan( void )
{
	unsigned int	i;
	int				tmp;
	int				min = INT_MAX;

	if (this->_arr.size() < 2)
		throw Span::NoSpanException();
	std::sort(this->_arr.begin(), this->_arr.end());	
	for (i = 0; i < this->_N - 1; i++)
	{
		tmp = this->_arr[i + 1] - this->_arr[i];
		if (tmp < min)
			min = tmp;
	}
	return (min);
}

int		Span::longestSpan( void )
{
	int	max;
	int	min;

	if (this->_arr.size() < 2)
		throw Span::NoSpanException();
	max = *std::max_element(this->_arr.begin(), this->_arr.end());
	min = *std::min_element(this->_arr.begin(), this->_arr.end());
	return (max - min);
}

void	Span::addManyNumbers( size_t count )
{
	size_t	i;

	if (count > this->_N)
		throw OverflowException();
	srand(time(NULL));
	for(i = 0; i < this->_N; i++)
		this->addNumber(rand() % 1000);
}

std::ostream &	operator<<( std::ostream & o, Span const & sp )
{
	size_t i;

	for (i = 0; i < sp.getN(); i++)
		std::cout << sp.getArr()[i] << std::endl;
	return o;
}
