#include <iostream>
using namespace std;

class Node
{
public:
    string patientID;
    Node* next;
};

class PatientQueue
{
private:
    Node* head;

public:
    PatientQueue()
    {
        head = NULL;
    }

    // Add patient at the end
    void addPatient(string id)
    {
        Node* newNode = new Node();

        newNode->patientID = id;
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

    // Display all waiting patients
    void displayPatients()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->patientID;

            if (temp->next != NULL)
            {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }

    // Remove the first patient
    void removeFirstPatient()
    {
        if (head == NULL)
        {
            cout << "No patients are waiting." << endl;
            return;
        }

        Node* temp = head;

        cout << "Patient " << head->patientID
             << " is being served." << endl;

        head = head->next;

        delete temp;
    }
};

int main()
{
    PatientQueue patients;

    // Adding patients
    patients.addPatient("P101");
    patients.addPatient("P102");
    patients.addPatient("P103");
    patients.addPatient("P104");

    cout << "Waiting Patients:" << endl;
    patients.displayPatients();

    // Serve first patient
    patients.removeFirstPatient();

    cout << "Updated Queue:" << endl;
    patients.displayPatients();

    return 0;
}

