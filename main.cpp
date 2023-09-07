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

    return 0;
}