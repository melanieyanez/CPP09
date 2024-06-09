/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:37:40 by melanieyane       #+#    #+#             */
/*   Updated: 2024/06/09 16:33:09 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange(){
	loadRates("data.csv");
	processFile("input.txt");
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::printRates() const {
    for (std::map<std::string, float>::const_iterator it = _rates.begin(); it != _rates.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

void	BitcoinExchange::loadRates(const std::string &filename){
	std::ifstream file(filename);
	if (!file.is_open()){
		std::cerr << "Error: could not open file" << std::endl;
		return ;
	} //ajouter une exception
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)){
		std::istringstream iss(line);
		std::string date;
		std::string rateStr;
		float rate;
		if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
		{
			date.erase(date.find_last_not_of(" \n\r\t") + 1);
			date.erase(0, date.find_first_not_of(" \n\r\t"));
			rateStr.erase(rateStr.find_last_not_of(" \n\r\t") + 1);
			rateStr.erase(0, rateStr.find_first_not_of(" \n\r\t"));
			if (!BitcoinExchange::validateDate(date, false) || !BitcoinExchange::validateValue(rateStr, false, false))
				continue;
			rate = std::atof(rateStr.c_str());
			if (this->_rates.find(date) != this->_rates.end())
				continue;
			this->_rates.insert(std::pair<std::string, float>(date, rate));
		}
	}
	file.close();
}

bool	BitcoinExchange::validateDate(const std::string &date, bool errorDisplay) const{

	if (date.size() != 10) {
		if (errorDisplay)
        	std::cerr << "Error: date format is invalid" << std::endl;
        return false;
    }
    
	for (size_t i = 0; i < date.size(); ++i)
	{
        if ((i == 4 || i == 7) && date[i] != '-') 
		{
			if (errorDisplay)
            	std::cerr << "Error: date format is invalid" << std::endl;
            return false;
        }
		else if (i != 4 && i != 7 && !isdigit(date[i]))
		{
			if (errorDisplay)
            	std::cerr << "Error: date format is invalid" << std::endl;
            return false;
        }
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 1900 || year > 2099)
	{
		if (errorDisplay)
        	std::cerr << "Error: year is out of valid range (1900-2099)" << std::endl;
        return false;
    }
    if (month < 1 || month > 12)
	{
		if (errorDisplay)
        	std::cerr << "Error: month is out of valid range (01-12)" << std::endl;
        return false;
    }
    if (day < 1 || day > 31)
	{
		if (errorDisplay)
        	std::cerr << "Error: day is out of valid range (01-31)" << std::endl;
        return false;
    }

    return true;
}

bool	BitcoinExchange::validateValue(const std::string &valueStr, bool errorDisplay, bool upperLimit) const{
	if (!valueStr.empty() && valueStr[0] == '-')
	{
		if (errorDisplay)
        	std::cerr << "Error: not a positive number" << std::endl;
        return false;
    }
	
	bool decimalPointSeen = false;
    
    for (size_t i = 0; i < valueStr.size(); ++i)
	{
        char c = valueStr[i];
        if (c == '.') {
            if (decimalPointSeen)
			{
				if (errorDisplay)
                	std::cerr << "Error: multiple decimal points in value" << std::endl;
                return false;
            }
            decimalPointSeen = true;
        } 
		else if (!isdigit(c))
		{
			if (errorDisplay)
            	std::cerr << "Error: value contains non-digit characters" << std::endl;
            return false;
        }
    }
    if (valueStr.empty() || valueStr == ".")
	{
		if (errorDisplay)
        	std::cerr << "Error: value is invalid" << std::endl;
        return false;
    }

    float value = std::atof(valueStr.c_str());
	if (value > 1000 && upperLimit)
	{
		if (errorDisplay)
       		std::cerr << "Error: too large a number" << std::endl;
        return false;
    }

    return true;
}

void	BitcoinExchange::processFile(const std::string &filename){
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return ;
	} //ajouter une exception
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)){
		std::istringstream iss(line);
		std::string date;
		std::string valueStr;
		float value;
		if (std::getline(iss, date, '|') && std::getline(iss, valueStr))
		{
			date.erase(date.find_last_not_of(" \n\r\t") + 1);
            date.erase(0, date.find_first_not_of(" \n\r\t"));
			valueStr.erase(valueStr.find_last_not_of(" \n\r\t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));
			if (!BitcoinExchange::validateDate(date, true) || !BitcoinExchange::validateValue(valueStr, true, true))
				continue;
			value = std::stof(valueStr);
	   		std::map<std::string, float>::iterator it = this->_rates.find(date);
            if (it == this->_rates.end())
			{
                it = this->_rates.lower_bound(date);
                if (it == this->_rates.begin())
				{
                    std::cerr << "Error: no previous date available for " << date << std::endl;
                    continue;
                }
                if (it == this->_rates.end())
                    it = --(this->_rates.end());
                else if (it->first != date)
                    --it;
            }
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
		}
		else
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
	}
	file.close();
}