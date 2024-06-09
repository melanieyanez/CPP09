/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:17:24 by melanieyane       #+#    #+#             */
/*   Updated: 2024/06/09 18:52:42 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
	public:
		RPN();
		RPN(const RPN &src);
		~RPN();
		RPN &operator=(const RPN &rhs);

		std::stack<int> getStack() const;
		
		void evaluate(const std::string &expression);

	private:
		std::stack<int> _stack;
};

#endif