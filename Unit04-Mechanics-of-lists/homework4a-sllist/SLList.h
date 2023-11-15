#pragma once

using namespace std;

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
        clear();
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
        remove(size() -1);
        // Node* temp = tail;
        // Node* itr = head;
        // for(int i = 0; i < size(); i++) {
        //     itr = itr->next;
        // }

        // itr->next = nullptr;

        // delete temp;

        // tail = itr;

        // count--;
    }

    const T& front() const {
        return head->value;
    }

    int size() const {
        return count;
    }

    void clear() {
        Node* itr = head;
        while(itr != nullptr) {
            Node* tmp = itr;
            itr = itr->next;
            delete tmp;
            count--;
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

    void remove(int position) {
        if(position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else if(position == size() -1) {
            Node* temp = tail;
            Node* itr = head;
            for(int i = 0; i < position -1; i++){
                itr = itr->next;
            }
            itr->next = nullptr;
            delete temp; 
            tail = itr;
        }
        count--;
    }

private:
    Node* head;
    Node* tail;
    int count;
};
