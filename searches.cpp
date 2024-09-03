/* 
@ AJ Enrique Arguello (9/1/24)

Q3 What’s in a name – Searches. Create 2 Searches (each one a Function)

Use a Linear Search and then a Binary search

Prompt the user to enter their name

  Send the name to each Function

      1. Search for vowels - Display the vowels that are in their name

      2. Calculate the Big O for each type of search*/


#include <iostream>
#include <vector>

using namespace std;

void binarySearch(vector<char> name, string inputName);
void bubbleSort(vector<char> name, string inputName);

int main () {
    vector<char> name;
    string inputName; 
    int searchType;

    cout << "What type of search would you like to use to detect vowels?\n";
    cout << "1.) Binary Search\n";
    cout << "2.) Bubble Sort\n";

    cin >> searchType;

    (searchType == 1) ? void(binarySearch(name, inputName)) :
        (searchType == 2) ? void(bubbleSort(name, inputName)) :
            void(cout << "Invalid input, try again");


}

void binarySearch(vector<char> name, string inputName) {
    cout << "You chose Binary Search, input your name:\n";
    cin >> inputName;
}

void bubbleSort(vector<char> name, string inputName) {
    char tmp; 

    cout << "You chose Bubble Sort, input your name:\n";
    cin >> inputName; 

    name.push_back(inputName); 

    for (int i = 0; i < name.size(); i++) {
        for (int j = 0; j < name.size() - 1; j++) {
            (name[j] = 'a' || name[j-1] = 'a') ? (cout << "\na\n") :
                (name[j] = 'e' || name[j-1] = 'e') ? (cout << "\ne\n") :
                    (name[j] = 'o' || name[j-1] = 'o') ? (cout << "\no\n") :
                        (name[j] = 'i' || name[j-1] = 'i') ? (cout << "\ni\n") :
                            (name[j] = 'u' || name[j-1] = 'u') ? (cout << "\nu\n") :
                                cout << "There are no vowels in that name"; 
        }
    }
/*
    for (int j = 1; j <= i-1; j++) {
    for (int k = 0; k < i-1; k++) {
      if (name[k] > name[k + 1]) { // prints letters in alphabetical order
        tmp = inputName[k];
        inputName[k] = inputName[k + 1];
        inputName[k + 1] = tmp;
      }
    }
  }*/
}