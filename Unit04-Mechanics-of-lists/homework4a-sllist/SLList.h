#pragma once

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    SLList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~SLList() {
        
    }

    const Node* get_head() const {
        return head;
    }

    void push_back(T item) {
        Node* newNode = new Node(item);

        if(head == nullptr) {
            tail = newNode;
            head = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        count++;
    }

    void pop_back() {
        // implement pop_back here
    }

    const T& front() const {
        // implement front here
    }

    int size() const {
        return count;
    }

    void clear() {
        while(itr != nullptr) {
            Node* tmp = itr;
            itr = itr->next;
            delete tmp;
        }
    }

    void print() {
        cout << "Linked List is: ";
        Node* itr = head;
        while(itr != nullptr) {
            cout << itr->value << ", ";
            itr = itr->next;
        }

        cout << endl;
    }

private:
    Node* head;
    Node* tail;
    int count;
};
