/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:57:53 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/19 19:41:11 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <deque>
#include <vector>

static void printMutant(MutantStack<int>& stack);
static void constPrintMutant(const MutantStack<int>& stack);

int main(void)
{
	{
		std::cout << "~~~ subject tests (MutantStack) ~~~" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		//[...]
		
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n~~~ subject tests (std::list) ~~~" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);

		//[...]
		
		mstack.push_back(0);
		
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int, std::list<int> > s(mstack);
	}
	{
		std::cout << "\n~~~ subject tests (std::deque) ~~~" << std::endl;
		std::deque<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);

		//[...]
		
		mstack.push_back(0);
		
		std::deque<int>::iterator it = mstack.begin();
		std::deque<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n~~~ subject tests (std::vector) ~~~" << std::endl;
		std::vector<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);

		//[...]
		
		mstack.push_back(0);
		
		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int, std::vector<int> > s(mstack);
	}
	{
		std::cout << "\n~~~ MutantStack, printing with different iterator types ~~~" << std::endl;
		MutantStack<int> mstack;
		for (int i = 0; i < 42; i++)
			mstack.push(i);
		std::cout << "size: " << mstack.size() << std::endl;
		printMutant(mstack);
		std::cout << std::endl;
		constPrintMutant(mstack);
		std::cout << std::endl;
	}
	{
		std::cout << "\n~~~ empty MutantStack ~~~" << std::endl;
		MutantStack<int> empty;
		std::cout << "is MutantStack empty? " << ((empty.begin() == empty.end()) ? "yes" : "no") << std::endl;
	}
	{
		std::cout << "\n~~~ ocf ~~~" << std::endl;
		MutantStack<char> a = MutantStack<char>();
		std::cout << "size a (default constructor): " << a.size() << std::endl;
		a.push('a');
		a.push('b');
		a.push('c');
		std::cout << "size a (after push): " << a.size() << std::endl;
		std::cout << "a:";
		MutantStack<char>::iterator it = a.begin();
		MutantStack<char>::iterator ite = a.end();
		while (it != ite)
		{
			std::cout << " " << *it;
			++it;
		}
		std::cout << std::endl;

		MutantStack<char> b(a);
		std::cout << "size b (copy constructor): " << b.size() << std::endl;
		std::cout << "b:";
		it = b.begin();
		ite = b.end();
		while (it != ite)
		{
			std::cout << " " << *it;
			++it;
		}
		std::cout << std::endl;

		MutantStack<char> c;
		std::cout << "size c (default constructor): " << c.size() << std::endl;
		c = b;
		std::cout << "size c (copy operator): " << c.size() << std::endl;
		std::cout << "c:";
		it = c.begin();
		ite = c.end();
		while (it != ite)
		{
			std::cout << " " << *it;
			++it;
		}
		std::cout << std::endl;
	}
	return 0;
}

static void printMutant(MutantStack<int>& stack)
{
	MutantStack<int>::iterator it = stack.begin();
	MutantStack<int>::iterator itend = stack.end();
	
	std::cout << "iterators:" << std::endl;
	while (it != itend)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	
	MutantStack<int>::reverse_iterator rit = stack.rbegin();
	MutantStack<int>::reverse_iterator ritend = stack.rend();
	
	std::cout << "reverse iterators:" << std::endl;
	while (rit != ritend)
	{
		std::cout << *rit << " ";
		++rit;
	}
}

static void constPrintMutant(const MutantStack<int>& stack)
{
	MutantStack<int>::const_iterator cit = stack.begin();
	MutantStack<int>::const_iterator citend = stack.end();
	
	std::cout << "const iterators:" << std::endl;
	while (cit != citend)
	{
		std::cout << *cit << " ";
		++cit;
	}
	std::cout << std::endl;
	
	MutantStack<int>::const_reverse_iterator crit = stack.rbegin();
	MutantStack<int>::const_reverse_iterator critend = stack.rend();
	
	std::cout << "const reverse iterators:" << std::endl;
	while (crit != critend)
	{
		std::cout << *crit << " ";
		++crit;
	}
}
