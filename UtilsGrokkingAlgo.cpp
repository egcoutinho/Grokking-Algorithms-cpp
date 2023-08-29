#include <climits>
#include <cstring>
#include "GrokkingAlgorithms.h"

using namespace std;

//template<typename T> void PrintData(const T &data)
//{
//	auto iter = data.begin();
//	while (iter != data.end())
//		cout << *iter++ << ", ";
//	cout << endl;
//
//	return;
//}
//
//template<typename T> void PrintData(T *data, int num)
//{
//	int cnt = 0;
//	for (; cnt != num; ++cnt)
//		cout << data[cnt] << ", ";
//
//	return;
//}

int InBinarySearch(const int *array, int pos1, int pos2, int val)
{
	/* Binary Search for recursive computation */
	int pos = -1;
	int j = (pos1 + pos2) / 2;

	if (pos1 > pos2);
	else
	{
		if (val == array[j])
			pos = j;
		else 
			if (val < array[j]) 
				pos = InBinarySearch(array, pos1, j - 1, val);
		else 
			if (val > array[j])
				pos = InBinarySearch(array, j + 1, pos2, val);
	}

	return pos;
}

void SelectionSort(int *array, int num)
{
	int val = INT_MAX;
	int pos = 0;
	int j, counter = 0;
	int temp;

	while (counter != num)
	{
		val = INT_MAX;
		for (j = counter; j != num; ++j)
		{
			if (val > array[j])
			{
				val = array[j];
				pos = j;
			}
		}

		temp = array[counter];
		array[counter] = val;
		array[pos] = temp;

		++counter;
	}

	return;
}

void Merge(int *array, int num, int pos)
{
	/*
	* function for Merge Sort
	*
	* merge two arrays | [0, pos) & [pos, num)
	*/

	int *newArray = (int *)malloc(num * sizeof(int));

	int i = 0, j = pos, k = 0;

	while ((i != pos) && (j != num))
	{
		if (array[i] < array[j])
			newArray[k++] = array[i++];
		else
			newArray[k++] = array[j++];
	}

	while (i != pos)
		newArray[k++] = array[i++];
	while (j != num)
		newArray[k++] = array[j++];

	memcpy(array, newArray, num * sizeof(int));
	free(newArray);
	return;
}

std::map<std::string, int>::iterator find_lowest_cose_node(std::map < std::string, int> &cost, std::map<std::string, int> &counter)
{
	std::map<std::string, int>::iterator iter = cost.begin(), ret = cost.end();
	int minCost = INT_MAX;

	while (iter != cost.end())
	{
		if (iter->second <= minCost  && counter[iter->first] == 0)
		{
			ret = iter;
			minCost = iter->second;
		}
		++iter;
	}

	return ret;
}

