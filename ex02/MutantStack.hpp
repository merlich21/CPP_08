/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:09:28 by merlich           #+#    #+#             */
/*   Updated: 2022/11/07 21:48:14 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <list>
#include <vector>
#include <deque>

template< typename T >
class	MutantStack : public std::stack<T>
{
	public:

		MutantStack( void ) 
		{
			std::cout << "MutantStack default constructor called " << std::endl;
		}
		MutantStack( MutantStack const & obj )
		{
			std::cout << "MutantStack copy constructor called " << std::endl;
			*this = obj;
		}
		~MutantStack( void )
		{
			std::cout << "MutantStack destructor called " << std::endl;
		}

		MutantStack	& operator=( MutantStack const & rhs )
		{
			std::stack<T>::operator=(rhs);
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator	begin( void )
		{
			return this->c.begin();
		}

		iterator	end( void )
		{
			return std::stack<T>::c.end();
		}
};

#endif
