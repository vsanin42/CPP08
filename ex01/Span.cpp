/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:50:20 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/16 15:34:41 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	std::cout << "Default constructor\n";
}

Span::Span(unsigned int n) // .reserve(n) ???
{
	std::cout << "Parametrized constructor\n";
}

Span::Span(const Span& ref)
{
	std::cout << "Copy constructor\n";
}

Span& Span::operator=(const Span& ref)
{
	std::cout << "Copy operator\n";
	if (this != &ref)
	{
		// todo
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Destructor\n";
}

void Span::addNumber(int num)
{
	
}
