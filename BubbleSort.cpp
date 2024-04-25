#include <functional>
using namespace std;

//function<bool(const Student&, const Student&)> byGpa = [](const Student& s1, const Student& s2) {return s1.getGpa() < s2.getGpa(); };
//Bubble_Sort(students, size,byGpa);
template <typename T>
void Bubble_Sort(T* arr, int Size)
{
	function<bool(const T&, const T&)> lessThan = [](const T& t1, const T& t2)->bool { return (t1 < t2); };

	Bubble_Sort(arr, Size, lessThan);
}
template <typename T>
void Bubble_Sort(T* arr, int Size, function<bool(const T&, const T&)> lessThan)
{
	for (int i = Size; i >= 0; i--)
	{
		for (int j = 1; j < i; j++)
		{
			if (lessThan(arr[j], arr[j - 1]))
			{
				T temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}