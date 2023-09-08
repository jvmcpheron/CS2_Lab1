/* 
CS 2 Lab 1
Jane McPheron
*/

 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;





// Base class
struct SElement {
    virtual void showValueAndType() = 0;

};



// Derived classes
struct Empty : SElement {
    virtual void showValueAndType() {
        cout << "Empty";
    }

};


struct Integer : SElement {
    int value;
    Integer(int val) : value(val) {}

    virtual void showValueAndType() {
        cout << "Int(" << value << ")";
    }
};

struct Float : SElement {
    float value;
    Float(float val) : value(val) {}

    virtual void showValueAndType() {
        cout << "Float(" << value << ")";
    }
};

struct String : SElement {
    string value;
    String(const string& val) : value(val) {}

    virtual void showValueAndType() {
        cout << "String(" << value << ")";
    }
};

int main() {
    vector<SElement*> spreadsheet;

    // Open the CSV file
    ifstream csvFile("data.csv");

    // exit if no file
    if (!csvFile.is_open()) {
        cerr << "Error: Unable to open the CSV file." << endl;
        return 1; 
    }

    //going through data and sorting it
    string line;
    while (getline(csvFile, line)) {
        istringstream iss(line);
        string token;
        while (getline(iss, token, ',')) {
            
            if (token.empty()) {

                spreadsheet.push_back(new Empty());

            } else if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                int intValue;
                istringstream(token) >> intValue;


                spreadsheet.push_back(new Integer(intValue));

            } else if (isdigit(token[0]) || token[0] == '-') {
                float floatValue;
                istringstream(token) >> floatValue;
                spreadsheet.push_back(new Float(floatValue));

            } else {
                spreadsheet.push_back(new String(token));

            }

        }
    }

    //looping to displaying values
    for (SElement* element : spreadsheet) {
        
        element->showValueAndType();
        cout << " ";


    }

    //code to delete everything to prevent memory leaks
    for (SElement* element : spreadsheet) {
        
        delete element;


    }


}
