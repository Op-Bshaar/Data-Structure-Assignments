#include<functional>
using namespace std;

template <typename T>
void mergeSort(T* arr,int size)
{
	function<bool(const T&, const T&)> lessThan = [](const T& t1, const T& t2)->bool { return (t1 < t2); };
		mergeSort(arr, size, lessThan);
}
template <typename T>
void mergeSort(T* arr,int size, function<bool(const T&,const T&)> lessThan)
{
	mergeSort(arr, 0, size - 1, lessThan);
}
template <typename T>
void mergeSort(T* arr,int begin, int end,function<bool(const T&, const T&)> lessThan)
{
	if (begin >= end)
	{
		return;
	}
	int mid = begin + (end - begin) / 2;
	mergeSort(arr, begin, mid,lessThan);
	mergeSort(arr, mid + 1, end, lessThan);
	merge(arr, begin, mid, end, lessThan);
}
template <typename T>
void merge(T*arr,int begin, int mid,int end, function<bool(const T&, const T&)> lessThan)
{
	int lsize = mid - begin + 1;
	int rsize = end - mid;
	T* left = new T[lsize];
	T* right = new T[rsize];
	for (int i = 0; i < lsize; i++)
	{
		left[i] = arr[begin + i];
	}
	for (int i = 0; i < rsize; i++)
	{
		right[i] = arr[mid + i + 1];
	}
	int ileft = 0, iright = 0, i = begin;
	while (ileft < lsize && iright < rsize)
	{
		if (lessThan(right[iright], left[ileft]))
		{
			arr[i] = right[iright];
			iright++;
		}
		else
		{
			arr[i] = left[ileft];
			ileft++;
		}
		i++;
	}
	for (;ileft < lsize; ileft++,i++)
	{
		arr[i] = left[ileft];
	}
	for (; iright < rsize; iright++, i++)
	{
		arr[i] = right[iright];
	}
	delete[] left;
	delete[] right;
}