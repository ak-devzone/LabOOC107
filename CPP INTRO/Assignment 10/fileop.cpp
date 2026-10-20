
#include <iostream>
#include <fstream>  // Header file for file handling
using namespace std;

int main() {
    // Create an object of ofstream to write data
    ofstream fout;

    // Declare a string variable to store input
    string line;

    // Open the file for writing
    fout.open("sample.txt");

    // Read input until the user enters -1
    while (true) {
        // Read a complete line from the keyboard
        getline(cin, line);

        // Stop the loop if the user enters -1
        if (line == "-1")
            break;

        // Write the line into the file
        fout << line << endl;
    }

    // Close the file after writing
    fout.close();

    // Create an object of ifstream to read data
    ifstream fin;

    // Open the file for reading
    fin.open("sample.txt");

    // Read the file line by line until EOF
    while (getline(fin, line)) {
        // Display each line on the screen
        cout << line << endl;
    }

    // Close the file after reading
    fin.close();

    return 0;  // End the program
}
