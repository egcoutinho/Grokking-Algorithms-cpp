#include "GrokkingAlgorithm.h"

using namespace std;

GrokkingAlgorithm::GrokkingAlgorithm()
{

}

GrokkingAlgorithm::~GrokkingAlgorithm()
{

}

void GrokkingAlgorithm::runDemoChapter_1()
{
	// ========= demo Chapter 1 -- Binary Search =========
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	cout << "\n =========================" << endl
		 <<   " Demo for Chapter 1 -- Binary Search " << endl
		 <<   " =========================" << endl;

	cout << "Original Data : " << endl;
	PrintData(array, 12);

	cout << "Input an integer for search: " << endl;

	int val = 0;
	cin >> val;

	cout << "search result: " << GrokkingAlgorithm::BinarySearch_Ch1(array, 12, val) << endl << endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_2()
{
	cout << "\n =========================" << endl
		 << " Demo for Chapter 2 -- Selection Sort " << endl
		 << " =========================" << endl;

	std::list<int> lst = { 5, 3, 6, 2, 10 };
	std::list<int> sortedLst;

	GrokkingAlgorithm::SelectionSort_Ch2(lst, sortedLst);

	cout << "Original List:" << endl;
	PrintData(lst);

	cout << "Sorted List:" << endl;
	PrintData(sortedLst);
	cout << endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_3()
{
	cout << "\n =========================" << endl
		<< " Demo for Chapter 3 -- Recursion " << endl
		<< " =========================" << endl;

	int num;
	cout << "Input an integer for Fibonacci number generation(no more than 20 is preferable):  ";
	cin >> num;
	cout << endl << "Fibonacci (" << num << ") is " << GrokkingAlgorithm::Recursion_Ch3(num) << endl << endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_4()
{
	cout << "\n =========================" << endl
		<< " Demo for Chapter 4 -- Quick Sort " << endl
		<< " =========================" << endl;

	/* Max Square */
	cout << endl << "solution for Max Square " << endl;
	cout << "Input two integers for width and height of a rectangle: " << endl;

	int  w, h;
	cin >> w >> h;
	cout << "side length of the max square: " << GrokkingAlgorithm::MaxSquare_Ch4(w, h) << endl;

	/* Sum */
	cout << endl << "solution for Sum " << endl;

	int array[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << "Original Data: ";
	PrintData(array, 9);

	cout << "The sum is: " << GrokkingAlgorithm::Sum_Ch4(array, 9) << endl;

	/* Quick Sort */
	cout << endl << "solution for Quick Sort " << endl;
	int unorderedArray[11] = { 25, 6, 1, 3, 8, 10, 52, 30, 15, 0, 55 };
	cout << "Original Data: " << endl;
	PrintData(unorderedArray, 11);

	GrokkingAlgorithm::QuickSort_Ch4(unorderedArray, 11);
	cout << "ordered array:" << endl;
	PrintData(unorderedArray, 11);

	/* Merge Sort */
	cout << endl << "solution for Merge Sort " << endl;
	int unorderedArray2[12] = { 5, 6, 100, 1, 3, 8, 10, 52, 30, 15, 0, 55 };
	cout << "Original Data: " << endl;
	PrintData(unorderedArray2, 12);

	GrokkingAlgorithm::MergeSort_Ch4(unorderedArray2, 12);
	cout << "ordered array:" << endl;
	PrintData(unorderedArray2, 12);
	cout << endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_5()
{
	cout << "\n =========================" << endl
		<< " Demo for Chapter 5 -- Hash Table " << endl
		<< " =========================" << endl;

	cout << "Initialize a map | <name, age>" << endl;

	std::map<std::string, int> mapping{ { "Allen", 32 }, { "Bob", 22 }, { "Alice", 28 } };
	std::map < std::string, int>::iterator iter;

	cout << "Map is initialized as follows:" << endl;
	for (iter = mapping.begin(); iter != mapping.end(); ++iter)
		cout << "Name: " << iter->first << ",\tAge: " << iter->second << endl;

	GrokkingAlgorithm::HashTable_Ch5(mapping);
	cout << "\nAll in map are as follows:" << endl;
	for (iter = mapping.begin(); iter != mapping.end(); ++iter)
		cout << "Name: " << iter->first << ",\tAge: " << iter->second << endl;
	cout << endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_6()
{
	cout << "\n =========================" << endl
		<< " Demo for Chapter 6 -- Breadth First Search (BFS) " << endl
		<< " =========================" << endl;

	cout << "initialize a personal relationship network by hash map" << endl;
	std::map<std::string, std::vector<std::string>> relationNet{ { "you", { "alice", "bob", "claire" } },
	{ "bob", { "anuj", "peggy" } }, { "alice", { "peggy" } }, { "claire", { "thom", "jonny" } },
	{ "anuj", {} }, { "peggy", {} }, { "thom", { "you" } }, { "jonny", {} } };

	/* assume the right one */
	std::set<std::string> seller{ "jonny", "doggy", "catty" };

	std::pair<bool, std::string> ret = GrokkingAlgorithm::BreadthFirstSearch_Ch6(relationNet, seller);

	if (ret.first)
		cout << "FOUND!" << endl << ret.second << " is a seller!" << endl << endl;
	else
		cout << "Not FOUND !" << endl << endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_7()
{
	cout << "\n =========================" << endl
		<< " Demo for Chapter 7 -- Dijkstra Algorithm " << endl
		<< " =========================" << endl;

	std::map<std::string, std::map<std::string, int>> graph1, graph2, graph3, graph4, graph5;

	/* graph 1 */
	graph1["start"]["a"] = 5;
	graph1["start"]["b"] = 0;
	graph1["a"]["c"] = 15;
	graph1["a"]["d"] = 20;
	graph1["b"]["c"] = 30;
	graph1["b"]["d"] = 35;
	graph1["c"]["fin"] = 20;
	graph1["d"]["fin"] = 10;

	/* graph 2 */
	graph2["start"]["A"] = 6;
	graph2["start"]["B"] = 2;
	graph2["A"]["fin"] = 1;
	graph2["B"]["A"] = 3;
	graph2["B"]["fin"] = 5;

	/* graph 3 */
	graph3["start"]["b"] = 5;
	graph3["start"]["c"] = 2;
	graph3["b"]["d"] = 4;
	graph3["b"]["e"] = 2;
	graph3["c"]["b"] = 8;
	graph3["c"]["e"] = 7;
	graph3["d"]["fin"] = 3;
	graph3["d"]["e"] = 6;
	graph3["e"]["fin"] = 1;

	/* graph 4 */
	graph4["start"]["b"] = 10;
	graph4["b"]["d"] = 20;
	graph4["d"]["c"] = 1;
	graph4["c"]["b"] = 1;
	graph4["d"]["fin"] = 30;

	/* graph 5 */
	/* This is a cyclic graph with negative side, no more Dijkstra */
	graph5["start"]["b"] = 2;
	graph5["start"]["d"] = 2;
	graph5["d"]["b"] = 2;
	graph5["b"]["fin"] = 2;
	graph5["b"]["e"] = 2;
	graph5["e"]["d"] = -5;
	graph5["e"]["fin"] = 2;

	std::map<std::string, int> fin;
	graph1["fin"] = graph2["fin"] = graph3["fin"] = graph4["fin"] = graph5["fin"] = fin;

	std::pair<std::vector<std::string>, int> ret1, ret2, ret3, ret4, ret5;
	ret1 = GrokkingAlgorithm::Dijkstra_Ch7(graph1);
	ret2 = GrokkingAlgorithm::Dijkstra_Ch7(graph2);
	ret3 = GrokkingAlgorithm::Dijkstra_Ch7(graph3);
	ret4 = GrokkingAlgorithm::Dijkstra_Ch7(graph4);
	ret5 = GrokkingAlgorithm::Dijkstra_Ch7(graph5);


	size_t i = 0, dims;
	std::vector<std::string>::iterator iter;

	dims = ret1.first.size();
	cout << "Shortest route:" << endl;
	for (iter = ret1.first.begin(); i < dims - 1; ++i, ++iter)
		cout << *iter << " <- ";
	cout << *iter << endl << "Shortest distance:\t" << ret1.second << endl << endl;

	dims = ret2.first.size();
	cout << "Shortest route:" << endl;
	for (iter = ret2.first.begin(); i < dims - 1; ++i, ++iter)
		cout << *iter << " <- ";
	cout << *iter << endl << "Shortest distance:\t" << ret2.second << endl << endl;

	dims = ret3.first.size();
	cout << "Shortest route:" << endl;
	for (iter = ret3.first.begin(); i < dims - 1; ++i, ++iter)
		cout << *iter << " <- ";
	cout << *iter << endl << "Shortest distance:\t" << ret3.second << endl << endl;

	dims = ret4.first.size();
	cout << "Shortest route:" << endl;
	for (iter = ret4.first.begin(); i < dims - 1; ++i, ++iter)
		cout << *iter << " <- ";
	cout << *iter << endl << "Shortest distance:\t" << ret4.second << endl << endl;

	dims = ret5.first.size();
	cout << "Shortest route:" << endl;
	for (iter = ret5.first.begin(); i < dims - 1; ++i, ++iter)
		cout << *iter << " <- ";
	cout << *iter << endl << "Shortest distance:\t" << ret5.second << endl << endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_8()
{
	cout << "\n =========================" << endl
		 << " Demo for Chapter 8 -- GreedyAlgorithm " << endl
		 << " =========================" << endl;

	/* prepare data */
	std::set<std::string> states_needed = { "mt", "wa", "or", "id", "nv", "ut", "ca", "az" };
	std::map<std::string, std::set<std::string>> stations;
	stations["kone"] = std::set < std::string > { "id", "nv", "ut" };
	stations["ktwo"] = std::set < std::string > {"wa", "id", "mt"};
	stations["kthree"] = std::set < std::string > {"or", "nv", "ca"};
	stations["kfour"] = std::set < std::string > {"nv", "ut"};
	stations["kfive"] = std::set < std::string > {"ca", "az"};

	std::set<std::string> ret = GrokkingAlgorithm::GreedyAlgorithm_Ch8(states_needed, stations);
	if (!ret.empty())
	{
		cout << "Solution FOUND!" << endl;
		for (auto &elem : ret)
			cout << elem << ", ";
		cout << endl << endl;
	}
	else
		cout << "No Solution!" << endl << endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_9()
{
	cout << "\n =========================" << endl
		<< " Demo for Chapter 9 -- Dynamic Programming " << endl
		<< " =========================" << endl;

	/* Knapsack Problem */
	int wt = 5;
	std::map<std::string, std::pair<int, int> > info
	{ { "Guitar", { 1, 1500 } }, { "Stereo", { 4, 3000 } },
	{ "Laptop", { 3, 2000 } }, { "Iphone", { 1, 2000 } } };

	std::pair<int, std::set<std::string>> ret = KnapsackProblem_Ch9(info, wt);
	cout << "\nStealing things for value maximum" << endl
		<< "The solution for Knapsack Problem with weight of " << wt << ":" << endl;
	cout << "The maximum of value is:  $ " << ret.first << endl << "The optimal solution is:  ";
	for (auto iter = ret.second.begin(); iter != ret.second.end(); ++iter)
		cout << *iter << ", ";
	cout << endl << endl;

	int wt2 = 6;
	std::map<std::string, std::pair<int, int>> info2
	{ { "Water", { 3, 10 } }, { "Book", { 1, 3 } }, { "Food", { 2, 9 } },
	{ "Jacket", { 2, 5 } }, { "Camera", { 1, 6 } } };

	std::pair<int, std::set<std::string>> ret2 = KnapsackProblem_Ch9(info2, wt2);
	cout << "Taking things to travel for value maximum" << endl
		<< "The solution for Knapsack Problem with weight of " << wt2 << ":" << endl;
	cout << "The maximum of value is:  $ " << ret2.first << endl << "The optimal solution is:  ";
	for (auto iter = ret2.second.begin(); iter != ret2.second.end(); ++iter)
		cout << *iter << ", ";
	cout << endl << endl;

	/* Longest Common Substring */
	std::string str1("fished"), str2("abfisabshezzishecaahed");
	std::pair<int, std::string> lcs = GrokkingAlgorithm::LongestCommonSubstring_Ch9(str1, str2);

	cout << "Find the Longest Common Substring" << endl;
	cout << "Input two strings as : \"" << str1 << "\" & \"" << str2 << "\"" << endl;
	cout << "The Longest Common Substring is:  \"" << lcs.second << "\"" << endl;
	cout << "The length is :  " << lcs.first << endl << endl;

	/* Longest Common Subsequence */
	std::string str3("fosh"), str4("fish");
	int len = GrokkingAlgorithm::LongestCommonSubsequence_Ch9(str3, str4);

	cout << "Find the Longest Common Subsequence" << endl;
	cout << "Input two strings as : \"" << str3 << "\" & \"" << str4 << "\"" << endl;
	cout << "The length of Longest Common Substring is:  " << len << endl << endl;

	return;
}
