#include <iostream>
using namespace std;

int main() {
    const int rows = 4;
    const int columns = 5;

    // 2D parking array
    // 0 = Empty, 1 = Occupied
    int parking[rows][columns] = {
        {1, 0, 1, 0, 1},
        {0, 1, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 1, 1}
    };

    int occupied = 0;
    int empty = 0;

    // Display parking layout
    cout << "========== PARKING LAYOUT ==========\n";

    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ": ";

        for (int j = 0; j < columns; j++) {
            cout << parking[i][j] << " ";

            // Count occupied and empty spaces
            if (parking[i][j] == 1) {
                occupied++;
            } else {
                empty++;
            }
        }

        cout << endl;
    }

    // Display occupied and empty spaces
    cout << "\nTotal occupied spaces: " << occupied << endl;
    cout << "Total empty spaces: " << empty << endl;

    // Ask user for row and column
    int row, column;

    cout << "\nEnter row number (1-4): ";
    cin >> row;

    cout << "Enter column number (1-5): ";
    cin >> column;

    // Check whether selected space is valid
    if (row < 1 || row > 4 || column < 1 || column > 5) {
        cout << "Invalid row or column number!" << endl;
    }
    else {
        // Convert to array index
        row--;
        column--;

        if (parking[row][column] == 0) {
            cout << "The selected parking space is AVAILABLE." << endl;
        }
        else {
            cout << "The selected parking space is OCCUPIED." << endl;
        }
    }

    // Display parking capacity and current occupancy
    int capacity = rows * columns;

    cout << "\n========== PARKING INFORMATION ==========\n";
    cout << "Total parking capacity: " << capacity << endl;
    cout << "Current occupancy: " << occupied << endl;
    cout << "Available spaces: " << empty << endl;

    return 0;
}

