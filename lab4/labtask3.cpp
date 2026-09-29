#include <iostream>
using namespace std;

class Node
{
public:
    string productID;
    Node* next;
};

class ShoppingCart
{
private:
    Node* head;

public:
    ShoppingCart()
    {
        head = NULL;
    }

    // Add product at the end
    void addProduct(string id)
    {
        Node* newNode = new Node();

        newNode->productID = id;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Display all products
    void displayCart()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->productID;

            if (temp->next != NULL)
            {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }

    // Remove product using Product ID
    void removeProduct(string id)
    {
        if (head == NULL)
        {
            cout << "Cart is empty." << endl;
            return;
        }

        // If first product needs to be removed
        if (head->productID == id)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            if (temp->next->productID == id)
            {
                Node* deleteNode = temp->next;

                temp->next = temp->next->next;

                delete deleteNode;

                return;
            }

            temp = temp->next;
        }

        cout << "Product not found." << endl;
    }
};

int main()
{
    ShoppingCart cart;

    // Add products
    cart.addProduct("P101");
    cart.addProduct("P205");
    cart.addProduct("P310");
    cart.addProduct("P415");

    cout << "Shopping Cart:" << endl;
    cart.displayCart();

    cout << "Remove Product: P310" << endl;

    cart.removeProduct("P310");

    cout << "Updated Cart:" << endl;
    cart.displayCart();

    return 0;
}
