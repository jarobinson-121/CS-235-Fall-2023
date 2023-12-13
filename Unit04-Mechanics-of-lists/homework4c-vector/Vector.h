#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template<class T>
class Vector {

private: 
    int size;
    int capacity;
    T* arr;

public:
    Vector() {
        capacity = 10;
        size = 0;
        arr = new T[capacity];
    }

    ~Vector() {
        clear();
    }

    void push_back(T item) {
        // implement push_back here
        size++;
    }

    void insert(T item, int position) {
        if(position > size) {
            throw out_of_range("Index out of range") 
        }
        if(size == capacity) {
            capacity *= 2;
            T* newArr = new T[capacity];

            for(int i = 0; i < position; ) {
                newArr[i] = arr[i];
            }

            newArr[position] = item;

            for(int i = ; i < position; i++) {
                newArr[i + 1] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            size++;
        }

        else {
            for(int i = size; i > position; i--) {
                arr[i] = arr[i - 1];
            }
            arr[position] = item;
            size++;
        }
    }

    void remove(int position) {
        if(position > size) {
            throw out_of_range("Index out of range");
        }
        else {
            for(int i = position; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        }
    }

    T& operator[](int index) {
        if(index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    int size() const {
        return size;
    }

    void clear() {
        delete[] arr;
    }
};
