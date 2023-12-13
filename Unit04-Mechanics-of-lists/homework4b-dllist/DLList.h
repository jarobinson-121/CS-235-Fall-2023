#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template<class T>
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

    DLList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~DLList() {
        clear();
    }

    const Node* get_head() const {
        return head;
    }

    void push_front(T item) {
        Node* newNode = new Node(item);

        if(head == nullptr) {
            tail = newNode;
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        count++;
    }

    void push_back(T item) {
        Node* newNode = new Node(item);
        if(tail == nullptr) {
            tail = newNode;
            head = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        count++;
    }

    void insert(T item, int position) {
        if(position <= size()) {
            if(position == 0) {
            push_front(item);
            }
            else if(position == size()) {
                push_back(item);
            }
            else {
                Node* newNode = new Node(item);
                Node* temp = head;
                for(int i = 0; i < position; i++) {
                    temp = temp->next;
                }
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
                newNode->next = temp;
                count++;
            }

        }
        else {
            throw out_of_range("threw an out_of_range exception");
        }
    }

    void pop_front() {
        if(head != nullptr) {
            Node* front = head->next;
            if(front == nullptr) {
                tail = nullptr;
            }
            else {
                front->prev = nullptr;
            }
            delete head;
            head = front;
            count--;
        }
        else{
            throw length_error("threw a length_error exception");
        }
    }

    void pop_back() {
        if(head != nullptr) {
            Node* back = tail->prev;
            if(back == nullptr) {
                head = nullptr;
            }
            else {
                back->next = nullptr;
            }
            delete tail;
            tail = back;
            count--;
        }
        else {
            throw length_error("threw a length_error exception");
        }
    }

    void remove(int position) {
            if(position >= size()){
                throw out_of_range("threw an out of range error exception");
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
        if(head != nullptr) {
        return head->value;
        }
        else {
            throw length_error("threw a length_error exception");    
        }
    }

    const T& back() const {
        if(head != nullptr) {
            return tail->value;
        }
        else {
            throw length_error("threw a length_error exception");

        }
    }

    const T& at(int index) const {
        if(index < count) {
            int currentIndex = 0;
        Node* temp = head;
        while(currentIndex < index) {
            temp = temp->next;
            currentIndex++;
        }
        return temp->value;
        }
        else {
            throw out_of_range("threw an out_of_range exception");
        }
    }

    bool contains(const T& item) const {
        Node* temp = head;
        while(temp != nullptr) { 
            
            if(temp->value == item) {
                return true;
            }
            else {
                temp = temp->next;
            }
        }
        return false;
    }

    int size() const {
        return count;
    }

    void clear() {
        while(head != nullptr) {
            pop_front();
        }
    }

private:
    Node* head;
    Node* tail;
    int count;
};
