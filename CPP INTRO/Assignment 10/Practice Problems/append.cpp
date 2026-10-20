
 /*
Question: Write a C++ program to append new records to a file
and then display all records.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string record;

    // Open file in append mode
    ofstream fout("records.txt", ios::app);

    // Enter new records
    cout << "Enter records (type -1 to stop):" << endl;

    while (true) {
        getline(cin, record);

        if (record == "-1")
            break;

        // Append record to the file
        fout << record << endl;
    }

    // Close file after writing
    fout.close();

    // Open file for reading
    ifstream fin("records.txt");

    // Display all records
    cout << "\nAll Records:" << endl;

    while (getline(fin, record)) {
        cout << record << endl;
    }

    // Close file after reading
    fin.close();

    return 0;
}
