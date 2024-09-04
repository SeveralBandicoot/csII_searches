/* 

@ AJ Enrique Arguello (8/25/24)

Q3 What’s in a name – Searches. Create 2 Searches (each one a Function)

Use a Linear Search and then a Binary search

Prompt the user to enter their name

  Send the name to each Function

      1. Search for vowels - Display the vowels that are in their name

      2. Calculate the Big O for each type of search

*/

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

void linearSearch(string &iName,  vector<char> &vowels, unordered_set<char> &foundVowels) {
    for (size_t i = 0; i < iName.size(); ++i) { // iterates over input name
        char charName = iName[i]; //grabs current characters from input name
        
        for (size_t j = 0; j < vowels.size(); ++j) { // iterates each character in vowels
            if (charName == vowels[j]) {
                foundVowels.insert(vowels[j]); // vowel is inserted into foundVowels set
                break;
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

void sortVowels(string& iName, vector<char>& sortedVowels) {
    unordered_set<char> vowelSet{'a', 'A', 'e', 'E', 'o', 'O', 'i', 'I', 'u', 'U'};
    vector<char> foundVowels;

    for (size_t i = 0; i < iName.size(); ++i) { // extracts vowels from inputname
        char ch = iName[i];
        if (vowelSet.find(ch) != vowelSet.end()) { // checks if ch matches a element within vowelSet, if so, push into foundVowels vector
            foundVowels.push_back(ch);
        }
    }

    sort(foundVowels.begin(), foundVowels.end()); // sorts set of found vowels in ascending order 

    vector<char> noDuplicates; // new vector to store vowels without duplicates
    if (!foundVowels.empty()) { // if foundvowels is not empty 
        noDuplicates.push_back(foundVowels[0]); // add first element
        for (size_t i = 1; i < foundVowels.size(); ++i) { // iterates over foundvowels vector starting with the second element 
            if (foundVowels[i] != foundVowels[i - 1]) { // if current vowel is different from the previous, add to noDuplicates as it is not a duplicate
                noDuplicates.push_back(foundVowels[i]);
            }
        }
    }

    sortedVowels = noDuplicates; // moves elements from noDuplicates to sortedVowels vector
}