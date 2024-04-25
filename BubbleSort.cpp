#include <iostream>
#include <functional>
using namespace std;
template <typename T>
void Bubble_Sort(T* arr, int Size)
{
	function<bool(const T&, const T&)> lessThan = [](const T& t1, const T& t2)->bool { return (t1 < t2); };

	Bubble_Sort(arr, Size, lessThan);
}
template <typename T>
void Bubble_Sort(T* arr, int Size, function<bool(const T&, const T&)> lessThan)
{
	for (int i = Size;i >=0;i--)
	{
		for (int j = 1; j < i; j++)
		{
			if (!lessThan(arr[j - 1], arr[j]))
			{
				T temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}