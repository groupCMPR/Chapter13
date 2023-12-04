//Names: Alexis Martinez, John Kim, Neidy Malaga, & Vivian Huynh
//Date: 11/27/2023
//Description: Chapter 13 Assignment - Sortings

#include <iostream> //For cout

//HEADER FILES
#include "input.h" //For input validation
#include "StudentRecord.h"
using namespace std;

//PROTOTYPES
int menuOption();
//Option 1 - Sorting simulations
void option1();
//Option 2 - Application of student records
void option2();

//Precondition : N/A
//Postcondition: Calls option 1 and 2
int main()
{
    do
    {
        system("cls");
        switch (menuOption())
        {
        case 0: exit(0);
        case 1: system("cls"); option1(); break;
        case 2: system("cls"); option2(); break;
        default: cout << "\t\tERROR: - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
    return 0;
}

//Precondition : Calls from main
//Postcondition: Returns integer choice
int menuOption()
{
    cout << "\n\tCMPR131 Chapter 13: Sortings (Final Group 11)";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\t\t1> Sorting simulations";
    cout << "\n\t\t2> Application of student records";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\t\t0> Exit";
    cout << "\n\t" << string(100, char(205));

    return inputInteger("\n\t\tOption: ", 0, 2);
}

//Precondition : Calls from main
//Postcondition: Simulate the different sorts
void option1()
{
    do
    {
        system("cls");
        cout << "\n\t1> Sort simulations";
        cout << "\n\t" << string(100, char(205));
        cout << "\n\t\tA> Create a dynamic array and fill with random elements";
        cout << "\n\t\tB> Display the unsorted array";
        cout << "\n\t\tC> Perform BubbleSort";
        cout << "\n\t\tD> Perform SelectionSort";
        cout << "\n\t\tE> Perform InsertionSort";
        cout << "\n\t\tF> Perform QuickSort";
        cout << "\n\t\tG> Perform MergeSort";
        cout << "\n\t\tH> Perform HeapSort";
        cout << "\n\t" << string(100, char(196));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(100, char(205));

        switch (inputChar("\n\t\tOption: ", static_cast<string>("ABCDEFGH0")))
        {
        case '0': return;
        case 'A': break;
        case 'B': break;
        case 'C': break;
        case 'D': break;
        case 'E': break;
        case 'F': break;
        case 'G': break;
        case 'H': break;
        default: cout << "\t\tERROR: - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}

//Precondition : Calls from main
//Postcondition: Apply a sort of student records
void option2()
{
    StudentRecord students;
    do
    {
        
        system("cls");
        cout << "\n\t2> Application of sorting student records";
        cout << "\n\t" << string(100, char(205));
        cout << "\n\t\tA> Read in data file";
        cout << "\n\t\tB> Display records";
        cout << "\n\t\tC> Insert a record";
        cout << "\n\t\tD> Remove a record";
        cout << "\n\t\tE> Sort records by ID, name, major or GPA";
        cout << "\n\t\tF> Write out data file";
        cout << "\n\t" << string(100, char(196));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(100, char(205));

        switch (inputChar("\n\t\tOption: ", static_cast<string>("ABCDEF0")))
        {
        case '0': return;
        case 'A':
            students.readData("Students.dat");
            
            break;
        case 'B':
            cout << "\n\tStudent records:\n";
            students.displayRecords();
            break;
        case 'C': {
            Student newStudent;

            newStudent.id = inputInteger("\n\tEnter a new student ID: ", true);
            newStudent.name = inputString("\n\tEnter the student's name: ", true);
            newStudent.major = inputString("\n\tEnter the student's major: ", true);
            newStudent.gpa = inputDouble("\n\tEnter the student's GPA: ", 0.0, 4.0);

            students.insertRecord(newStudent);
            cout << "\n\tNew student has been inserted.";
            break;
        }
        case 'D': 
            students.remove(inputString("\n\tEnter a student's name to remove: ", true));
            break;
        case 'E': {
            StudentRecord sortVersion = students;
            char sortOrder = inputChar("\n\tChoose sort in (A)-ascending or (D)-descending order: ", 'A', 'D');
            char sortBy = inputChar("\n\tChoose by (I)-ID, (N)-name, (M)-major or (G)-GPA: ", static_cast<string>("INMG"));

            sortOrder == 'A' ? cout << "\n\tAscending order:\n" : cout << "\n\tDescending order:\n";

            sortVersion.sortRecords(sortOrder, sortBy);
            sortVersion.displayRecords();
            break;
        }
        case 'F': 
            students.writeData("students.dat");
            cout << "\n\tData have been saved to students.dat.";
            break;
        default: cout << "\t\tERROR: - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}