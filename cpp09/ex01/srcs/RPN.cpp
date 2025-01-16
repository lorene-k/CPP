/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:35:23 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/16 16:17:29 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/************************************************** Constructors & destructor */
RPN::RPN() {}

RPN::RPN(std::string const &) {}

RPN::RPN(RPN const &src) : _stack(src._stack)
{
    *this = src;
}

RPN &RPN::operator=(RPN const &src)
{
    if (this != &src)
        this->_stack = src._stack;
    return (*this);
}

RPN::~RPN() {}

/*********************************************************** Helper functions */
static bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return (true);
    return (false);
}

/*********************************************************** Member functions */
void RPN::calculate(std::string const &input)
{
    std::istringstream ss(input);
    std::string token;

    ss >> std::ws;
    if (input.empty() || input.size() < 3 || ss.peek() == EOF)
        throw std::runtime_error("Error");
    while (ss >> token)
    {
        if (isdigit(token[0]) && token.size() == 1)
            this->_stack.push(static_cast<float>(token[0]) - '0');
        else if (isOperator(token[0]) && token.size() == 1)
        {
            if (this->_stack.size() < 2)
                throw std::runtime_error("Error");
            doOperation(token[0]);
        }
        else
            throw std::runtime_error("Error");
        ss >> std::ws;
        if (ss.peek() == EOF)
            printResult();
    }
}

void RPN::doOperation(char const &c)
{
    float a = this->_stack.top();
    this->_stack.pop();
    float b = this->_stack.top();
    this->_stack.pop();

    switch (c)
    {
        case '+':
            this->_stack.push(b + a);
            break;
        case '-':
            this->_stack.push(b - a);
            break;
        case '*':
            this->_stack.push(b * a);
            break;
        case '/':
            if (a == 0)
                throw std::runtime_error("Error");
            this->_stack.push(b / a);
            break;
    }
}

void RPN::printResult()
{
    if (this->_stack.size() != 1)
        throw std::runtime_error("Error");
    std::cout << this->_stack.top() << std::endl;
}
