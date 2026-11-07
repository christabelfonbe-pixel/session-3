#include <iostream>
using namespace std;

int main() {
    int marks[8] = {45, 78, 90, 32, 67, 88, 54, 73};
    int sum = 0;
    int highest = marks[0];
    int lowest = marks[0];
    int passCount = 0;
    const int passMark = 50;

    // Process all eight marks.
    for (int i = 0; i < 8; i++) {
        sum += marks[i];

        if (marks[i] > highest) {
            highest = marks[i];
        }

        if (marks[i] < lowest) {
            lowest = marks[i];
        }

        if (marks[i] >= passMark) {
            passCount++;
        }
    }

    double average = static_cast<double>(sum) / 8;

    cout << "CLASS RESULTS\n";
    cout << "Total: " << sum << '\n';
    cout << "Average: " << average << '\n';
    cout << "Highest mark: " << highest << '\n';
    cout << "Lowest mark: " << lowest << '\n';
    cout << "Number of passes: " << passCount << '\n';

    cout << "\nFailing students (index starts at 0):\n";
    for (int i = 0; i < 8; i++) {
        if (marks[i] < passMark) {
            cout << "Index " << i << ": " << marks[i] << '\n';
        }
    }

    // Search for a mark entered by the user.
    int target;
    bool found = false;

    cout << "\nEnter a mark to search for: ";
    cin >> target;

    for (int i = 0; i < 8; i++) {
        if (marks[i] == target) {
            found = true;
            cout << "Mark found at index " << i << ".\n";
        }
    }

    if (!found) {
        cout << "That mark does not exist in the array.\n";
    }

    return 0;
}

/*
EXPLANATION
- marks is an integer array containing eight marks.
- sum stores the total of all marks.
- highest and lowest track the largest and smallest values.
- passCount increases whenever a mark is at least 50.
- static_cast<double> ensures the average can contain decimal places.
- Array indexes start at 0, so the eight positions are 0 to 7.
- found records whether the requested mark was present.

EXPECTED RESULTS
Total = 527
Average = 65.875
Highest = 90
Lowest = 32
Passes = 6
Failing marks: index 0 (45), index 3 (32)
*/
