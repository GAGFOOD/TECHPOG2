#pragma once
#include <stdexcept>
#include <utility>
#include <memory>
#include <type_traits>


template<typename T>
class Konteiner {
private:
    T* data;
    int size;
    int capacity;

    void reserve(int new_cap);
    void destroy_all();

public:
    Konteiner();
    Konteiner(const Konteiner& other);
    ~Konteiner();

    Konteiner& operator=(const Konteiner& other);

    T& operator[](int index);

    const T& operator[](int index) const;

    void qsortByDestination();

    void _quick_sort_destination(int left, int right);

    void push_back(const T& value);
    void push_back(T&& value);

    template<typename... Args>
    void emplace_back(Args&&... args);

    void pop_back();
    void erase(int index);
    int getsize() const;
    int getcapacity() const;
    bool empty() const;

    T& front();
    T& back();

    T* begin();
    T* end();

    void clear();
};

#include "Konteiner.hpp"
