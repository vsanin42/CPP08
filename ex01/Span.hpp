/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:56:42 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/16 15:28:31 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class notFound : public std::exception
{
	public:
		const char* what() const throw() { return "No occurrence of element found in container"; }
};

class emptyContainer : public std::exception
{
	public:
		const char* what() const throw() { return "The container is empty"; }
};

class Span
{
	private:
		std::vector<int> arr;
		unsigned int size;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& ref);
		Span& operator=(const Span& ref);
		~Span();
		void addNumber(int num);
};

#endif
