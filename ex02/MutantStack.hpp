/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:56:42 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/19 19:56:17 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack& ref) : std::stack<T>(ref) {}
		MutantStack& operator=(const MutantStack& ref)
		{
			if (this != &ref)
				std::stack<T>::operator=(ref);
			return *this;
		};
		~MutantStack() {}

		typedef typename std::deque<T>::iterator 				iterator;
		typedef typename std::deque<T>::const_iterator			const_iterator;
		typedef typename std::deque<T>::reverse_iterator		reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator	const_reverse_iterator;
		
		iterator		 		begin()		{ return this->c.begin(); }
		iterator 		 		end()		{ return this->c.end(); }
		reverse_iterator 		rbegin()	{ return this->c.rbegin(); }
		reverse_iterator 		rend()		{ return this->c.rend(); }
		
		const_iterator		 	begin()		const	{ return this->c.begin(); }
		const_iterator 		 	end()		const	{ return this->c.end(); }
		const_reverse_iterator	rbegin()	const	{ return this->c.rbegin(); }
		const_reverse_iterator	rend()		const	{ return this->c.rend(); }
};

#endif
