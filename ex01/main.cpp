/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:57:53 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/17 22:27:01 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>

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
		std::cout << "\n~~~ addExtra() ~~~" << std::endl;
		Span span(10);
		
		span.addNumber(1);
		span.addExtra(22, 30);
		span.printSpan();

		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
	return 0;
}
