
/*
Question: Write a C++ program to count the number of lines,
words and characters in a text file.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("sample.txt");

    string line, word;
    int lines = 0, words = 0, characters = 0;

    // Check whether the file is opened
    if (!fin) {
        cout << "File not found!" << endl;
        return 1;
    }

    // Read the file line by line
    while (getline(fin, line)) {
        lines++;

        // Count characters in the line
        characters += line.length();

        // Count words in the line
        int i = 0;
        while (i < line.length()) {
            // Skip spaces
            while (i < line.length() && line[i] == ' ')
                i++;

            // Count a word
            if (i < line.length()) {
                words++;

                // Move to the next space
                while (i < line.length() && line[i] != ' ')
                    i++;
            }
        }
    }

    // Close the file
    fin.close();

    // Display the results
    cout << "Number of lines: " << lines << endl;
    cout << "Number of words: " << words << endl;
    cout << "Number of characters: " << characters << endl;

    return 0;
}
