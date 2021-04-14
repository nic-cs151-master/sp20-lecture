#ifndef JOINER_H
#define JOINER_H

template <typename T>
class Joiner
{
public:
    T combine(T x, T y);
};

template<typename T>
T Joiner<T>::combine(T x, T y)
{
    return x + y;
}

#endif