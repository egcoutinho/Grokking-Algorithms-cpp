#include "GrokkingAlgorithm.h"

namespace GrokkingAlgorithm
{
	void SelectionSort(int *array, int *sortedArray, int num)
	{
		/* Selection Sort for array rather than list
		*  
		*  Params:
		*		- array, int pointer for input unordered array
		*		- sortedArray, int pointer for output ordered array
		*		- num, length of array
		*
		*  NOTE:
		*		MAKE SURE these's enough malloc memory for output sortedArray.
		*/

		int *temp = (int *)malloc(sizeof(int)*num);
		memcpy(temp, array, sizeof(int)*num);

		int val = INT_MAX;
		int pos = 0;
		int counter = num;
		int j;

		while (counter)
		{
			val = INT_MAX;
			for (j = 0; j != num; ++j)
			{
				if (val > temp[j])
				{
					val = temp[j];
					pos = j;
				}
			}

			temp[pos] = INT_MAX;
			sortedArray[num - counter--] = val;
		}

		free(temp);

		return;
	}

	void Ch2_SelectionSort(std::list<int> lst, std::list<int> &sortedLst)
	{
		/* Selection Sort
		*
		*  Params:
		*		- lst, input unordered list
		*		- sortedLst, output ordered list
		*  
		*  Why choose list<int> ?
		*		Fairly for quickly deleting element
		*/

		int val;
		std::list<int>::iterator iter_min;
		std::list<int>::iterator iter;

		while (lst.begin() != lst.end())
		{
			val = INT_MAX;
			for (iter = lst.begin(); iter != lst.end(); ++iter)
			{
				if (val > *iter)
				{
					val = *iter;
					iter_min = iter;
				}
			}
			sortedLst.push_back(val);
			lst.erase(iter_min);
		}

		/* 
		// ====================================== 
		// test for SelectionSort(int *array, int *sortedArray, int num)
		// ======================================

		int a[5] = { 5, 2, 6, 3, 8 };
		int *b = (int *)malloc(sizeof(int) * 5);
		SelectionSort(a, b, 5);

		std::cout << "Original List:" << std::endl;
		for (int i = 0; i != 5; ++i)
		std::cout << a[i] << "\t";
		std::cout << std::endl << "Sorted List:" << std::endl;
		for (int i = 0; i != 5; ++i)
		std::cout << b[i] << "\t";
		std::cout << std::endl;
		free(b);
		*/

		return;
	}
}