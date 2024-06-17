/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:15:38 by melanieyane       #+#    #+#             */
/*   Updated: 2024/06/17 15:09:35 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		try
		{
			int num = std::atoi(argv[i]);
			if (num <= 0)
				throw std::runtime_error("Invalid input");
			this->_vec.push_back(num);
			this->_lst.push_back(num);
		}
		catch(const std::exception& e)
		{
			throw std::runtime_error("Invalid input");
		}
	}
}

PmergeMe::PmergeMe(const PmergeMe &src) : _vec(src.getVec()), _lst(src.getLst()){}

PmergeMe::~PmergeMe(){}
		
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs){
	if (this != &rhs)
	{
		this->_vec = rhs.getVec();
		this->_lst = rhs.getLst();
	}
	return *this;
}

std::vector<int> PmergeMe::getVec() const
{
	return this->_vec;
}

std::vector<int> PmergeMe::getSortedVec() const
{
	return this->_sortedVec;
}

void PmergeMe::setSortedVec(std::vector<int> sortedVec)
{
	this->_sortedVec = sortedVec;
}

std::list<int> PmergeMe::getLst() const
{
	return this->_lst;
}

std::list<int> PmergeMe::getSortedLst() const
{
	return this->_sortedLst;
}

void PmergeMe::setSortedLst(std::list<int> sortedLst)
{
	this->_sortedLst = sortedLst;
}

std::vector<int> PmergeMe::mergeInsertSort(const std::vector<int> &sequence)
{
	if (sequence.size() <= 1)
		return sequence;
		
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < sequence.size(); i += 2)
		pairs.push_back(std::pair<int, int>(sequence[i], sequence[i + 1]));

	std::vector<int> smaller;
	std::vector<int> larger;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first > pairs[i].second)
		{
			larger.push_back(pairs[i].first);
			smaller.push_back(pairs[i].second);
		}
		else
		{
			larger.push_back(pairs[i].second);
			smaller.push_back(pairs[i].first);
		}
	}

	if (sequence.size() % 2)
		smaller.push_back(sequence.back());

	if (larger.size() > 1)
		larger = mergeInsertSort(larger);

	for (size_t i = 0; i < smaller.size(); i++)
	{
		std::vector<int>::iterator it = std::lower_bound(larger.begin(), larger.end(), smaller[i]);
		larger.insert(it, smaller[i]);
	}

	return larger;
}

std::list<int> PmergeMe::mergeInsertSort(const std::list<int> &sequence)
{
	if (sequence.size() <= 1)
		return sequence;

	std::list<std::pair<int, int> > pairs;
	std::list<int> temp = sequence;
	while (temp.size() >= 2)
	{
		int a = temp.front();
		temp.pop_front();
		int b = temp.front();
		temp.pop_front();
		pairs.push_back(std::pair<int, int>(a, b));
	}

	std::list<int> smaller;
	std::list<int> larger;
	while (!pairs.empty())
	{
		int first = pairs.front().first;
		int second = pairs.front().second;
		pairs.pop_front();

		if (first > second)
		{
			larger.push_back(first);
			smaller.push_back(second);
		}
		else
		{
			larger.push_back(second);
			smaller.push_back(first);
		}
	}
	
	if (!temp.empty())
	{
		smaller.push_back(temp.front());
		temp.pop_front();
	}

	if (larger.size() > 1)
		larger = mergeInsertSort(larger);

	while (!smaller.empty())
	{
		std::list<int>::iterator it = std::lower_bound(larger.begin(), larger.end(), smaller.front());
		larger.insert(it, smaller.front());
		smaller.pop_front();
	}

	return larger;
}
	