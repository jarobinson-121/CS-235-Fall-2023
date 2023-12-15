#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template<class T>
class Vector {

private: 
    int length;
    int capacity;
    T* arr;

public:
    Vector() {
        capacity = 10;
        length = 0;
        arr = new T[capacity];
    }

    ~Vector() {
        clear();
        delete[] arr;
    }

    void push_back(T item) {
        if(length == capacity) {
            capacity++;
            T* newArr = new T[capacity];

            for(int i = 0; i < length; i++) {
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;

            arr[length++] = item;
        }
        else {
            arr[length++] = item;
        }
    }

    void insert(T item, int position) {
        if(position > length) {
            throw out_of_range("Index out of range");
        }
        if(length == capacity) {
            capacity++;
            T* newArr = new T[capacity];

            for(int i = 0; i < position; i++) {
                newArr[i] = arr[i];
            }

            newArr[position] = item;

            for(int i = position; i < length; i++) {
                newArr[i + 1] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            length++;
        }

        else {
            for(int i = length; i > position; i--) {
                arr[i] = arr[i - 1];
            }
            arr[position] = item;
            length++;
        }
    }

    void remove(int position) {
        if(position >= length) {
            throw out_of_range("Index out of range");
        }
        else {
            for(int i = position; i < length; i++) {
                arr[i] = arr[i + 1];
            }
            length--;
        }
    }

    T& operator[](int index) {
        if(index >= length) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }

    int size() const {
        return length;
    }

    void clear() {
        while(length > 0) {
            remove(0);
        }
    }
};
