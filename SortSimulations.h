//Name: Neidy Malaga and Vivian Huynh
//Date: 11/29/2023
//Description: Header file for template class SortSimulations

#pragma
#include <iostream>  //For cout
#include <iomanip>   //For formatting output
#include <vector>    //For vector
#include <random>    //For randomizing values
#include <algorithm> //For swap and other member functions
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
	//CONSTRUCTOR
	SortSimulations();

	//MUTATORS
	void set_Array(int);
	void set_sort_array();
	void bubble_sort_recurse(size_t, bool (*compare_func)(T, T));
	void selection_sort_recurse(size_t, bool (*compare_func)(T, T));
	void insertion_sort_recurse(size_t, bool (*compare_func)(T, T));
	void sort_heap_recurse(size_t, bool (*compare_func)(T, T));
	void merge(size_t, size_t, size_t, bool (*compare_func)(T, T));
	void mergesort(size_t, size_t, bool (*compare_func)(T, T));
	void quick_sort(size_t, size_t, bool (*compare_func)(T, T));
	void reset_Count();
	void displayUnsorted();

	//ACCESSORS
	bool is_Empty() const;
	size_t get_Size() const;
	static bool greater_compare(T, T);
	static bool lesser_compare(T, T);
	T partition(size_t, size_t, bool(compare_func(T, T)));

	template <typename T>
	friend ostream& operator<< (ostream&, const SortSimulations<T>&);
};

#include "SortSimulations.template"
