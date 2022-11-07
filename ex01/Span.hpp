/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:41:42 by merlich           #+#    #+#             */
/*   Updated: 2022/11/06 23:56:34 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <climits>
#include <vector>
#include <random>

class	Span
{
	public:

		Span( void );
		Span( unsigned int n );
		Span( Span const & obj );
		~Span( void );

		Span & operator=( Span const & rhs );

		std::vector<int>	getArr( void ) const;
		std::vector<int>	getSortedArr( void ) const;
		unsigned int		getN( void ) const;

		class	OverflowException : public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};

		class	NoSpanException : public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};

		void	addNumber( int num );
		int		shortestSpan( void );
		int		longestSpan( void );
		void	addManyNumbers( size_t count );

	private:

		std::vector<int>	_arr;
		unsigned int		_N;

};

std::ostream &	operator<<( std::ostream & o, Span const & sp );

#endif
