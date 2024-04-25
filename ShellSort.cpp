#include <iostream>
#include <functional>
using namespace std;
template <typename T>
int Shell_Sort(T* arr, int Size, function<bool(const T&, const T&)> lessThan)
{
	int comparisons = 0;
	for (int gap = Size / 2; gap > 0; gap /= 2)
	{
		for (int i = Size - 1; i - gap >= 0; i--)
		{
			comparisons++;
			if (lessThan(arr[i], arr[i - gap]))
			{
				T temp = arr[i];
				arr[i] = arr[i - gap];
				arr[i - gap] = temp;

			}

		}
	}
	return comparisons;
}
template <typename T>
int Shell_Sort(T* arr, int Size)
{
	function<bool(const T&, const T&)> lessThan = [](const T& t1, const T& t2)->bool { return (t1 < t2); };
	return Shell_Sort(arr, Size, lessThan);
}

