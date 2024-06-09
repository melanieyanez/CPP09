/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:17:33 by melanieyane       #+#    #+#             */
/*   Updated: 2024/06/09 18:54:13 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN(){}

RPN::RPN(const RPN &src) : _stack(src.getStack()){}

RPN::~RPN(){}

RPN &RPN::operator=(const RPN &rhs){
	if (this != &rhs)
		this->_stack = rhs.getStack();
	return *this;
}

std::stack<int> RPN::getStack() const{
	return this->_stack;
}

void RPN::evaluate(const std::string &expression){
	
}


