#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Function prototypes
void linearSearch(string &iName, vector<char> &vowels, unordered_set<char> &foundVowels);
void binarySearch(vector<char> &sortedVowels,  vector<char> &vowels, unordered_set<char> &foundVowels);
void printVowels(unordered_set<char> &foundVowels);
void sortVowels(string &iName, vector<char> &sortedVowels);

vector<char> vowels{'a', 'A', 'e', 'E', 'o', 'O', 'i', 'I', 'u', 'U'}; // vowel vector

int main() {
    string iName;
    int searchType;
    unordered_set<char> foundVowels; // char vector to store found vowels
    vector<char> sortedVowels; // char vector to store sorted vowels

    cout << "Input your name:\n";
    cin >> iName;

    cout << "What type of search would you like to use to detect vowels?\n";
    cout << "1.) Linear Search\n";
    cout << "2.) Binary Search\n";

    cin >> searchType;

    if (searchType == 1) {
        linearSearch(iName, vowels, foundVowels); // both vectors and string variable are passed by reference 
        printVowels(foundVowels); // foundvowels vector is passed by reference
    } else if (searchType == 2) {
        sortVowels(iName, sortedVowels); // collects voewels from iName and sorts
        binarySearch(sortedVowels, vowels, foundVowels); // checks if each extracted vowel from name exists in list of vowels
        printVowels(foundVowels);
    } else {
        cout << "Invalid input, try again.\n";
    }

    return 0;
}

// Linear search function to find vowels in the input name
void linearSearch(string &iName,  vector<char> &vowels, unordered_set<char> &foundVowels) {
    for (char ch : iName) { // iterates over each character in iName
        for (char vowel : vowels) { // iterates over each character in vowels vector
            if (ch == vowel) {
                foundVowels.insert(vowel); // inserts vowel into the foundVowels set 
                break; // No need to check further vowels for this character
            }
        }
    }
}

void binarySearch( vector<char>& sortedVowels,  vector<char>& vowels, unordered_set<char>& foundVowels) { //this function is to find vowels in sorted list
    for (char vowel : vowels) { // collects vowels from input name 
        if (binary_search(sortedVowels.begin(), sortedVowels.end(), vowel)) { // checks for the prescence of a value in a sorted range
            foundVowels.insert(vowel); // inserts vowels into foundVowels set if found 
        }
    }
}

// Function to print the found vowels
void printVowels( unordered_set<char> &foundVowels) {
    if (foundVowels.empty()) { // if set is empty
        cout << "No vowel found in the name.\n";
    } else {
        cout << "Vowels found in the name: ";
        for (char vowel : foundVowels) { // prints vowels found
            cout << vowel << " ";
        }
    }
}

void sortVowels( string& iName, vector<char>& sortedVowels) { // function to sort vowels/extract duplicates
    unordered_set<char> vowelSet{'a', 'A', 'e', 'E', 'o', 'O', 'i', 'I', 'u', 'U'};
    vector<char> foundVowels;

    for (char ch : iName) { // iterates over input name
        if (vowelSet.find(ch) != vowelSet.end()) {
            foundVowels.push_back(ch);
        }
    }

    // Remove duplicates by converting vector to set, then back to vector
    sort(foundVowels.begin(), foundVowels.end()); // Sort the vowels

    // Remove duplicates
    auto last = unique(foundVowels.begin(), foundVowels.end());
    foundVowels.erase(last, foundVowels.end());

    sortedVowels = foundVowels; // Assign sorted unique vowels to the output parameter
}
