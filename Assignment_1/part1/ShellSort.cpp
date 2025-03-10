#include <iostream>
#include <functional>
using namespace std;
template <typename T>
int Shell_Sort(T* arr, int Size, function<bool(const T&, const T&)> lessThan)
{
	int comparisons = 0;
	for (int gap = Size / 2; gap > 0; gap /= 2)
	{
	    for (int i = 0; i+ gap <Size; i++)
	    {
		    for (int j = 0; j+ gap <Size; j+=gap)
		        {
			    comparisons++;
			    if (lessThan(arr[j + gap],arr[j]))
			    {
				    
				    T temp = arr[j];
				    arr[j] = arr[j + gap];
				    arr[j + gap] = temp;

			    }
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
