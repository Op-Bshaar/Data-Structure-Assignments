#include <iostream>
using namespace std;
template <typename T>
void Bubble_Sort(T arr[], int Size)
{
	for (int i=0;i<Size-1;i++)
	{
		int temp = 0;
		for(int j =i+1;j<Size;j++)
		{
		if(arr[j-1]>arr[j])
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		}
	}
}