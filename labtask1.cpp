
#include <iostream>
using namespace std;

class Node
{
public:
    int rollNumber;
    Node* next;
};

class StudentList
{
private:
    Node* head;

public:
    StudentList()
    {
        head = NULL;
    }

    // Add student at the end
    void addStudent(int roll)
    {
        Node* newNode = new Node();

        newNode->rollNumber = roll;
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

    // Display all students
    void displayStudents()
    {
        Node* temp = head;

        cout << "Registered Students: " << endl;

        while (temp != NULL)
        {
            cout << temp->rollNumber;

            if (temp->next != NULL)
            {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }

    // Search student by roll number
    void searchStudent(int roll)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->rollNumber == roll)
            {
                cout << "Student Found" << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Student Not Found" << endl;
    }
};

int main()
{
    StudentList students;
    int n, roll, searchRoll;

    cout << "How many students registered? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Roll Number: ";
        cin >> roll;

        students.addStudent(roll);
    }

    students.displayStudents();

    cout << "Enter Roll Number to Search: ";
    cin >> searchRoll;

    students.searchStudent(searchRoll);

    return 0;
}
