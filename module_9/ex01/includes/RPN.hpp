#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <vector>

class RPN
{
public:
    RPN();
    RPN(const RPN &src);
    RPN &operator=(const RPN &src);
    ~RPN();

    const std::stack<int> &getStack() const;

    void pushToken(const char &token);

    const int &getResult() const;

private:
    std::stack<int> _stack;
};

#endif
