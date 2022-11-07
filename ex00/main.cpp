/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:55:27 by merlich           #+#    #+#             */
/*   Updated: 2022/11/06 21:39:23 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main( void )
{
	// std::list<int> l;
	std::vector<int> l;

	l.push_back(0);
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	try
	{
		std::cout << *easyfind(l, 42) << std::endl;
	}
	catch ( std::out_of_range const & e )
	{
		std::cout << e.what() << std::endl;
	}

	l.push_back(42);
	try
	{
		std::cout << *easyfind(l, 42) << std::endl;
	}
	catch ( std::out_of_range const & e )
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
