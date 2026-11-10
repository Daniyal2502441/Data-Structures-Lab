
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

void display(Node* root) {
    if (root == NULL)
        return;

    cout << "Member: " << root->name << endl;

    cout << "Left Child: ";
    if (root->left != NULL)
        cout << root->left->name;
    else
        cout << "None";

    cout << endl;

    cout << "Right Child: ";
    if (root->right != NULL)
        cout << root->right->name;
    else
        cout << "None";

    cout << "\n----------------------" << endl;

    display(root->left);
    display(root->right);
}

int main() {

    Node* hod = new Node("HOD");

    hod->left = new Node("Coordinator Academics");
    hod->right = new Node("Coordinator Research");

    hod->left->left = new Node("Professor Ali");
    hod->left->right = new Node("Professor Ahmed");

    hod->right->left = new Node("Lecturer Sara");
    hod->right->right = new Node("Lecturer Ayesha");

    display(hod);

    return 0;
}

