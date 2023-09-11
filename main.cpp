/* 
CS 2 Lab 1
Jane McPheron
*/

 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>





// Base class
struct SElement {
    virtual void showValueAndType() = 0;

};



// Derived classes
struct Empty : SElement {
    virtual void showValueAndType() {
        std::cout << "Empty";
    }

};


struct Integer : SElement {
    int value;
    Integer(int val) : value(val) {}

    virtual void showValueAndType() {
        std::cout << "Int(" << value << ")";
    }
};

struct Float : SElement {
    float value;
    Float(float val) : value(val) {}

    virtual void showValueAndType() {
        std::cout << "Float(" << value << ")";
    }
};

struct String : SElement {
    std::string value;
    String(const std::string& val) : value(val) {}

    virtual void showValueAndType() {
        std::cout << "String(" << value << ")";
    }
};

int main() {
    std::vector<SElement*> spreadsheet;

    // Open the CSV file
    std::ifstream csvFile("data.csv");

    // exit if no file
    if (!csvFile.is_open()) {
        std::cerr << "Error: Unable to open the CSV file." << std::endl;
        return 1; 
    }

    //going through data and sorting it


    //idea: Useful functions stod (string to double), stoi (string to integer)
    //Use try and catch blocks

    std::string line;
    while (getline(csvFile, line)) {
        std::istringstream iss(line);
        std::string token;
        while (getline(iss, token, ',')) {
            
            if (token.empty()) {

                spreadsheet.push_back(new Empty());

            } else if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                
                int intValue;
                std::istringstream(token) >> intValue;


                spreadsheet.push_back(new Integer(intValue));

            } else if (isdigit(token[0]) || token[0] == '-') {
                float floatValue;
                std::istringstream(token) >> floatValue;
                spreadsheet.push_back(new Float(floatValue));

            } else {
                spreadsheet.push_back(new String(token));

            }

        }
    }

    //looping to displaying values
    for (SElement* element : spreadsheet) {
        
        element->showValueAndType();
        std::cout << " ";


    }

    //code to delete everything to prevent memory leaks
    for (SElement* element : spreadsheet) {
        
        delete element;


    }


}
