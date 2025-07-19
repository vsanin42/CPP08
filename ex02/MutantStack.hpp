/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:56:42 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/19 17:16:56 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <cstddef>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		struct Iterator
		{
			typedef std::forward_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;
			private:
				T* m_ptr;
			public:
				Iterator(T* ptr) : m_ptr(ptr) {}
				T& operator*() { return *m_ptr; }
				T* operator->() { return m_ptr; }
				Iterator operator++(int)
				{
					Iterator temp = *this;
					m_ptr++;
					return temp;
				}
				Iterator& operator++()
				{
					m_ptr++;
					return *this;
				}
				Iterator operator--(int)
				{
					Iterator temp = *this;
					m_ptr--;
					return temp;
				}
				Iterator& operator--()
				{
					m_ptr--;
					return *this;
				}
				bool operator==(const Iterator& ref) const { return this->m_ptr == ref.m_ptr; }
				bool operator!=(const Iterator& ref) const { return this->m_ptr != ref.m_ptr; }
		};
		Iterator begin() { return Iterator(&this->c[0]); };
		Iterator end() { return Iterator(&this->c[0] + this->c.size()); }
		typedef Iterator iterator;
};

#endif
