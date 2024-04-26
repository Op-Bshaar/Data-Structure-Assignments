#include<functional>
using namespace std;

template <typename T>
int quickSort(T* arr, int size)
{
	function<bool(const T&, const T&)> lessThan = [](const T& t1, const T& t2)->bool { return (t1 < t2); };
	return quickSort(arr, size, lessThan);
}
template <typename T>
int quickSort(T* arr, int size, function<bool(const T&, const T&)> lessThan)
{
	return quickSort(arr, 0, size - 1, lessThan);
}
template <typename T>
int quickSort(T* arr, int begin,int end, function<bool(const T&, const T&)> lessThan)
{
	if (begin >= end)
	{
		return 0;
	}
	int comparisons = 0;
	int p = partition(arr, begin, end, lessThan, comparisons);
	return comparisons +
		quickSort(arr, begin, p - 1, lessThan) +
		quickSort(arr, p + 1, end, lessThan);
}
template <typename T>
int partition(T* arr, int begin, int end, function<bool(const T&, const T&)> lessThan,int& comparisons)
{
	int pivot_index = begin;
	T pivot = arr[pivot_index];
	int i = begin;
	for (int j = begin; j <= end; j++)
	{
		comparisons++;
		if (lessThan(arr[j], pivot))
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i], arr[pivot_index]);
	return i;
}