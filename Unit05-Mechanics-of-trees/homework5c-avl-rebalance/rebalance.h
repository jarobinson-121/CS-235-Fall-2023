#pragma once
#include <algorithm>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Hint: you might find it helpful to write an update_height function that takes
// a Node* and updates its height field based on the heights of its children

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
    int diff = getheight(root->left) - getheight(root->right);
    if(abs(diff) <= 1) {
        return;
    }
    // left imbalance
    else if(diff > 1) {
        // Left-left imbalance
        if(diff ) {

        }

        // left-right imbalance
        
    }
    // right imbalance
    else {
        // right-right imbalance
        if(diff < -1) {

        }
        // right-left imbalance



    }
}

void updateheight(Node*& n) {
    int hleft = getheight(n->left);
    int hright = getheight(n->right);
    n->height = max(hleft, hright) + 1;
}

int getheight(Node* n) {
    if(n == nullptr) {
        return -1;
    }
    else {
        return n->height;
    }
}

bool insertHelper(Node*& n, int val) {
    if(n == nullptr) {
        n = new Node(val);
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

bool removeHelper(Node*& n, int val) {
    if(n->right == nullptr && n->left == nullptr) {

    }
    else if(n->right == nullptr && n->left != nullptr) {

    }
    else if(n->right != nullptr && n->left == nullptr) {

    }
    else {
        
    }
}