#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

enum class Status {
    PASS,
    FAIL
};

struct Student {
    int id;
    string name;
    double mark1;
    double mark2;
    double mark3;
    double average;
    Status status;
};

int main() {
    const double passMark = 50.0;

    // Create five student records.
    vector<Student> students = {
        {101, "Amina", 60, 70, 80, 0, Status::FAIL},
        {102, "Brian", 40, 50, 45, 0, Status::FAIL},
        {103, "Carla", 50, 50, 50, 0, Status::FAIL},
        {104, "David", 90, 85, 95, 0, Status::FAIL},
        {105, "Esther", 35, 55, 60, 0, Status::FAIL}
    };

    // Calculate each average and status.
    for (Student &student : students) {
        student.average =
            (student.mark1 + student.mark2 + student.mark3) / 3.0;

        if (student.average >= passMark) {
            student.status = Status::PASS;
        } else {
            student.status = Status::FAIL;
        }
    }

    // Display a formatted report.
    cout << fixed << setprecision(2);
    cout << "\nSTUDENT CLASS REPORT\n";
    cout << left << setw(8) << "ID"
         << setw(15) << "Name"
         << setw(12) << "Average"
         << "Status\n";
    cout << "----------------------------------------\n";

    for (const Student &student : students) {
        cout << left << setw(8) << student.id
             << setw(15) << student.name
             << setw(12) << student.average
             << (student.status == Status::PASS ? "PASS" : "FAIL")
             << '\n';
    }

    // Search for a student by ID.
    int requestedID;
    cout << "\nEnter student ID to search for: ";
    cin >> requestedID;

    bool found = false;
    for (const Student &student : students) {
        if (student.id == requestedID) {
            found = true;
            cout << "Found: " << student.name
                 << ", average: " << student.average
                 << ", status: "
                 << (student.status == Status::PASS ? "PASS" : "FAIL")
                 << '\n';
            break;
        }
    }

    if (!found) {
        cout << "No student has that ID.\n";
    }

    // Demonstrate the exact pass threshold.
    double testAverages[] = {49.99, 50.00};
    cout << "\nThreshold test:\n";
    for (double value : testAverages) {
        cout << value << " -> "
             << (value >= passMark ? "PASS" : "FAIL") << '\n';
    }

    return 0;
}

/*
EXPLANATION
- enum class Status defines two possible student outcomes.
- struct Student groups related information about one student.
- vector<Student> stores five Student objects and can grow when needed.
- The loop calculates the average of the three marks.
- An average of 50 or above is PASS; anything below 50 is FAIL.
- setw and left help align the report into columns.
- The search loop checks each student's ID.
- The threshold test confirms that 49.99 fails and 50.00 passes.

The example records are sample data because the exercise does not prescribe
student names, IDs, or individual marks.
*/
