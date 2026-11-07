#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string fullName;

    cout << "Enter your full name: ";
    getline(cin, fullName);

    if (fullName.empty()) {
        cout << "You did not enter a name.\n";
        return 0;
    }

    // Display the length and first character.
    cout << "Name: " << fullName << '\n';
    cout << "Length: " << fullName.length() << '\n';
    cout << "First character: " << fullName[0] << '\n';

    // Check whether the name contains a space.
    bool containsSpace = false;
    for (char character : fullName) {
        if (character == ' ') {
            containsSpace = true;
            break;
        }
    }

    if (containsSpace) {
        cout << "The name contains a space.\n";
    } else {
        cout << "The name does not contain a space.\n";
    }

    // Safely create a username from the first three characters.
    if (fullName.length() >= 3) {
        string username = fullName.substr(0, 3) + "123";
        cout << "Generated username: " << username << '\n';
    } else {
        cout << "Name is too short for a three-character username.\n";
    }

    // Compare two strings. C++ string comparison is case-sensitive.
    string first, second;
    cout << "\nEnter the first word: ";
    cin >> first;
    cout << "Enter the second word: ";
    cin >> second;

    if (first == second) {
        cout << "The words are exactly the same.\n";
    } else {
        cout << "The words are different (capital letters matter).\n";
    }

    // Extra challenge: make lowercase copies safely.
    string lowerFirst = first;
    string lowerSecond = second;

    for (char &character : lowerFirst) {
        character = static_cast<char>(
            tolower(static_cast<unsigned char>(character))
        );
    }

    for (char &character : lowerSecond) {
        character = static_cast<char>(
            tolower(static_cast<unsigned char>(character))
        );
    }

    if (lowerFirst == lowerSecond) {
        cout << "They are the same when letter case is ignored.\n";
    } else {
        cout << "They are still different when letter case is ignored.\n";
    }

    return 0;
}

/*
EXPLANATION
- getline reads a complete line, including spaces.
- length() returns the number of characters.
- fullName[0] accesses the first character.
- A range-based for loop checks each character.
- substr(0, 3) takes three characters starting at position zero.
- == compares strings. The normal comparison is case-sensitive.
- tolower converts a character to lowercase.
- The unsigned-char conversion avoids undefined behaviour for some
  character values when using cctype functions.

TEST
A name shorter than three characters is handled without calling substr
with an invalid starting position.
*/
