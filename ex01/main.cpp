/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:57:53 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/29 14:36:29 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <climits>

int main(void)
{
	{
		std::cout << "~~~ subject tests ~~~" << std::endl;	
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\n~~~ ocf tests ~~~" << std::endl;
		Span def;
		try
		{
			def.addNumber(42);
		}
		catch(const ElementLimitException& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		Span param(3);
		param.addNumber(1);
		param.addNumber(2);
		param.addNumber(3);
		std::cout << "param: " << param.getNums()[0] << " "
				  << param.getNums()[1] << " " << param.getNums()[2] << std::endl;
		try
		{
			param.addNumber(42);
		}
		catch(const ElementLimitException& e)
		{
			std::cerr << e.what() << '\n';
		}

		Span copy(param);
		std::cout << "copy: " << copy.getNums()[0] << " "
				  << copy.getNums()[1] << " " << copy.getNums()[2] << std::endl;

		def = copy;
		std::cout << "def after copy operation: " << def.getNums()[0] << " "
				  << def.getNums()[1] << " " << def.getNums()[2] << std::endl;
	}
	{
		std::cout << "\n~~~ empty/one element ~~~" << std::endl;
		Span span(10);
		
		span.printSpan();
		try
		{
			std::cout << "shortest: " << span.shortestSpan() << std::endl;
			std::cout << "longest: " << span.longestSpan() << std::endl;
		}
		catch(const SpanUnavailableException& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		span.addNumber(42);
		span.printSpan();
		try
		{
			std::cout << "shortest: " << span.shortestSpan() << std::endl;
			std::cout << "longest: " << span.longestSpan() << std::endl;
		}
		catch(const SpanUnavailableException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\n~~~ sorted/unsorted ~~~" << std::endl;
		Span a(4);
		a.addNumber(1);
		a.addNumber(3);
		a.addNumber(10);
		a.addNumber(100);

		Span b(4);
		b.addNumber(10);
		b.addNumber(1);
		b.addNumber(100);
		b.addNumber(3);

		a.printSpan();
		b.printSpan();
		std::cout << "shortest a: " << a.shortestSpan() << std::endl;
		std::cout << "shortest b: " << b.shortestSpan() << std::endl;
		std::cout << "longest a: " << a.longestSpan() << std::endl;
		std::cout << "longest b: " << b.longestSpan() << std::endl;
	}
	{
		std::cout << "\n~~~ addExtra() - default ~~~" << std::endl;
		Span span(10);
		
		span.addNumber(1);
		span.printSpan();
		span.addExtra(22, 30);
		span.printSpan();

		std::cout << "shortest: " << span.shortestSpan() << std::endl;
		std::cout << "longest: " << span.longestSpan() << std::endl;
	}
	{
		std::cout << "\n~~~ addExtra() - limit ~~~" << std::endl;
		Span span(10);

		span.printSpan();
		try
		{
			span.addExtra(1, 42);
		}
		catch(const ElementLimitException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\n~~~ addExtra() - inverted ~~~" << std::endl;
		Span span(10);

		span.printSpan();
		span.addExtra(99, 90);
		span.printSpan();
		std::cout << "shortest: " << span.shortestSpan() << std::endl;
		std::cout << "longest: " << span.longestSpan() << std::endl;
	}
	{
		std::cout << "\n~~~ addExtra() - single ~~~" << std::endl;
		Span span(2);

		span.addExtra(24, 24);
		span.printSpan();
		span.addExtra(42, 42);
		span.printSpan();
	}
	{
		std::cout << "\n~~~ addExtra() - 10000 ~~~" << std::endl;
		Span span(10000);
		
		span.addExtra(-5000, 4999);
		span.printSpan();

		std::cout << "shortest: " << span.shortestSpan() << std::endl;
		std::cout << "longest: " << span.longestSpan() << std::endl;
	}
	{
		std::cout << "\n~~~ addExtra() - 100000 ~~~" << std::endl;
		Span span(100000);
		
		span.addExtra(-50000, 49999);
		span.printSpan();

		std::cout << "shortest: " << span.shortestSpan() << std::endl;
		std::cout << "longest: " << span.longestSpan() << std::endl;
	}
	{
		std::cout << "\n~~~ addExtra() - uintmax ~~~" << std::endl;
		Span span(UINT_MAX);
		try
		{
			span.addExtra(INT_MIN, INT_MAX);
		}
		catch(const ElementLimitException& e)
		{
			std::cerr << e.what() << '\n';
		}
		span.printSpan();
	}
	{
		std::cout << "\n~~~ addNumbers() - default ~~~" << std::endl;
		Span span(6);
		
		span.addNumber(42);
		span.printSpan();

		int ints[] = { 1, 2, 3, 100, 500 };
		std::vector<int> vector(ints, ints + 5);
		span.addNumbers(vector.begin(), vector.end());
		span.printSpan();

		std::cout << "shortest: " << span.shortestSpan() << std::endl;
		std::cout << "longest: " << span.longestSpan() << std::endl;
	}
	{
		std::cout << "\n~~~ addNumbers() - limit ~~~" << std::endl;
		Span span(5);
		
		span.addNumber(42);
		span.printSpan();

		int ints[] = { 1, 2, 3, 100, 500 };
		std::vector<int> vector(ints, ints + 5);
		try
		{
			span.addNumbers(vector.begin(), vector.end());
		}
		catch(const ElementLimitException& e)
		{
			std::cerr << e.what() << '\n';
		}
		span.printSpan();
	}
	{
		std::cout << "\n~~~ addNumbers() - inverted ~~~" << std::endl;
		Span span(5);

		span.printSpan();
		int ints[] = { 1, 2, 3, 100, 500 };
		std::vector<int> vector(ints, ints + 5);
		try
		{
			span.addNumbers(vector.end(), vector.begin());
		}
		catch(const std::invalid_argument& e)
		{
			std::cerr << e.what() << '\n';
		}
		span.printSpan();
	}
	{
		std::cout << "\n~~~ addNumbers() - single ~~~" << std::endl;
		Span span(2);

		int int24[] = { 24 };
		int int42[] = { 42 };
		std::vector<int> vector1(int24, int24 + 1);
		std::vector<int> vector2(int42, int42 + 1);
		span.addNumbers(vector1.begin(), vector1.end());
		span.printSpan();
		span.addNumbers(vector2.begin(), vector2.end());
		span.printSpan();
	}
	{
		std::cout << "\n~~~ addNumbers() - const ~~~" << std::endl;
		Span span(5);
		span.printSpan();

		int ints[] = { 1, 2, 3, 100, 500 };
		std::vector<int> vector(ints, ints + 5);
		std::vector<int>::const_iterator b = vector.begin();
		std::vector<int>::const_iterator e = vector.end();
		span.addNumbers(b, e);
		span.printSpan();
	}
	return 0;
}
