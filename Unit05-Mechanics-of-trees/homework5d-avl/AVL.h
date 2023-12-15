#include <algorithm>

#pragma once

using namespace std;

template<class T>
class AVL {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        int height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}
    };

    AVL() {
        root = nullptr;
        count = 0;
    }

    ~AVL() {
        clear();
    }

    const Node* getRootNode() const {
        return root;
    }

    bool insert(T item) {
        return insertHelper(root, item);
    }

    bool remove(T item) {
        bool ret = removeHelper(root, item);
        if(ret == true) {
            count--;
        }
        return ret;
    }

    bool contains(T item) const {
        return findHelper(root, item);
    }

    void clear() {
        clearHelper(root);
        count = 0;
    }

    int size() const {
        return count;
    }

    int getheight(Node* n) {
    if(n == nullptr) {
        return 0;
    }
    else {
        return n->height;
    }
}

int difference(Node* n) {
    int left = getheight(n->left);
    int right = getheight(n->right);

    return left - right;
}

void updateheight(Node*& n) {
    int hleft = getheight(n->left);
    int hright = getheight(n->right);
    n->height = max(hleft, hright) + 1;
}


// Promote left == rotate right
void promote_left(Node*& root) {
    Node* temp = root;
    root = root->left;
    temp->left = root->right;
    root->right = temp;
    updateheight(temp);
    updateheight(root);
}

// Promote Right == rotate left
void promote_right(Node*& root) {
    Node* temp = root;
    root = root->right;
    temp->right = root->left;
    root->left = temp;
    updateheight(temp);
    updateheight(root);
}

    void rebalance(Node*& root) {
    int diff = difference(root);
    if(abs(diff) <= 1) {
        return;
    }
    // left imbalance
    else if(diff > 1) {
        // Left-left imbalance
        if(difference(root->left) >= 0) {
            promote_left(root);
        }

        // left-right imbalance
        else {
            promote_right(root->left);
            promote_left(root);
        }
        
    }
    // right imbalance
    else {
        if(difference(root->right) <= 0) {
            promote_right(root);
        }

        // left-right imbalance
        else {
            promote_left(root->right);
            promote_right(root);
        }
        
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
            bool ret = insertHelper(n->right, val);
            updateheight(n);
            rebalance(n);
            return ret;
        }
        else {
            bool ret = insertHelper(n->left, val);
            updateheight(n);
            rebalance(n);
            return ret;
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
                // count--;
                return true;
            }
            //left child
            else if(n->right == nullptr && n->left != nullptr) {
                Node* tmp = n->left;
                delete n;
                n = tmp;
                updateheight(n);
                rebalance(n);
                count--;
                return true;
            }
            //right child
            else if(n->right != nullptr && n->left == nullptr) {
                Node* tmp = n->right;
                delete n;
                n = tmp;
                updateheight(n);
                rebalance(n);
                // count--;
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
                updateheight(n);
                rebalance(n);
                // count--;
                return isRemoved;
            }
        }
        else if(n->value > val) {
            bool ret = removeHelper(n->left, val);
            updateheight(n);
            rebalance(n);
            return ret;
        }
        else {
            bool ret = removeHelper(n->right, val);
            updateheight(n);
            rebalance(n);
            return ret;
        }    
    }

    void clearHelper(Node*& n) {
        if(n != nullptr){
            clearHelper(n->right);
            clearHelper(n->left);
            delete n;
            n = nullptr;
        }
    }

private: 
    Node* root;
    int count;
};


