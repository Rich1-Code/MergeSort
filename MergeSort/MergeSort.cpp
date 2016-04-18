// MergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void merge(int*,int,int);
void mergeSort(int *, int, int, int);

int _tmain(int argc, _TCHAR* argv[])
{
	int count;
	int* a;
	cout << "请输入你将要输入排序数字的个数:";
	cin >> count;

	a = new int[count];
	cout << "请输入你将要排序的数字:";

	for (int i = 0; i < count; i++)
	{
		cin >> a[i];
	}
	merge(a, 0, count-1);

	for (int i = 0; i < count; i++)
	{
		cout<< a[i] <<' ';
	}
	system("pause");
	return 0;
}

void merge(int* sort,int first, int last)
{
	int mid = 0;
	if (first + 1 < last)
	{
		mid = (first + last) / 2; 
		merge( sort,  first, mid);
		merge(sort,  mid + 1, last);
		mergeSort(sort, first, last, mid);
	}
	else 
	{
		if (sort[first] > sort[last])
		{
			int temp = sort[first];
			sort[first] = sort[last];
			sort[last] = temp;
		}
	}
	
}

void mergeSort(int* sort, int first, int last, int mid)
{
	int i, j, m ,l, k;
	i = first;
	j = mid + 1;
	l = last;
	k = 0;
	m = mid;
	int* temp = new int[last + 1 - first];
	while (i <= m && j <= l)
	{
		if (sort[i] < sort[j])
		{
			temp[k++] = sort[i++];
		}
		else
		{
			temp[k++] = sort[j++];
		}
	}
	while (i <= m)
	{
		temp[k++] = sort[i++];
	}
	while (j <= l)
	{
		temp[k++] = sort[j++];
	}
	for (i = 0; i < k; i++)
	{
		sort[first + i] = temp[i];
	}
}
