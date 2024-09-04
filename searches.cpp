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
#include <cstring> 
#include <string> 

using namespace std;

int binarySearch(string iName, int size, vector<char> vowels);
void linearSearch(string iName, string inputName, bool &vowelFound);
void noVowel(bool &vowelFound);

vector<char> vowels{'a', 'A', 'e', 'E', 'o', 'O', 'i', 'I', 'u', 'U'};

int main () {
    string iName;
    //string inputName; 
    int searchType;
    bool vowelFound = false; 
    int position;
    //int size, searchValue;
    //vector<string>name;
    int size = 10;
    //const int length = inputName.length();

    //char* char_array = new char(length + 1);

    //strcpy(char_array, inputName.c_str());
    cout << "Input your name:\n";
    cin >> iName;

    cout << "What type of search would you like to use to detect vowels?\n";
    cout << "1.) Binary Search\n";
    cout << "2.) Linear Search\n";

    cin >> searchType;

    (searchType == 1) ? void(position = binarySearch(iName, size, vowels)) :
        (searchType == 2) ? void(linearSearch(iName, inputName, vowelFound)) :
            void(cout << "Invalid input, try again");

    
    noVowel(vowelFound);
}

int binarySearch(string iName, int size, vector<char> vowels) {
    //vector<string> name;
    //bool vowelFound = false; 
    int first = 0, last = size - 1, middle, position = -1;       		  // Position of search value
    bool found = false;       												// Flag
    int count = 0;

    const int length = iName.length(); 
  
    // declaring character array (+1 for null terminator) 
    char* name_array = new char[length + 1]; 
  
    // copying the contents of the 
    // string to char array 
    strcpy(name_array, iName.c_str()); 

    while (!found && first <= last) {
	    count++;
	    cout << "\n\tcount = " << count;

	    middle = (first + last) / 2;     		 // Calculate mid point
	if (vowels[middle] == char('a').name_array())     {      		  // If value is found at mid
		found = true;
		position = middle;
	}
	else if (vowels[middle] > char('a').name_array())        		 // If value is in lower half
		last = middle - 1;
	else
		first = middle + 1;            		// If value is in upper half
    }
        cout << "\n\tcount = " << count;
    return position;

    /*cout << "You chose Binary Search, input your name:\n";
    cin >> inputName;

    name.push_back(inputName);


    while(!found && first <= last) {
        count++;
        cout << "\n\tcount = " << count;

        middle = (first + last / 2);
        if (name[middle] == inputName) {
            found = true;
            position = middle;
        } else if {
            last = middle - 1;
        } else {
            first = middle + 1;
        }
        cout << "\n\tcount = " << count;
        return position;
    }

    iName = inputName;
    //name = inputName;
    //name.push_back(inputName);

    for (int i = 0; i < iName.size(); i++) {
        char charName = iName[i];
        (charName == 'a' || charName == 'A') ? void(cout << "\na\n") :
                (charName == 'e' || charName == 'E') ? void(cout << "\ne\n") :
                    (charName == 'o' || charName == 'O') ? void(cout << "\no\n") :
                        (charName == 'i' || charName == 'I') ? void(cout << "\ni\n") :
                            (charName == 'u' || charName == 'U') ? void(cout << "\nu\n") :
                                void(cout << " "); 
        
        (charName == 'a' || charName == 'A') ? void(vowelFound = true) :
                (charName == 'e' || charName == 'E') ? void(vowelFound = true) :
                    (charName == 'o' || charName == 'O') ? void(vowelFound = true) :
                        (charName == 'i' || charName == 'I') ? void(vowelFound = true) :
                            (charName == 'u' || charName == 'U') ? void(vowelFound = true) :
                                void(cout << " "); 

    }*/
}

void linearSearch(string iName, string inputName, bool &vowelFound) {
    //char tmp; 

    cout << "You chose Linear Search, input your name:\n";
    cin >> inputName; 


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

void noVowel(bool &vowelFound) {
    if (vowelFound == false) {
        cout << "\nThere are no vowels in that name.\n";
    }
}