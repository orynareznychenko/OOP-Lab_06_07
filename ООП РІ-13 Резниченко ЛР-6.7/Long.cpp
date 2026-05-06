#include "Long.h"

template<class T>
bool Positive<T>::operator()(T x) {
    return x > 0;
}

template<class T>
bool Even<T>::operator()(T x) {
    return x % 2 == 0;
}

template<class T>
int unique_copy(T* begin, T* end, T* to) {
    if (begin == end) return 0;
    int n = 0;
    T* from = begin;
    *to = *from; to++; n++;
    T* prev = from; from++;
    for (; from < end; from++) {
        if (*from != *prev) {
            *to = *from; to++; n++;
        }
        prev = from;
    }
    return n;
}

template<class T>
int unique_copy_if(T* begin, T* end, T* to, Predicate<T>& p) {
    if (begin == end) return 0;
    int n = 0;
    T* from = begin;
    *to = *from; to++; n++;
    T* prev = from; from++;
    for (; from < end; from++) {
        if (*from != *prev) {
            *to = *from; to++; n++;
        }
        else {
            if (!p(*from)) {
                *to = *from; to++; n++;
            }
        }
        prev = from;
    }
    return n;
}

template class Positive<int>;
template class Even<int>;
template int unique_copy<int>(int* begin, int* end, int* to);
template int unique_copy_if<int>(int* begin, int* end, int* to, Predicate<int>& p);