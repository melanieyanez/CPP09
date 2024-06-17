/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:15:29 by melanieyane       #+#    #+#             */
/*   Updated: 2024/06/17 15:11:03 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>

class PmergeMe{
	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		
		PmergeMe &operator=(const PmergeMe &rhs);
		
		std::vector<int> getVec() const;
		std::vector<int> getSortedVec() const;
		void setSortedVec(std::vector<int> sortedVec);
		
		std::list<int> getLst() const;
		std::list<int> getSortedLst() const;
		void setSortedLst(std::list<int> sortedLst);

		template <typename T>
		void print(const T &sequence) const;

		std::vector<int> mergeInsertSort(const std::vector<int> &sequence);
		std::list<int> mergeInsertSort(const std::list<int> &sequence);

	
	private:
		std::vector<int> _vec;
		std::vector<int> _sortedVec;
		std::list<int> _lst;
		std::list<int> _sortedLst;
};

template <typename T>
void PmergeMe::print(const T &sequence) const
{
	typename T::const_iterator it;
	for (it = sequence.begin(); it != sequence.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#endif