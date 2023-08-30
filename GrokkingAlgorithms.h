#ifndef GROKKING_ALGORITHM_H_
#define GROKKING_ALGORITHM_H_

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>

class GrokkingAlgorithm
{
public:
	GrokkingAlgorithm();
	~GrokkingAlgorithm();

	void runDemoChapter_1();
	void runDemoChapter_2();
	void runDemoChapter_3();
	void runDemoChapter_4();
	void runDemoChapter_5();
	void runDemoChapter_6();
	void runDemoChapter_7();
	void runDemoChapter_8();
	void runDemoChapter_9();

private:
	int Pesquisa_Binaria_Ch1(const int *lista, int tamanho, int item);
	int InBinarySearch(const int *array, int pos1, int pos2, int val);
	void SelectionSort_Ch2(std::list<int> lst, std::list<int> &sortedLst);
	int Recursion_Ch3(int val);
	int MaxSquare_Ch4(int w, int h);
	int Sum_Ch4(int *array, int num);
	void QuickSort_Ch4(int *array, int num);
	void MergeSort_Ch4(int *array, int num);
	void Merge(int *array, int num, int pos);
	void HashTable_Ch5(std::map<std::string, int> &mapping);
	std::pair<bool, std::string> BreadthFirstSearch_Ch6(std::map<std::string, std::vector<std::string>> &relationNet, std::set<std::string> &seller);
	std::pair<std::vector<std::string>, int> Dijkstra_Ch7(std::map<std::string, std::map<std::string, int>> &graph);
	std::map<std::string, int>::iterator find_lowest_cose_node(std::map < std::string, int> &cost, std::map<std::string, int> &counter);
	std::set<std::string> GreedyAlgorithm_Ch8(std::set<std::string> &states_needed, std::map<std::string, std::set<std::string>> &stations);
	std::pair<int, std::set<std::string>> KnapsackProblem_Ch9(std::map<std::string, std::pair<int, int>> &info, int wt);
	std::pair<int, std::string> LongestCommonSubstring_Ch9(std::string str1, std::string str2);
	int LongestCommonSubsequence_Ch9(std::string str1, std::string str2);
};

template<typename T> void PrintData(const T &data)
{
	auto iter = data.begin();
	while (iter != data.end())
		std::cout << *iter++ << ", ";
	std::cout << std::endl;

	return;
}

template<typename T> void PrintData(T *data, int num)
{
	int cnt = 0;
	for (; cnt != num; cnt++)
		std::cout << data[cnt] << ", ";
	std::cout << std::endl;
	return;
}

#endif