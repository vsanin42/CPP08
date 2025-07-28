/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:50:20 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/28 20:47:36 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <climits>

Span::Span() : nums(), maxSize(0)
{
	std::cout << "Default constructor\n";
}

Span::Span(unsigned int n) : nums(), maxSize(n)
{
	std::cout << "Parametrized constructor\n";
}

Span::Span(const Span& ref) : nums(ref.nums), maxSize(ref.maxSize)
{
	std::cout << "Copy constructor\n";
}

Span& Span::operator=(const Span& ref)
{
	std::cout << "Copy operator\n";
	if (this != &ref)
	{
		this->nums = ref.nums;
		this->maxSize = ref.maxSize;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Destructor\n";
}

const std::vector<int>& Span::getNums(void) const { return nums; }

void Span::addNumber(int num)
{
	if (nums.size() == maxSize)
		throw ElementLimitException();
	nums.push_back(num);
}

void Span::addExtra(int first, int last)
{
	long long extraSize = std::llabs(static_cast<long long>(first) - last) + 1; // force first <= last ?
	if (extraSize > UINT_MAX || extraSize + nums.size() > maxSize)
		throw ElementLimitException();
	size_t safeExtraSize = static_cast<size_t>(extraSize);
	std::vector<int> extra(safeExtraSize);
	int step = first < last ? 1 : -1;
	for (size_t i = 0; i < safeExtraSize; i++)
	{
		extra[i] = first;
		first += step;
	}
	this->addNumbers(extra.begin(), extra.end());
}

int Span::shortestSpan(void)
{
	if (nums.size() < 2)
		throw SpanUnavailableException();
	std::vector<int> sorted = nums;
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::iterator current = sorted.begin();
	std::vector<int>::iterator next = current + 1;
	int diff = *next - *current;
	while (next != sorted.end())
	{
		if (*next - *current < diff)
			diff = *next - *current;
		current++;
		next++;
	}
	return diff;
}

int Span::longestSpan(void)
{
	if (nums.size() < 2)
		throw SpanUnavailableException();
	std::vector<int>::iterator min = std::min_element(nums.begin(), nums.end());
	std::vector<int>::iterator max = std::max_element(nums.begin(), nums.end());
	return *max - *min;
}

void Span::printSpan(void)
{
	size_t size = nums.size();
	std::cout << "span:";
	if (!size)
	{
		std::cout << " empty" << std::endl;
		return;
	}
	if (size < 10)
	{
		for (size_t i = 0; i < size; i++)
			std::cout << " " << nums[i];
	}
	else
	{
		for (size_t i = 0; i < 3; i++)
			std::cout << " " << nums[i];
		std::cout << " ... ";
		for (size_t i = size - 3; i < size; i++)
			std::cout << " " << nums[i];
	}
	std::cout << std::endl;
}
