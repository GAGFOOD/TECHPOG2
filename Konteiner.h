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

    void qsortByDestination() {
        if (size <= 1) return;
        _quick_sort_destination(0, size - 1);
    }

    void _quick_sort_destination(int left, int right) {
        if (left >= right) return;

        const std::string p = data[left].getDestination(); // опорный элемент - destination
        int i = left;
        int j = right;

        while (i < j) {
            while (data[j].getDestination() > p && i < j) j--;
            if (i != j) {
                std::swap(data[i], data[j]);
                i++;
            }
            while (data[i].getDestination() < p && i < j) i++;
            if (i != j) {
                std::swap(data[j], data[i]);
                j--;
            }
        }

        if (left < i - 1) _quick_sort_destination(left, i - 1);
        if (i + 1 < right) _quick_sort_destination(i + 1, right);
    }

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
