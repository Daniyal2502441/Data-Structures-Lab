#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int students = 6;
    const int subjects = 4;

    string subjectNames[subjects] = {
        "English", "Mathematics", "Programming", "AI"
    };

    // 2D array to store marks
    int marks[students][subjects] = {
        {85, 90, 88, 92},
        {78, 82, 85, 80},
        {92, 95, 90, 94},
        {75, 80, 78, 85},
        {88, 86, 91, 89},
        {95, 93, 96, 97}
    };

    cout << "================ MARKS TABLE ================\n";

    cout << left << setw(12) << "Student";

    for (int j = 0; j < subjects; j++) {
        cout << setw(15) << subjectNames[j];
    }

    cout << setw(12) << "Total";
    cout << "Average\n";

    int highestTotal = 0;
    int highestStudent = 0;

    // Display marks, calculate total and average
    for (int i = 0; i < students; i++) {

        int total = 0;

        cout << left << setw(12) << "Student";

        // Display student number without to_string()
        cout << i + 1 << "\t";

        for (int j = 0; j < subjects; j++) {
            cout << setw(15) << marks[i][j];
            total += marks[i][j];
        }

        double average = (double) total / subjects;

        cout << setw(12) << total;
        cout << fixed << setprecision(2) << average << endl;

        // Find highest total
        if (total > highestTotal) {
            highestTotal = total;
            highestStudent = i;
        }
    }

    // Find highest marks in each subject
    cout << "\n========== HIGHEST MARKS IN EACH SUBJECT ==========\n";

    for (int j = 0; j < subjects; j++) {

        int highest = marks[0][j];

        for (int i = 1; i < students; i++) {
            if (marks[i][j] > highest) {
                highest = marks[i][j];
            }
        }

        cout << subjectNames[j] << ": " << highest << endl;
    }

    // Display student with highest total
    cout << "\n========== HIGHEST TOTAL MARKS ==========\n";

    cout << "Student " << highestStudent + 1
         << " has the highest total marks: "
         << highestTotal << endl;

    return 0;
}

