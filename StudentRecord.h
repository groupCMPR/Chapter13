#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

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
    void readData(const string& filename);
    void displayRecords();
    void insertRecord(const Student& newStudent);
    void remove(const string& nameToRemove);
    void sortRecords(char sortOrder, char sortBy);
    void writeData(const string& filename);
};
