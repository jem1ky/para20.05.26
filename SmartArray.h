#ifndef SMART_ARRAY_H
#define SMART_ARRAY_H

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <cstddef>

template <typename T>
class SmartArray {
private:
    T* data;            // Указатель на динамический массив
    size_t capacity;    // Физическая емкость массива
    size_t current_size;// Текущее количество элементов

    // Вспомогательный метод для изменения размера памяти
    void resize(size_t newCapacity) {
        // 1. Создаем новый массив нужного размера
        T* newData = new T[newCapacity];

        // 2. Копируем/перемещаем элементы, но СТРОГО не больше, 
        // чем физически может вместить новый массив и сколько есть в старом
        size_t elementsToCopy = std::min(current_size, newCapacity);

        for (size_t i = 0; i < elementsToCopy; ++i) {
            newData[i] = std::move(data[i]); // Используем std::move для скорости
        }

        // 3. Обновляем текущий размер, если новый массив оказался меньше старого
        current_size = elementsToCopy;

        // 4. Освобождаем старую память и обновляем указатели
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    // Класс Итератора (вложенный)
    class Iterator {
    private:
        T* ptr;
    public:
        Iterator(T* p) : ptr(p) {}

        T& operator*() { return *ptr; }

        Iterator& operator++() {
            ptr++;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    // Конструкторы и деструктор
    SmartArray() : data(nullptr), capacity(0), current_size(0) {}

    SmartArray(size_t initialCapacity) : capacity(initialCapacity), current_size(0) {
        data = new T[capacity];
    }

    SmartArray(const SmartArray& other) : capacity(other.capacity), current_size(other.current_size) {
        if (capacity > 0) {
            data = new T[capacity];
            for (size_t i = 0; i < current_size; ++i) {
                data[i] = other.data[i];
            }
        }
        else {
            data = nullptr;
        }
    }

    ~SmartArray() {
        delete[] data;
    }

    // Операторы
    T& operator[](size_t index) {
        if (index >= current_size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= current_size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    SmartArray& operator=(const SmartArray& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            current_size = other.current_size;
            if (capacity > 0) {
                data = new T[capacity];
                for (size_t i = 0; i < current_size; ++i) {
                    data[i] = other.data[i];
                }
            }
            else {
                data = nullptr;
            }
        }
        return *this;
    }

    // Основные методы
    void push_back(const T& value) {
        if (capacity == 0) {
            resize(4);
        }
        else if (current_size >= capacity) {
            resize(capacity * 2);
        }
        data[current_size++] = value;
    }

    void pop_back() {
        if (current_size > 0) {
            current_size--;
        }
    }

    T& back() {
        if (current_size == 0) {
            throw std::underflow_error("Array is empty");
        }
        return data[current_size - 1];
    }

    size_t size() const {
        return current_size;
    }

    bool empty() const {
        return current_size == 0;
    }

    void clear() {
        current_size = 0;
    }

    void insert(size_t index, const T& value) {
        if (index > current_size) {
            throw std::out_of_range("Index out of bounds");
        }
        if (current_size >= capacity) {
            resize(capacity == 0 ? 4 : capacity * 2);
        }
        for (size_t i = current_size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        current_size++;
    }

    void erase(size_t index) {
        if (index >= current_size) {
            throw std::out_of_range("Index out of bounds");
        }
        for (size_t i = index; i < current_size - 1; ++i) {
            data[i] = data[i + 1];
        }
        current_size--;
    }

    int find(const T& value) const {
        for (size_t i = 0; i < current_size; ++i) {
            if (data[i] == value) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    // Методы для работы итератора
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + current_size); }
};

#endif // SMART_ARRAY_H
