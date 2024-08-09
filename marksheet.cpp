#include <iostream>
#include <iomanip>

using namespace std;

void displayInterface() {
    cout << "======================================" << endl;
    cout << "         Simple Marksheet Calculator  " << endl;
    cout << "======================================" << endl;
}

void calculateMarks() {
    int subjects;
    cout << "Enter the number of subjects: ";
    cin >> subjects;

    int marks[subjects];
    int totalMarks = 0;

    for (int i = 0; i < subjects; i++) {
        cout << "Enter marks for subject " << i + 1 << ": ";
        cin >> marks[i];
        totalMarks += marks[i];
    }

    double percentage = (double)totalMarks / subjects;

    cout << "======================================" << endl;
    cout << "Total Marks: " << totalMarks << endl;
    cout << "Percentage: " << fixed << setprecision(2) << percentage << "%" << endl;
    cout << "======================================" << endl;

    if (percentage >= 50) {
        cout << "Status: Pass" << endl;
    } else {
        cout << "Status: Fail" << endl;
    }
}

int main() {
    displayInterface();
    calculateMarks();
    return 0;
}
