#include <iostream>
using namespace std;
template <typename T>
void Insert_Sort(T arr[],int Size)
{
	for (int i = 1; i < Size; i++)
	{
		bool flag = false;
		int value = arr[i];
		int temp=0;
		for (int j = i - 1; j >= 0 && arr[j] > value; j--)
		{
			arr[j + 1] = arr[j];
			temp = j;
			flag = true;
		}
		if(flag==true)	
			{arr[temp] = value;}

	}
}