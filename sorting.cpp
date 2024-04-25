// datastr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "Student.hpp"
#include "BubbleSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"
#include "SelectionSort.cpp"
#include "ShellSort.cpp"
typedef function<bool(const Student&, const Student&)> comparerType;
using namespace std;
void sort(string name, function<int(Student*,int, comparerType)> sorter, comparerType comparer,ostream& output)
{
	int count;
	Student* students = Student::read(count);
	auto start = chrono::high_resolution_clock::now();
	int comparisons = sorter(students, count, comparer);
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	output << "Algorithm: " << name << endl << "Number of comparisons: " << comparisons << endl;
	output << "Running Time: " << duration.count() << " microseconds" << endl;
	for (int i = 0; i < count; i++)
	{
		output << students[i]; 
	}
	delete[] students;
}
void getOutput(comparerType comparer, ostream& out)
{
	sort("Selection Sort", [](Student* st, int size, comparerType c) {return selectionSort(st, size, c); }, comparer, out);
	sort("Bubble Sort", [](Student* st, int size, comparerType c) {return Bubble_Sort(st, size, c); }, comparer, out);
	sort("Shell Sort", [](Student* st, int size, comparerType c) {return Shell_Sort(st, size, c); }, comparer, out);
	sort("Merge Sort", [](Student* st, int size, comparerType c) {return mergeSort(st, size, c); }, comparer, out);
	sort("Quick Sort", [](Student* st, int size, comparerType c) {return quickSort(st, size, c); }, comparer, out);
}
int main()
{
	comparerType byName = [](const Student& s1, const Student& s2) {return s1 < s2; };
	comparerType byGpa = [](const Student& s1, const Student& s2) {return s1.getGpa() < s2.getGpa(); };
	ofstream nameF("SortedByName.txt"), gpaF("SortedByGPA.txt");
	getOutput(byName, nameF);
	getOutput(byGpa, gpaF);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
