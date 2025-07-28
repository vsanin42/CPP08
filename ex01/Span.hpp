/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:56:42 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/28 20:18:51 by vsanin           ###   ########.fr       */
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
		const char* what() const throw() { return "Element limit reached when attempting to add number(s)"; }
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
		
		template <typename I>
		void addNumbers(I begin, I end)
		{
			if (std::distance(begin, end) + nums.size() > maxSize) // distance ret val?
				throw ElementLimitException();
			nums.insert(nums.end(), begin, end);
		}
		
		void addExtra(int first, int last);
		int shortestSpan(void);
		int longestSpan(void);
		void printSpan(void);
};

#endif
