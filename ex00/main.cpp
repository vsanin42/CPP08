/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:57:53 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/15 19:36:03 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

static void print(int n)
{
	std::cout << ' ' << n;
}

int main(void)
{
	{
		std::cout << "~~~ empty ~~~" << std::endl;
		std::vector<int> emptyVector;
		try
		{
			easyfind(emptyVector, 42);
		}
		catch(const emptyContainer& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::deque<int> emptyDeque;
		try
		{
			easyfind(emptyDeque, 42);
		}
		catch(const emptyContainer& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::list<int> emptyList;
		try
		{
			easyfind(emptyList, 42);
		}
		catch(const emptyContainer& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}
	{
		std::cout << "~~~ vector ~~~" << std::endl;
		int ints[] = { 1, 2, 3, 100, 500 };
		std::vector<int> vector(ints, ints + 5);
		std::cout << "vector:";
		std::for_each(vector.begin(), vector.end(), ::print);
		std::cout << std::endl;

		std::cout << "easyfind(vector, 1): " << *easyfind(vector, 1) << std::endl;
		std::cout << "easyfind(vector, 100): " << *easyfind(vector, 100) << std::endl;
		std::cout << "easyfind(vector, 500): " << *easyfind(vector, 500) << std::endl;
		std::cout << "easyfind(vector, -1): "; 
		try
		{
			std::cout << *easyfind(vector, -1) << std::endl;
		}
		catch(const notFound& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "easyfind(vector, 999): "; 
		try
		{
			std::cout << *easyfind(vector, 999) << std::endl;
		}
		catch(const notFound& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "~~~ deque ~~~" << std::endl;
		std::deque<int> deque;
		deque.push_back(1);
		deque.push_back(2);
		deque.push_back(3);
		deque.push_back(100);
		deque.push_back(500);
		std::cout << "deque:";
		std::for_each(deque.begin(), deque.end(), ::print);
		std::cout << std::endl;

		std::cout << "easyfind(deque, 1): " << *easyfind(deque, 1) << std::endl;
		std::cout << "easyfind(deque, 100): " << *easyfind(deque, 100) << std::endl;
		std::cout << "easyfind(deque, 500): " << *easyfind(deque, 500) << std::endl;
		std::cout << "easyfind(deque, -1): "; 
		try
		{
			std::cout << *easyfind(deque, -1) << std::endl;
		}
		catch(const notFound& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "easyfind(deque, 999): "; 
		try
		{
			std::cout << *easyfind(deque, 999) << std::endl;
		}
		catch(const notFound& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "~~~ list ~~~" << std::endl;
		std::list<int> list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(100);
		list.push_back(500);
		std::cout << "list:";
		std::for_each(list.begin(), list.end(), ::print);
		std::cout << std::endl;

		std::cout << "easyfind(list, 1): " << *easyfind(list, 1) << std::endl;
		std::cout << "easyfind(list, 100): " << *easyfind(list, 100) << std::endl;
		std::cout << "easyfind(list, 500): " << *easyfind(list, 500) << std::endl;
		std::cout << "easyfind(list, -1): "; 
		try
		{
			std::cout << *easyfind(list, -1) << std::endl;
		}
		catch(const notFound& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "easyfind(list, 999): "; 
		try
		{
			std::cout << *easyfind(list, 999) << std::endl;
		}
		catch(const notFound& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
