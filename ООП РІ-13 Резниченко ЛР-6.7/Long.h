#pragma once

template <class T>
class Predicate {
public:
    virtual bool operator () (T x) = 0;
    virtual ~Predicate() {}
};

template <class T>
class Even : public Predicate<T> {
public:
    virtual bool operator () (T x) override {
        return x % 2 == 0;
    }
};

template <class T>
class Negative : public Predicate<T> {
public:
    virtual bool operator () (T x) override {
        return x < 0;
    }
};

template <class T>
int unique_copy_custom(T* begin, T* end, T* to) {
    if (begin == end) return 0;

    int n = 0;
    *to = *begin;
    to++; n++;

    for (T* from = begin + 1; from < end; from++) {
        if (*from != *(from - 1)) {
            *to = *from;
            to++; n++;
        }
    }
    return n;
}

template <class T>
int unique_copy_if_custom(T* begin, T* end, T* to, Predicate<T>& p) {
    if (begin == end) return 0;

    int n = 0;
    *to = *begin;
    to++; n++;

    for (T* from = begin + 1; from < end; from++) {
        bool is_duplicate = (*from == *(from - 1));

        if (is_duplicate && p(*from)) {
            continue;
        }

        *to = *from;
        to++; n++;
    }
    return n;
}