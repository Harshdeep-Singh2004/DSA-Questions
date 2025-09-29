#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        height = 1;         
        left = right = nullptr;
    }
};

int getHeight(Node* node) {
    return (node ? node->height : 0);
}

Node* leftRotation(Node* root) {
    Node* child = root->right;
    Node* child_left = child->left;

    child->left = root;
    root->right = child_left;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node* rightRotation(Node* root) {
    Node* child = root->left;
    Node* child_right = child->right;

    child->right = root;
    root->left = child_right;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // no duplicates

    int l = getHeight(root->left);
    int r = getHeight(root->right); 
    int balance = l - r;

    // LL
    if (balance > 1 && key < root->left->data)
        return rightRotation(root);

    // LR
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // RR
    if (balance < -1 && key > root->right->data)
        return leftRotation(root);

    // RL
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    inorder(root);
    cout << "\n";

    return 0;
}
