#pragma once

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    BST() {
        root = nullptr;
    }

    ~BST() {
        clear();
    }

    const Node* getRootNode() const {
        return root;
    }

    bool insert(T item) {
        return insertHelper(root, item);
    }

    bool remove(T item) {
        return removeHelper(root, item);
    }

    bool contains(T item) const {
        return findHelper(root, item);
    }

    void clear() {
        if(root == nullptr) {
            return;
        }
        else {
            clearHelper(root);
        }
        root = nullptr;
        count = 0;
    }

    int size() const {
        if(root == nullptr) {
            return 0;
        }
        else {
            return count;
        }
    }

    bool insertHelper(Node*& n, int val) {
        if(n == nullptr) {
            n = new Node(val);
            count++;
            return true;
        }
        else if(val == n->value) {
            return false;
        }
        else if(val > n->value) {
            return insertHelper(n->right, val);
        }
        else {
            return insertHelper(n->left, val);
        }
    }

    bool findHelper(Node* n, int v) const {
        if(n == nullptr) {
            return false;
        }
        else if(n->value == v) {
            return true;
        }
        else if(n->value > v) {
            return findHelper(n->left, v);
        }
        else {
            return findHelper(n->right, v);
        }
    }

    bool removeHelper(Node*& n, T val) {
        if(n == nullptr) {
            return false;
        }
        
        if(n->value == val) {
            //no children
            if(n->right == nullptr && n->left == nullptr) {
                n = nullptr;
                delete n;
                count--;
                return true;
            }
            //left child
            else if(n->right == nullptr && n->left != nullptr) {
                Node* tmp = n->left;
                delete n;
                n = tmp;
                count--;
                return true;
            }
            //right child
            else if(n->right != nullptr && n->left == nullptr) {
                Node* tmp = n->right;
                delete n;
                n = tmp;
                count--;
                return true;
            }
            //both
            else {
                Node* iop = n->left;
                while(iop->right != nullptr) {
                    iop = iop->right;
                }
                n->value = iop->value;
                bool isRemoved = removeHelper(n->left, iop->value);

                count--;
                return isRemoved;
            }
        }
        else if(n->value > val) {
            return removeHelper(n->left, val);
        }
        else {
            return removeHelper(n->right, val);
        
        }    
    }


void clearHelper(Node*& n) {
    if(n != nullptr){
        clearHelper(n->right);
        clearHelper(n->left);
        delete n;
    }
}

private: 
    Node* root;
    int count;
};
