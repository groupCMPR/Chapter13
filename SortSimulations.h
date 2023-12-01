//Name: Neidy Malaga and Vivian Huynh
//Date: 11/29/2023
//Description: Header file for template class SortSimulations

#pragma
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class SortSimulations
{
private: 
	vector<T> myVector;
	T partition_descend(int, int);
	T partition_ascend(int, int);
	void mergeSortHalf(int, int, int, bool (compare_func)(T, T));

public:
	bool lesserCompare(T, T);
	SortSimulations();
	SortSimulations(SortSimulations<T>&);

	int getSize();
	bool isEmpty();
	int bubbleSort(int, int, bool (compare_func)(T, T));
	int selectionSort(int, int, bool (compare_func)(T, T));
	int insertionSort(int, int, bool (compare_func)(T, T));
	int heapSort(int, int, bool (compare_func)(T, T));

	void push(const T&);
	void quickSort(int, int, bool);
	void mergeSort(int, int, bool (compare_func)(T, T));
	void display();
};

#include "SortSimulations.template"

template <class T>
bool greaterCompare(T comp_1, T comp_2);

template <class T>
bool lesserCompare(T comp_1, T comp_2);
