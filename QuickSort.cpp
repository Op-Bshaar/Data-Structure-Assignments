#include<functional>
using namespace std;

template <typename T>
void quickSort(T* arr, int size)
{
	function<bool(const T&, const T&)> lessThan = [](const T& t1, const T& t2)->bool { return (t1 < t2); };
	quickSort(arr, size, lessThan);
}
template <typename T>
void quickSort(T* arr, int size, function<bool(const T&, const T&)> lessThan)
{
	quickSort(arr, 0, size - 1, lessThan);
}
template <typename T>
void quickSort(T* arr, int begin,int end, function<bool(const T&, const T&)> lessThan)
{
	if (begin >= end)
	{
		return;
	}
	int p = partition(arr, begin, end, lessThan);
	quickSort(arr, begin, p - 1, lessThan);
	quickSort(arr, p + 1, end, lessThan);
}
template <typename T>
int partition(T* arr, int begin, int end, function<bool(const T&, const T&)> lessThan)
{
	int pivot_index = begin;
	T pivot = arr[pivot_index];
	int i = begin;
	for (int j = begin; j <= end; j++)
	{
		if (lessThan(arr[j], pivot))
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i], arr[pivot_index]);
	return i;
}