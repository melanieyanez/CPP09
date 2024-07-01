/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:15:20 by melanieyane       #+#    #+#             */
/*   Updated: 2024/07/01 16:22:14 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		PmergeMe sorter(argc, argv);

		std::cout << "Before: ";
		sorter.print(sorter.getVec());
		//sorter.print(sorter.getLst());

		clock_t start = clock();
		sorter.setSortedVec(sorter.mergeInsertSort(sorter.getVec()));
		clock_t end = clock();
		double duration_vec = double(end - start) / CLOCKS_PER_SEC;

		start = clock();
		sorter.setSortedLst(sorter.mergeInsertSort(sorter.getLst()));
		end = clock();
		double duration_lst = double(end - start) / CLOCKS_PER_SEC;

		std::cout << "After: ";
		sorter.print(sorter.getSortedVec());
		//sorter.print(sorter.getSortedLst());

		std::cout << "Time to process a range of " << sorter.getVec().size() << " elements with std::vector: " << duration_vec << " us" << std::endl;
		std::cout << "Time to process a range of " << sorter.getLst().size() << " elements with std::list: " << duration_lst << " us" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return 0;
}