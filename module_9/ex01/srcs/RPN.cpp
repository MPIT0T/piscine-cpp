#include "RPN.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

RPN::RPN() {}

RPN::RPN(const RPN &src)
{
    *this = src;
}

RPN &RPN::operator=(const RPN &src)
{
    (void) src; // TODO do this
    return *this;
}

RPN::~RPN() {}

const std::stack<int> &RPN::getStack() const
{
    return _stack;
}

static int safeDivide(const int &x, const int &y)
{
    if (y == 0)
        throw std::runtime_error("by zero Division");
    return x / y;
}

void RPN::pushToken(const char &token)
{
    static std::string numbers = "0123456789";
    static std::string operators = "+-/*";

    if (numbers.find(token) != std::string::npos)
        _stack.push(token - 48);
    else if (operators.find(token) != std::string::npos)
    {
        if (_stack.size() < 2)
            throw std::runtime_error("Operator received when not enough values stored");

        const int y = _stack.top();
        _stack.pop();
        const int x = _stack.top();
        _stack.pop();

        switch (token)
        {
            case '+':
                _stack.push(x + y);
                break;
            case '-':
                _stack.push(x - y);
                break;
            case '/':
                _stack.push(safeDivide(x, y));
                break;
            case '*':
                _stack.push(x * y);
                break;
            default:
                throw std::runtime_error("unknown token");
        }
    }
    else
        throw std::runtime_error("Unknown token");
}

const int & RPN::getResult() const
{
    if (_stack.size() != 1)
        throw std::runtime_error("multiple tokens left");
    return _stack.top();
}
