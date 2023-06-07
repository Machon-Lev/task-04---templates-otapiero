#pragma once

#include <iostream>
#include <list>
#include <exception>


template<typename T>
concept SupportsLessThan = requires (T x) { x < x; };

template<typename T>
    requires SupportsLessThan<T>
struct MyComparator {
    bool operator()(const T& a, const T& b) const
    {
        return a < b;
    }
};

// any templates?
template <typename T>
    requires SupportsLessThan<T>
class PriorityQueue {

public:


    // You need to complete the implement : 
    void push(const T& t);
    T poll();

private:
    std::list<T> queue;
    // add relevant data members
};

template<typename T>
    requires SupportsLessThan<T>
inline void PriorityQueue<T>::push(const T& t)
{
    typename std::list<T>::iterator it;
    for (it = queue.begin(); it != queue.end(); ++it) {
        if (MyComparator<T>()(t, *it))
        {
            break;
        }
    }
    queue.insert(it, t);
}

template<typename T>
    requires SupportsLessThan<T>
inline T PriorityQueue<T>::poll()
{
    // get the first element
    if (queue.empty())
    {
        throw std::exception("PriorityQueue empty !");
    }
    T front = queue.front();
    queue.pop_front();
    return front;
}

