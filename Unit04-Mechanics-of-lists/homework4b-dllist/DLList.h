#pragma once

#include <iostream>
#include <string>

template<class T>
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

    DLList() {}

    ~DLList() {}

    const Node* get_head() const {
        // implement get_head here
    }

    void push_front(T item) {
        // implement push_front here
    }
    void push_back(T item) {
        // implement push_back here
    }
    void insert(T item, int position) {
        // implement insert here
    }

    void pop_front() {
        // implement pop_front here
    }
    void pop_back() {
        // implement pop_back here
    }
    void remove(int position) {

        if(position >= size()){
            return;
        }

        // Case 1: position = 0
        else if(position == 0) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }


        // Case 2: position = size() -1
        else if(position == (size() -1)) {
            Node* itr = head;
            for(int i =0; i < (position -1); i++) {
                itr = itr->next;
            }
            Node* tmp = tail;
            itr->next = nullptr;
            delete tmp;
            tail = itr;
        }

        // Case 3: removing from the middle
        else {
            Node* itr = head;
            for(int i =0; i < (position -1); i++) {
                itr = itr->next;
            }
            Node* tmp = itr->next;
            itr->next = itr->next->next;
            delete tmp;
        }
        count--;
    }

    const T& front() const {
        // implement front here
    }
    const T& back() const {
        // implement back here
    }
    const T& at(int index) const {
        // implement at here
    }

    bool contains(const T& item) const {
        // implement contains here
    }

    int size() const {
        // implement size here
    }

    void clear() {
        // implement clear here
    }
};
