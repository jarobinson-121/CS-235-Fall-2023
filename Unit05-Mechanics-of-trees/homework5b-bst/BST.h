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
        removeHelper(root, root->value);
    }

    int size(Node* root) const {
        if(root == nullptr) {
            return 0;
        }
        else {
            return 1 + size(root->left) + size(root->right);
        }
    }

    bool insertHelper(Node*& n, int val) {
        if(n == nullptr) {
            n = new Node(val);
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

    bool findHelper(Node* n, int v) {
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
        if(n->value == val) {
            Node* temp = parentHelper(n, val);
            if(n->right == nullptr && n->left == nullptr) {
                if(temp->right == val) {
                    temp->right = nullptr;
                    delete n;
                    return true;
                }
                if(temp->left == val) {
                    temp->left = nullptr;
                    delete n;
                    return true;
                }
            }
            else if(n->right == nullptr && n->left != nullptr) {
                if(temp->right->value == val) {
                    temp->right = n->left;
                    delete n;
                    return true;
                }
                if(temp->left->value == val) {
                    temp->left = n->left;
                    delete n;
                    return true;
                }

            }
            else if(n->right != nullptr && n->left == nullptr) {
                if(temp->right->value == val) {
                    temp->right = n->right;
                    delete n;
                }
                if(temp->left->value == val) {
                    temp->left = n->right;
                    delete n;
                    return true;
                }
            }
            else {
                Node* swap = n->left;
                while (swap->right) {
                    swap = swap->right;
                }
                if(temp->right->value == val) {
                    temp->right = swap;
                    swap->right = n->right;
                    delete n;
                    return true;
                }
                if(temp->left->value == val) {
                    temp->left = swap;
                    swap->right = n->right;
                    delete n;
                    return true;
                }                
            }
        }
        else if(n->value > val) {
            return removeHelper(n->left, val);
        }
        else {
            return removeHelper(n->right, val);
        }    

    }

Node* parentHelper(Node*& n, int val) {
        if(n->left->value == val) {
            return n;
        }
        else if(n->right->value == val) {
            return n;
        }
        else if(n->left->value > val) {
            return parentHelper(n->left, val);
        }
        else {
            return parentHelper(n->right, val);
        }
}
private: 
    Node* root;
};
