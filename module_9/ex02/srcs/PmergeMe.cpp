#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>
#include <climits>

PmergeMe::PmergeMe() {}

static bool isPositiveInteger(const std::string &str)
{
    if (str.empty())
        return false;

    int result = 0;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (!isdigit(str[i]))
            return false;

        int digit = str[i] - '0';
        if (result > (INT_MAX - digit) / 10)
            return false;
        result = result * 10 + digit;
    }

    return true;
}

static int ft_atoi(const std::string &str)
{
    int result = 0;

    for (size_t i = 0; i < str.size(); ++i)
        result = result * 10 + (str[i] - '0');

    return result;
}

PmergeMe::PmergeMe(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
        if (!isPositiveInteger(av[i]))
            throw std::runtime_error("invalid digit");

        int val = ft_atoi(av[i]);

        _vector.push_back(val);
        _deque.push_back(val);
    }
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    (void) src;
    return *this;
}

PmergeMe::~PmergeMe() {}

const std::deque<int> &PmergeMe::getDeque() const
{
    return _deque;
}

const std::vector<int> &PmergeMe::getVector() const
{
    return _vector;
}

static std::vector<size_t> generateJacobsthalVector(const size_t limit)
{
    std::vector<size_t> seq;
    size_t a = 0;
    size_t b = 1;

    while (b < limit)
    {
        seq.push_back(b);
        size_t temp = b;
        b = b + 2 * a;
        a = temp;
    }
    return seq;
}

static std::deque<size_t> generateJacobsthalDeque(const size_t limit)
{
    std::deque<size_t> seq;
    size_t a = 0;
    size_t b = 1;

    while (b < limit)
    {
        seq.push_back(b);
        size_t temp = b;
        b = b + 2 * a;
        a = temp;
    }
    return seq;
}

static void fordJohnsonSort(std::vector<int> &input)
{
    if (input.size() <= 1)
        return ;

    std::vector<int> main_chain;
    std::vector<int> pending;

    std::vector<int>::iterator it = input.begin();
    while (it != input.end() && it + 1 != input.end())
    {
        main_chain.push_back(std::max(*it, *it + 1));
        pending.push_back(std::min(*it, *it + 1));

        it += 2;
    }

    if (it != input.end())
        pending.push_back(*it);

    fordJohnsonSort(main_chain);

    const std::vector<size_t> jacob = generateJacobsthalVector(pending.size());
    std::vector<bool> used(pending.size(), false);

    for (size_t i = 0; i < jacob.size(); ++i)
    {
        if (i >= pending.size())
            break ;
        int value = pending[jacob[i]];
        used[jacob[i]] = true;
        std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), value);
        main_chain.insert(pos, value);
    }

    for (size_t i = 0; i < pending.size(); ++i)
    {
        if (used[i])
            continue ;
        int value = pending[i];
        std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), value);
        main_chain.insert(pos, value);
    }

    input.assign(main_chain.begin(), main_chain.end());
}

static void fordJohnsonSort(std::deque<int> &input)
{
    if (input.size() <= 1)
        return ;

    std::deque<int> main_chain;
    std::deque<int> pending;

    std::deque<int>::iterator it = input.begin();
    while (it != input.end() && it + 1 != input.end())
    {
        main_chain.push_back(std::max(*it, *it + 1));
        pending.push_back(std::min(*it, *it + 1));

        it += 2;
    }

    if (it != input.end())
        pending.push_back(*it);

    fordJohnsonSort(main_chain);

    const std::deque<size_t> jacob = generateJacobsthalDeque(pending.size());
    std::deque<bool> used(pending.size(), false);

    for (size_t i = 0; i < jacob.size(); ++i)
    {
        if (i >= pending.size())
            break ;
        int value = pending[jacob[i]];
        used[jacob[i]] = true;
        std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), value);
        main_chain.insert(pos, value);
    }

    for (size_t i = 0; i < pending.size(); ++i)
    {
        if (used[i])
            continue ;
        int value = pending[i];
        std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), value);
        main_chain.insert(pos, value);
    }

    input.assign(main_chain.begin(), main_chain.end());
}

double PmergeMe::sortVector()
{
    const clock_t start = clock();
    fordJohnsonSort(_vector);
    const clock_t end = clock();

    return static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

double PmergeMe::sortDeque()
{
    const clock_t start = clock();
    fordJohnsonSort(_deque);
    const clock_t end = clock();

    return static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

std::ostream &operator<<(std::ostream &OUT, const PmergeMe &pmergeMe)
{
    const std::deque<int> &deq = pmergeMe.getDeque();
    const std::vector<int> &vec = pmergeMe.getVector();

    // Print vector
    OUT << " - vector: ";
    if (vec.size() <= MAX_PRINT)
    {
        for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        {
            OUT << *it;
            std::vector<int>::const_iterator next = it;
            if (++next != vec.end())
                OUT << " ";
        }
    }
    else
    {
        std::vector<int>::const_iterator it = vec.begin();
        for (int i = 0; i < MAX_PRINT && it != vec.end(); ++i, ++it)
            OUT << *it << " ";
        OUT << "[...]";
    }

    OUT << std::endl;

    // Print deque
    OUT << " - deque : ";
    if (deq.size() <= MAX_PRINT)
    {
        for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
        {
            OUT << *it;
            std::deque<int>::const_iterator next = it;
            if (++next != deq.end())
                OUT << " ";
        }
    }
    else
    {
        std::deque<int>::const_iterator it = deq.begin();
        for (int i = 0; i < MAX_PRINT && it != deq.end(); ++i, ++it)
            OUT << *it << " ";
        OUT << "[...]";
    }

    return OUT;
}
