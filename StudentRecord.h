//Name: Alexis Martinez and John Kim
//Date: 12/3/2023
//Description: Header file for class StudentRecord

#pragma
#include <iostream>  //For cout
#include <vector>    //For vector
#include <string>    //For string
#include <fstream>   //For reading and writing in file
#include <sstream>   //For stringstream
#include <iomanip>   //For formatting output
#include <algorithm> //For sorting

using namespace std;
//Struct to use for parsed data from file
struct Student {
    int id;
    string name;
    string major;
    double gpa;
};

class StudentRecord {
private:
    vector<Student> studentInfo;

public:
//members
    void readData(const string& filename);
    void displayRecords();
    void insertRecord(const Student& newStudent);
    void remove(const string& nameToRemove);
    void sortRecords(char sortOrder, char sortBy);
    void writeData(const string& filename);
};
