/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:56:42 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/17 22:18:51 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class ElementLimitException : public std::exception
{
	public:
		const char* what() const throw() { return "Element limit reached"; }
};

class SpanUnavailableException : public std::exception
{
	public:
		const char* what() const throw() { return "Cannot determine span of 0 or 1 elements"; }
};

class Span
{
	private:
		std::vector<int> nums;
		unsigned int maxSize;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& ref);
		Span& operator=(const Span& ref);
		~Span();
		const std::vector<int>& getNums(void) const;
		void addNumber(int num);
		void addExtra(int first, int last);
		int shortestSpan(void);
		int longestSpan(void);
		void printSpan(void);
};

#endif
