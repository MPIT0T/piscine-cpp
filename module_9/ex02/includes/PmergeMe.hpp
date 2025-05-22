#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <deque>
#include <vector>
#include <string>

#define MAX_PRINT 10

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(int ac, char **av);
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &src);
    ~PmergeMe();

    const std::vector<int> &getVector() const;
    const std::deque<int> &getDeque() const;

    double sortDeque();
    double sortVector();

private:
    std::vector<int>    _vector;
    std::deque<int>     _deque;
    std::vector<int>    _unsortedVector;
    std::deque<int>     _unsortedDeque;
};

std::ostream &operator<<(std::ostream &OUT, const PmergeMe &pmergeMe);

#endif
