#include <iostream>
using namespace std;

int main()
{
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int Sum[3][3];

    cout << "Matrix A:" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << A[i][j] << "  ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Matrix B:" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << B[i][j] << "  ";
        }
        cout << endl;
    }

    cout << endl;

    // Adding Matrix A and Matrix B
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Sum[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "Sum of Matrix A and B:" << endl;
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << Sum[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}
