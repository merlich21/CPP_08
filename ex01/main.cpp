/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:40:39 by merlich           #+#    #+#             */
/*   Updated: 2022/11/07 22:55:02 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// int	main( void )
// {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

int	main( void )
{
	Span sp = Span(100000);
	Span sp2 = Span(10);
	
	/* TEST 1 TO FEW VALUES */
	sp2.addManyNumbers(10);
	std::cout << sp2 << std::endl;
	// std::cout << sp2.getSortedArr() << std::endl;
	try
	{
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch( Span::NoSpanException const & e )
	{
		std::cerr << e.what() << std::endl;
	}

	/* TEST 2 TO MANY VALUES */
	try
	{
		sp.addManyNumbers(1000000);
	}
	catch( Span::OverflowException const & e )
	{
		std::cerr << e.what() << std::endl;
	}
	
	/* TEST 3 OK */
	try
	{
		sp.addManyNumbers(100000);
	}
	catch( Span::OverflowException const & e )
	{
		std::cerr << e.what() << std::endl;
	}

	/* TEST 4 OK */
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch( Span::NoSpanException const & e )
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

