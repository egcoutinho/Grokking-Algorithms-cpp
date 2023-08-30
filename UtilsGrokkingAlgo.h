#ifndef __UTILSGROKKING_ALGO_H__
#define __UTILSGROKKING_ALGO_H__
#include <map>
#include <string>

//int InBinarySearch(const int *array, int pos1, int pos2, int val);
//void SelectionSort(int *array, int num);
//void Merge(int *array, int num, int pos);

std::map<std::string, int>::iterator find_lowest_cose_node(std::map < std::string, int> &cost, std::map<std::string, int> &counter);

#endif //__UTILSGROKKING_ALGO_H__