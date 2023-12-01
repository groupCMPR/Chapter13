//Name: Neidy Malaga and Vivian Huynh
//Date: 11/29/2023
//Description: Header file for template class SortSimulations

#ifndef SORTSIMULATIONS_H
#define SORTSIMULATIONS_H
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
	T partition_descend(size_t, size_t);
	T partition_ascend(size_t, size_t);
	void mergeSortHalf(size_t, size_t, size_t, bool (compare_func)(double, double));

public:
	bool lesserCompare(T, T);
	SortSimulations();
	SortSimulations(SortSimulations<T>&);

	int getSize();
	bool isEmpty();
	int insertionSort(int, int, bool (compare_func)(T, T));
	int selectionSort(size_t, int, bool (compare_func)(T, T));
	int heapSort(size_t, int, bool (compare_func)(double, double));

	void push(const T&);
	void quickSort(int, int, bool);
	void mergeSort(size_t, size_t, bool (compare_func)(double, double));
	void display();
};

#include "SortSimulations.template"
#endif

template <class T>
bool greaterCompare(T comp_1, T comp_2);

template <class T>
bool lesserCompare(T comp_1, T comp_2);