
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(string name) {
        folder = name;
        left = NULL;
        right = NULL;
    }
};

// In-order: Left, Root, Right
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->folder << " ";
    inorder(root->right);
}

// Pre-order: Root, Left, Right
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->folder << " ";
    preorder(root->left);
    preorder(root->right);
}

// Post-order: Left, Right, Root
void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->folder << " ";
}

int main() {

    Node* root = new Node("Computer");

    root->left = new Node("Documents");
    root->right = new Node("Pictures");

    root->left->left = new Node("Assignments");
    root->left->right = new Node("Projects");

    root->right->left = new Node("Photos");
    root->right->right = new Node("Videos");

    cout << "In-order Traversal: ";
    inorder(root);

    cout << "\nPre-order Traversal: ";
    preorder(root);

    cout << "\nPost-order Traversal: ";
    postorder(root);

    return 0;
}

