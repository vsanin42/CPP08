/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:56:42 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/17 15:33:12 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NotFoundException : public std::exception
{
	public:
		const char* what() const throw() { return "No occurrence of element found in container"; }
};

class EmptyContainerException : public std::exception
{
	public:
		const char* what() const throw() { return "The container is empty"; }
};

template <typename T>
typename T::iterator easyfind(T& t, int i)
{
	if (t.empty())
		throw EmptyContainerException();
	typename T::iterator it = std::find(t.begin(), t.end(), i);
	if (it == t.end())
		throw NotFoundException();
	return it;
}

#endif
