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
void quickSort(T* arr, int bigen,int end, function<bool(const T&, const T&)> lessThan)
{
	if (begin >= end)
	{
		return;
	}
	int p = pivot(arr, begin, end, lessThan);
	quickSort(arr, begin, p - 1, lessThan);
	quickSort(arr, p + 1, end, lessThan);
}
template <typename T>
int pivot(T* arr, int bigen, int end, function<bool(const T&, const T&)> lessThan)
{
	return 0;
}