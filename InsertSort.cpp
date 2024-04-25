#include <iostream>
#include <functional>
using namespace std;
template <typename T>
int Insert_Sort(T* arr, int Size, function<bool(const T&, const T&)> lessThan)
{
	int comparisons = 0;
	for (int i = 1; i < Size; i++)
	{
		bool flag = false;
		T value = arr[i];
		int temp = 0;
		for (int j = i - 1; j >= 0 && !lessThan(arr[j], value); j--)
		{
			comparisons++;
			arr[j + 1] = arr[j];
			temp = j;
			flag = true;
		}
		if (flag == true)
		{
			arr[temp] = value;
		}

	}
	return comparisons;
}
template <typename T>
int Insert_Sort(T* arr, int Size)
{
	function<bool(const T&, const T&)> lessThan = [](const T& t1, const T& t2)->bool { return (t1 < t2); };
	return Insert_Sort(arr, Size, lessThan);
}