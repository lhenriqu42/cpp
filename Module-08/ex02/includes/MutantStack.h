#pragma once

#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
    typedef std::stack<T> stack;
    typedef typename stack::container_type container;
    typedef typename container::iterator iterator;
    typedef typename container::const_iterator const_iterator;

    MutantStack() {};
    explicit MutantStack(const container& c) : stack(c) {}

    iterator begin() { return stack::c.begin(); }
    const_iterator begin() const { return stack::c.begin(); }

    iterator end() { return stack::c.end(); }
    const_iterator end() const { return stack::c.end(); }
};
