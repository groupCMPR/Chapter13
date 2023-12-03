//Name: Neidy Malaga and Vivian Huynh
//Date: 11/29/2023
//Description: Header file for template class SortSimulations

#pragma
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

template <class T>
class SortSimulations
{
private:
	vector<T> original_Vector;
	vector<T> myVector;
	vector<T> merged_array;
	size_t count;

public:
	SortSimulations();

	//mutators
	void set_sort_array();
	void set_Array(int size);
	void bubble_sort_recurse(size_t, static bool (*compare_func)(T, T));
	void selection_sort_recurse(size_t, bool (*compare_func)(T, T));
	void insertion_sort_recurse(size_t, bool (*compare_func)(T, T));
	void sort_heap_recurse(size_t, bool (*compare_func)(T, T));
	void merge(size_t, size_t, size_t end, bool (*compare_func)(T, T));
	void mergesort(size_t, size_t, bool (*compare_func)(T, T));
	T partition(size_t low, size_t high, bool(compare_func(T, T)));
	void quick_sort(size_t low, size_t high, bool (*compare_func)(T, T));
	void display();
	void reset_Count();

	//accessors
	static bool greater_compare(T comp_1, T comp_2);
	static bool lesser_compare(T comp_1, T comp_2);
	size_t get_Size() const;
	bool is_Empty() const;

	template <typename T>
	friend ostream& operator<< (ostream& out, const SortSimulations<T>& obj);
};

#include "SortSimulations.template"
