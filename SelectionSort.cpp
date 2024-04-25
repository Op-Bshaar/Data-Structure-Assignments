#include <functional>
using namespace std;
template <typename T>
void selectionSort(T* arr, int size)
{
	function<bool(const T&, const T&)> lessThan = [](const T& t1, const T& t2)->bool { return (t1 < t2); };
	selectionSort(arr, size, lessThan);
}
template <typename T>
void selectionSort(T* arr, int size, function<bool(const T&, const T&)> lessThan)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (lessThan(arr[j],arr[min]))
			{
				min = j;
			}
		}
		swap(arr[i], arr[min]);
	}
}
