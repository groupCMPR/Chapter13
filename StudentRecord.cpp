//Name: Alexis Martinez and John Kim
//Date: 12/3/2023
//Description: cpp file for class StudentRecord

#include "StudentRecord.h"
//PreCondition:Accepts a string data type
//PostCondition: Parses the file information to create a student object
void StudentRecord::readData(const string& filename) {
    ifstream file(filename);
    string line, token;
    studentInfo.clear();

    if (!file) {
        cout << "\n\tERROR - File, " << filename << ", not found.";
        return;
    }

    while (getline(file, line)) {
        stringstream content(line);
        Student student;
        getline(content, token, ','); student.id = stoi(token);
        getline(content, token, ','); student.name = token;
        getline(content, token, ','); student.major = token;
        getline(content, token, ','); student.gpa = stod(token);
        studentInfo.push_back(student);
    }
    cout << "\n\tData have been read from " << filename << ".";
}
//PreCondition: None
//PostCondition: Displays all the students in the container 
void StudentRecord::displayRecords() {
    for (const auto& student : studentInfo) {
        cout << setw(10) << right << student.id;
        cout << setw(25) << right << student.name;
        cout << setw(20) << right << student.major;
        cout << setw(10) << right << student.gpa << endl;
    }
}
//PreCondition: Accepts a student object
//PostCondition: inserts that student at the end of the list 
void StudentRecord::insertRecord(const Student& newStudent) {
    studentInfo.push_back(newStudent);
}
//PreCondition: Accepts a string data type
//PostCondition: removes the student based off the name entered 
void StudentRecord::remove(const string& nameToRemove) {
    for (auto it = studentInfo.begin(); it != studentInfo.end(); ) {
        if (it->name == nameToRemove) {
            it = studentInfo.erase(it);
            cout << "\n\tThe student record has been removed.";
            return;
        }
        else {
            ++it;
        }
    }
    cout << "\n\tThe student record cannot be found to be removed.";
}
//PreCondition: Accepts two char data types 
//PostCondition: Sorts either by asending or descending order and either ID, Name,GPA or major 
void StudentRecord::sortRecords(char sortOrder, char sortBy) {
    if (sortBy == 'I') {
        sort(studentInfo.begin(), studentInfo.end(), [sortOrder](const Student& student1, const Student& student2) {
            return sortOrder == 'A' ? student1.id < student2.id : student1.id > student2.id;
            });
    }
    else if (sortBy == 'N') {
        sort(studentInfo.begin(), studentInfo.end(), [sortOrder](const Student& student1, const Student& student2) {
            return sortOrder == 'A' ? student1.name < student2.name : student1.name > student2.name;
            });
    }
    else if (sortBy == 'M') {
        sort(studentInfo.begin(), studentInfo.end(), [sortOrder](const Student& student1, const Student& student2) {
            return sortOrder == 'A' ? student1.major < student2.major : student1.major > student2.major;
            });
    }
    else if (sortBy == 'G') {
        sort(studentInfo.begin(), studentInfo.end(), [sortOrder](const Student& student1, const Student& student2) {
            return sortOrder == 'A' ? student1.gpa < student2.gpa : student1.gpa > student2.gpa;
            });
    }
}
//PreCondition: Accepts a string value for the file name
//PostCondition: Writes the list of students to a file
void StudentRecord::writeData(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "\n\tERROR - Unable to open file for writing: " << filename;
        return;
    }
    for (const auto& student : studentInfo) {
        file << setw(10) << right << student.id;
        file << setw(25) << right << student.name;
        file << setw(20) << right << student.major;
        file << setw(10) << right << student.gpa << endl;
    }
}
