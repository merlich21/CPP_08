/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:55:40 by merlich           #+#    #+#             */
/*   Updated: 2022/11/06 21:39:28 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template< class T >
typename T::const_iterator	easyfind( T const & arr, int const & num )
{
	typename T::const_iterator	it;

	it = std::find(arr.begin(), arr.end(), num);
	if (it == arr.end())
		throw std::out_of_range("No occurence found!");
	return it;
}

#endif
