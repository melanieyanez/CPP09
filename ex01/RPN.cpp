/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:17:33 by melanieyane       #+#    #+#             */
/*   Updated: 2024/06/13 10:33:16 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &src) : _stack(src.getStack()){}

RPN::~RPN(){}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
		this->_stack = rhs.getStack();
	return *this;
}

std::stack<int> RPN::getStack() const
{
	return this->_stack;
}

bool RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::applyOperation(int a, int b, char op)
{	
	long long result;

	switch (op)
	{
		case '+':
			result = static_cast<long long>(a) + static_cast<long long>(b);
			break;
		case '-':
			result = static_cast<long long>(a) - static_cast<long long>(b);
			break;
		case '*':
			result = static_cast<long long>(a) * static_cast<long long>(b);
			break;
		case '/':
			if (b == 0)
				throw std::runtime_error("Division by zero");
			result = static_cast<long long>(a) / static_cast<long long>(b);
			break;
	}
		
	if (result < INT_MIN || result > INT_MAX)
		throw std::runtime_error("Result out of range for int");
		
	return static_cast<int>(result);
}

int RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && isOperator(token[0]))
		{
			if (this->_stack.size() < 2)
				throw std::runtime_error("Not enough operands");
			int b = this->_stack.top();
			this->_stack.pop();
			int a = this->_stack.top();
			this->_stack.pop();
			int result = applyOperation(a, b, token[0]);
			this->_stack.push(result);
		}
		else
		{
			try
			{
				int num = std::stoi(token);
				if (num < -9 || num > 9)
					throw std::runtime_error("Token out of range: " + token);
				this->_stack.push(num);
			}
			catch (const std::invalid_argument &)
			{
				throw std::runtime_error("Invalid token: " + token);
			}
		}
	}
	if (this->_stack.size() != 1)
		throw std::runtime_error("Invalid expression");
	return this->_stack.top(); 
}
