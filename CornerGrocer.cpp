// Hunter Prince 2024 //
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip> // for formatting
using namespace std;

// Function to read the file and count the frequency of each item
map<string, int> countItems(const string& filePath) {
    map<string, int> frequency;
    ifstream file(filePath);
    string item;

    if (file.is_open()) {
        while (file >> item) {
            frequency[item]++;
        }
        file.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }
    return frequency;
}

// Menu Option 1: Get frequency of a specific item
void searchItem(const map<string, int>& frequency) {
    string item;
    cout << "Enter the item: ";
    cin >> item;

    auto it = frequency.find(item);
    if (it != frequency.end()) {
        cout << item << ": " << it->second << endl;
    }
    else {
        cout << item << " not found." << endl;
    }
}

// Menu Option 2: Print all item frequencies
void printFrequencies(const map<string, int>& frequency) {
    cout << "\nItem Frequency List:" << endl;
    for (const auto& pair : frequency) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// Menu Option 3: Print histogram of item frequencies
void printHistogram(const map<string, int>& frequency) {
    cout << "\nItem Frequency Histogram:" << endl;
    for (const auto& pair : frequency) {
        cout << setw(10) << left << pair.first << ": ";
        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Function to write the frequency data to frequency.dat
void writeFrequencyData(const map<string, int>& frequency) {
    ofstream outFile("frequency.dat");  // Output file for data backup
    if (outFile.is_open()) {
        for (const auto& pair : frequency) {
            outFile << pair.first << " " << pair.second << endl;
        }
        outFile.close();
        cout << "Data has been backed up to frequency.dat." << endl;
    }
    else {
        cout << "Unable to create or write to frequency.dat." << endl;
    }
}

// Main function with menu
int main() {
    string filePath = "Input.txt";  // Input file path
    map<string, int> frequency = countItems(filePath);

    // Write frequency data to frequency.dat
    writeFrequencyData(frequency);

    int choice;

    do {
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Search for an item\n";
        cout << "2. Display frequency of all items\n";
        cout << "3. Display histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            searchItem(frequency);
            break;
        case 2:
            printFrequencies(frequency);
            break;
        case 3:
            printHistogram(frequency);
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
