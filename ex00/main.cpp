/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:37:14 by melanieyane       #+#    #+#             */
/*   Updated: 2024/07/01 15:47:02 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc [input_file]" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange exchange;

		std::string ratesFile = "data.csv";
		exchange.loadRates(ratesFile);
		
		//std::cout << "Loaded rates:" << std::endl;
		//exchange.printRates();

		std::string inputFile = argv[1];
		exchange.processFile(inputFile);

		BitcoinExchange exchangeCopy(exchange);
		//std::cout << "\nLoaded rates (copy):" << std::endl;
		//exchangeCopy.printRates();

		BitcoinExchange anotherExchange;
		anotherExchange = exchange;
		//std::cout << "\nLoaded rates (assigned):" << std::endl;
		//anotherExchange.printRates();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}