#include <functional>
using namespace std;
template <typename T>
int selectionSort(T* arr, int size)
{
	function<bool(const T&, const T&)> lessThan = [](const T& t1, const T& t2)->bool { return (t1 < t2); };
	return selectionSort(arr, size, lessThan);
}
template <typename T>
int selectionSort(T* arr, int size, function<bool(const T&, const T&)> lessThan)
{
	int comparisons = 0;
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (lessThan(arr[j],arr[min]))
			{
				min = j;
			}
			comparisons++;
		}
		swap(arr[i], arr[min]);
	}
	return comparisons;
}
