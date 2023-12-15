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





// bool insertHelper(Node*& n, int val) {
//     if(n == nullptr) {
//         n = new Node(val);
//     }
//     else if(val == n->value) {
//         return false;
//     }
//     else if(val > n->value) {
//         bool ret = insertHelper(n->right, val);
//         updateheight(n);
//         rebalance(n);
//         return ret;
//     }
//     else {
//         bool ret = insertHelper(n->left, val);
//         updateheight(n);
//         rebalance(n);
//         return ret;
//     }
// }

// bool removeHelper(Node*& n, int val) {
//     if(n->right == nullptr && n->left == nullptr) {

//     }
//     else if(n->right == nullptr && n->left != nullptr) {

//     }
//     else if(n->right != nullptr && n->left == nullptr) {

//     }
//     else {
        
//     }
// }