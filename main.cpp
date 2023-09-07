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


// base class
struct SElement{
    virtual void showValueAndType() = 0;
};

struct Empty : SElement{
    virtual void showValueAndType(){cout<< "Empty";}
};

struct Integer : SElement{
    int value;
    virtual void showValueAndType() {cout << "Int(" <<to_string(value) << ")";}
    Integer(int val){value = val;}
};

struct Float : SElement{
    float value;
    virtual void showValueAndType() {cout << "Float(" <<to_string(value) << ")";}
    Float(float val){value = val;}

};

struct String : SElement{
    string value;
    virtual void showValueAndType() {cout << "String(" <<value << ")";}
    String(string val){value = val;}

};

int main(){

//declaring vector that will contain all data
    vector<string> allData;

    ifstream inputFile;

    //accessing the CSV data file
    inputFile.open("data.csv");

    //creating a clear line variable
    string line = "";

    //reading csv
    while (getline(inputFile, line)){
        
        //variables to parse out line
        string var;
        //creating a string out of the line
        stringstream inputString(line);


        getline(inputString, var, ',');
        allData.push_back(var);

        getline(inputString, var, ',');
        allData.push_back(var);

        getline(inputString, var, ',');
        allData.push_back(var);


    }

    for (int i=0; i<allData.size(); i++){
        cout << allData[i] <<endl;
    }

    return 0;
}