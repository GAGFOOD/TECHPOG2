#pragma once
#include "Konteiner.h"
#include <new> // placement new

template<typename T>
void Konteiner<T>::reserve(int new_cap)
{
    if (new_cap <= capacity)
        return;

    T* new_data = static_cast<T*>(::operator new(sizeof(T) * new_cap));

    // Переносим старые элементы
    for (int i = 0; i < size; i++)
        new (new_data + i) T(std::move(data[i]));

    // Вызываем деструкторы старых элементов
    destroy_all();

    ::operator delete(data);
    data = new_data;
    capacity = new_cap;
}


template<typename T>
void Konteiner<T>::destroy_all()
{
    for (int i = 0; i < size; i++)
        data[i].~T();
}

template<typename T>
Konteiner<T>::Konteiner() : data(nullptr), size(0), capacity(0) {}

template<typename T>
Konteiner<T>::Konteiner(const Konteiner& other)
    : size(other.size), capacity(other.capacity)
{
    data = static_cast<T*>(::operator new(sizeof(T) * capacity));
    for (int i = 0; i < size; i++)
        new (data + i) T(other.data[i]);
}

template<typename T>
Konteiner<T>::~Konteiner()
{
    destroy_all();
    ::operator delete(data);
}

template<typename T>
Konteiner<T>& Konteiner<T>::operator=(const Konteiner& other)
{
    if (this == &other)
        return *this;

    clear();
    reserve(other.capacity);
    size = other.size;

    for (int i = 0; i < size; i++)
        new (data + i) T(other.data[i]);

    return *this;
}

template<typename T>
T& Konteiner<T>::operator[](int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template<typename T>
const T& Konteiner<T>::operator[](int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template<typename T>
void Konteiner<T>::qsortByDestination() {
    if (size <= 1) return;
    _quick_sort_destination(0, size - 1);
}

template<typename T>
void Konteiner<T>::_quick_sort_destination(int left, int right) {
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

template<typename T>
void Konteiner<T>::push_back(const T& value)
{
    std::cout<<"1";
    if (size == capacity)
        reserve(capacity == 0 ? 1 : capacity * 2);
    new (data + size++) T(value);
}

template<typename T>
void Konteiner<T>::push_back(T&& value)
{
    if (size == capacity)
        reserve(capacity == 0 ? 1 : capacity * 2);
    new (data + size++) T(std::move(value));
    qsortByDestination();
}

template<typename T>
template<typename... Args>
void Konteiner<T>::emplace_back(Args&&... args)
{
    if (size == capacity)
        reserve(capacity == 0 ? 1 : capacity * 2);
    new (data + size++) T(std::forward<Args>(args)...);
}

template<typename T>
void Konteiner<T>::pop_back()
{
    if (size == 0)
        throw std::out_of_range("Empty container");

    data[size - 1].~T();
    size--;
}

template<typename T>
int Konteiner<T>::getsize() const { return size; }

template<typename T>
int Konteiner<T>::getcapacity() const { return capacity; }

template<typename T>
bool Konteiner<T>::empty() const { return size == 0; }

template<typename T>
T& Konteiner<T>::front()
{
    if (size == 0)
        throw std::out_of_range("Empty");
    return data[0];
}
template<typename T>
void Konteiner<T>::erase(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Erase: index out of range");

    data[index].~T();

    for (int i = index; i < size - 1; i++)
    {
        new (data + i) T(std::move(data[i + 1]));
        data[i + 1].~T();
    }

    size--;
}

template<typename T>
T& Konteiner<T>::back()
{
    if (size == 0)
        throw std::out_of_range("Empty");
    return data[size - 1];
}

template<typename T>
T* Konteiner<T>::begin() { return data; }

template<typename T>
T* Konteiner<T>::end() { return data + size; }

template<typename T>
void Konteiner<T>::clear()
{
    destroy_all();
    ::operator delete(data);
    data = nullptr;
    size = 0;
    capacity = 0;
}
