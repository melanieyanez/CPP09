/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:15:29 by melanieyane       #+#    #+#             */
/*   Updated: 2024/06/13 18:01:03 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &rhs);
		
		std::vector<int> getVec() const;
		std::deque<int> getDeq() const;

		void print(std::vector<int> &vec);
		void print(std::deque<int> &deq);

		void mergeSort(std::vector<int> &vec);
		void mergeSort(std::deque<int> &deq);

		void insertSort(std::vector<int> &vec);
		void insertSort(std::deque<int> &deq);

		void mergeInsertSort(std::vector<int> &vec);
		void mergeInsertSort(std::deque<int> &deq);
	
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
};

#endif