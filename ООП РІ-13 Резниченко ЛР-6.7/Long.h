#pragma once

template<class T>
class Predicate {
public:
    virtual bool operator () (T x) = 0;
    virtual ~Predicate() = default;
};

template<class T>
class Positive : public Predicate<T> {
public:
    virtual bool operator () (T x) override;
};

template<class T>
class Even : public Predicate<T> {
public:
    virtual bool operator () (T x) override;
};

template<class T>
int unique_copy(T* begin, T* end, T* to);

template<class T>
int unique_copy_if(T* begin, T* end, T* to, Predicate<T>& p);