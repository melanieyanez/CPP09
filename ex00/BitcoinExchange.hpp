/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:37:28 by melanieyane       #+#    #+#             */
/*   Updated: 2024/06/09 16:32:07 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		//BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		//BitcoinExchange &operator=(const BitcoinExchange &rhs);

		void	printRates() const;
		
		void	loadRates(const std::string &filename);
		void	processFile(const std::string &filename);
		
		bool	validateDate(const std::string &date, bool errorDisplay) const;
		bool	validateValue(const std::string &value, bool errorDisplay, bool upperLimit) const;
	
	private:
		std::map<std::string, float> _rates;
		
};

#endif