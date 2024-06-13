/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:15:38 by melanieyane       #+#    #+#             */
/*   Updated: 2024/06/13 18:03:41 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &src) : _vec(src.getVec()), _deq(src.getDeq()){}

PmergeMe::~PmergeMe(){}
		
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs){
	if (this != &rhs)
	{
		this->_vec = rhs.getVec();
		this->_deq = rhs.getDeq();
	}
	return *this;
}

std::vector<int> PmergeMe::getVec() const{
	return this->_vec;
}

std::deque<int> PmergeMe::getDeq() const{
	return this->_deq;
}

void PmergeMe::print(std::vector<int> &vec){}
		
void PmergeMe::print(std::deque<int> &deq){}

void PmergeMe::mergeSort(std::vector<int> &vec){}
		
void PmergeMe::mergeSort(std::deque<int> &deq){}

void PmergeMe::insertSort(std::vector<int> &vec){}

void PmergeMe::insertSort(std::deque<int> &deq){}

void PmergeMe::mergeInsertSort(std::vector<int> &vec){}

void PmergeMe::mergeInsertSort(std::deque<int> &deq){}
	