#include <cstring>
#include <climits>
#include "GrokkingAlgorithms.h"
#include "UtilsGrokkingAlgo.h"

using namespace std;

GrokkingAlgorithm::GrokkingAlgorithm()
{

}

GrokkingAlgorithm::~GrokkingAlgorithm()
{

}

// ******************* CHAPTER 1
int GrokkingAlgorithm::Pesquisa_Binaria_Ch1(const int *lista, int num, int item)
{
	/* Binary Search
	*
	*  Params:
	*		- lista, int pointer for an ascend-sorted array
	*		- num, length of input array
	*		- item, value to be searched.
	*
	*  Out
	*		return position if found, else -1.
	*/

	/* recursive */
	//return InBinarySearch(lista, 0, num - 1, val);

	/* loop */
	int baixo = 0, pos2 = num - 1;
	int pos = -1, meio;
	while (baixo <= pos2)
	{
		meio = (baixo + pos2) / 2;
		int chute = lista[meio];

		if (item == chute)
		{
			pos = meio;
			break;
		}
		else 
			if (item < chute) pos2 = meio - 1;
		else 
			if (item > chute) baixo = meio + 1;
	}

	return pos;
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

	cout << "search result: " << GrokkingAlgorithm::Pesquisa_Binaria_Ch1(array, 12, val) << endl << endl;

	return;
}

// ******************* CHAPTER 2
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

void Ch2_SelectionSortInArray(int *array, int *sortedArray, int num)
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

void GrokkingAlgorithm::SelectionSort_Ch2(std::list<int> lst, std::list<int> &sortedLst)
{
	/* Selection Sort
	*
	*  Params:
	*		- lst, input unordered list
	*		- sortedLst, output ordered list
	*
	*  Why choose list<int> ?
	*		Fairly for quickly deleting element
	*
	*  Note:
	*		- The idea in this book is to generate a new array/list and delete the original one.
	*		- My preference is to swap data as "SelectionSort" function on the beginning of this file.
	*
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
	// test for Ch2_SelectionSortInArray(int *array, int *sortedArray, int num)
	// ======================================

	int a[5] = { 5, 2, 6, 3, 8 };
	int *b = (int *)malloc(sizeof(int) * 5);
	Ch2_SelectionSortInArray(a, b, 5);

	cout << "Original List:" << endl;
	for (int i = 0; i != 5; ++i)
	cout << a[i] << "\t";
	cout << endl << "Sorted List:" << endl;
	for (int i = 0; i != 5; ++i)
	cout << b[i] << "\t";
	cout << endl;
	free(b);
	*/

	/*
	// ======================================
	// test for SelectionSortInArray(int *array, int num) | A preferable one for me
	// ======================================

	int a[5] = { 5, 2, 6, 3, 8 };

	cout << "Original List:" << endl;
	for (int i = 0; i != 5; ++i)
	cout << a[i] << "\t";

	SelectionSort(a, 5);

	cout << endl << "Sorted List:" << endl;
	for (int i = 0; i != 5; ++i)
	cout << a[i] << "\t";
	cout << endl;
	*/

	return;
}

// ******************* CHAPTER 3
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

int GrokkingAlgorithm::Recursion_Ch3(int val)
{
	/* Recursion -- implementation of Fibonacci numbers
	*
	*  Params:
	*		- val, input nonnegetive number to generate Fibonacci number
	*
	*  Out
	*		return the computation result.
	*
	*  Note:
	*		- "Loops may achieve a performance gain for your program. Recursion may achieve a performance gain for your programmer."
	*
	*		- For Fibonacci numbers, dynamic programming (DP) is a considerable approach. This is just a demo for recursion.
	*/

	if (val <= 0)
		return 0;
	else if (val == 1)
		return 1;
	else
		return (Recursion_Ch3(val - 1) + Recursion_Ch3(val - 2));
}

// ******************* CHAPTER 4
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

int GrokkingAlgorithm::MaxSquare_Ch4(int w, int h)
{
	/*
	* ========== Max Square ==============
	*
	* solution to max square given arbitary rectangle with w width and h height.
	*
	* Params:
	*
	*		- w, width of your rectangle
	*		- h, height of youre rectangle
	*
	* Out
	*
	*		return the side length of max square
	*
	*/

	if (!((w > 0) && (h > 0)))
		return -1;

	int minL(h), maxL(w);

	if (h > w)
	{
		minL = w; maxL = h;
	}

	int res = maxL % minL;
	if (res)
		return MaxSquare_Ch4(minL, res);
	else
		return minL;
}

int GrokkingAlgorithm::Sum_Ch4(int *array, int num)
{
	/*
	* ========== Sum =====================
	*
	* solution to sum an array with D&C (divide and conquer)
	*
	* Params:
	*		- array, input integer array
	*		- num, length of array
	*
	* Out
	*		return the sum
	*
	* Note:
	*		- This is implemented with 'a[0] + sum{a[1], a[2], ...}' ---- (sum one and the others)
	*		- Another approach is with 'sum{a[0] + ... + a[m/2]} + sum{a[m/2+1], ..., a[m]}' ---- (sum one half and the other part, which is similar to Binary Search)
	*
	*		- 'Find max value of an array' is with the same idea. No coding more.
	*/

	if (num == 0)
		return 0;
	if (num == 1)
		return array[0];

	return array[0] + Sum_Ch4(&array[1], num - 1);
}

void GrokkingAlgorithm::QuickSort_Ch4(int *array, int num)
{
	/*
	* ========== Quick Sort ==============
	*
	* solution to merge sort of an integer array (ascending)
	*
	* Params:
	*		- array, intpu unordered array
	*		- num, length of array
	*
	* Out
	*		sorted ordered array
	*
	* Note
	*		- The first number of an array is selected for base value
	*		- For better illustration, a new array is created, thus inrcreasing the cost.
	*		- A more efficient version (no-creating new array) is on the below.
	*/


	/* base line */
	if (num < 2)
		return;

	int temp;
	if (num == 2)
	{
		if (array[0] > array[1])
		{
			temp = array[0];
			array[0] = array[1];
			array[1] = temp;
		}
		return;
	}

	/* D & C */
	int baseVal = array[0];


	// ========= create a new array for better understanding ============== 
	int *newArray = (int *)malloc(num * sizeof(int));

	int i = 0, j = num - 1;
	for (int k = 1; k != num; ++k)
	{
		if (baseVal < array[k])
			newArray[j--] = array[k];
		else
			newArray[i++] = array[k];
	}
	newArray[i] = baseVal;


	QuickSort_Ch4(newArray, i);
	QuickSort_Ch4(&newArray[i + 1], num - i - 1);

	memcpy(array, newArray, num * sizeof(int));
	free(newArray);


	/*
	// ========= a no-creating version ====================================
	int head = 1, tail = num - 1;
	while (head <= tail)
	{
	while ((array[tail] > baseVal) && (head <= tail)) --tail;
	if (head >= tail)
	break;

	while ((array[head] < baseVal) && (head <= tail)) ++head;
	if (head <= tail)
	{
	temp = array[tail];
	array[tail] = array[head];
	array[head] = temp;
	++head; --tail;
	}
	}

	array[0] = array[tail];
	array[tail] = baseVal;

	Ch4_QuickSort(array, tail);
	Ch4_QuickSort(&array[tail + 1], num - tail - 1);
	*/

	return;
}

void GrokkingAlgorithm::MergeSort_Ch4(int *array, int num)
{
	/*
	* ========== Merge Sort ==============
	*
	* solution to merge sort of an integer array (ascending)
	*
	* Params:
	*		- array, intpu unordered array
	*		- num, length of array
	*
	*/

	if (num < 2)
		return;

	int temp;
	if (num == 2)
	{
		if (array[0] > array[1])
		{
			temp = array[0];
			array[0] = array[1];
			array[1] = temp;
		}
		return;
	}

	int pos = num / 2;
	MergeSort_Ch4(array, pos);
	MergeSort_Ch4(&array[pos], num - pos);
	Merge(array, num, pos);

	return;
}

// ******************* CHAPTER 5
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

void GrokkingAlgorithm::HashTable_Ch5(std::map<std::string, int> &mapping)
{
	/*
	* ========== Hash Table ==============
	*
	* solution to hash table for quick search and insertion
	*
	* Params:
	*		- mapping, a map containing name (string) and age(int)
	*
	*/
	std::string input;
	int age;
	char flag;
	std::map < std::string, int>::iterator iter;

	while (true)
	{
		cout << "Input Name to Search: ('q' to quit)" << endl;
		cin >> input;

		if (input == "q")
			break;

		iter = mapping.find(input);

		if (iter == mapping.end())
		{
			cout << "No such name. \n Will you add this one? (Y/N)" << endl;
			cin >> flag;
			if (flag == 'Y')
			{
				cout << "Please input the age:" << endl;
				cin >> age;

				mapping.insert(std::pair<std::string, int>(input, age));
				cout << "Done!" << endl;
			}
			cout << endl;
			continue;
		}
		else
			cout << "Age: " << iter->second << endl << endl;
	}

	return;
}

// ******************* CHAPTER 6
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

std::pair<bool, std::string> GrokkingAlgorithm::BreadthFirstSearch_Ch6(std::map<std::string, std::vector<std::string>> &relationNet, std::set<std::string> &seller)
{
	/*
	* ========== Breadth First Search (BFS) ==============
	*
	* solution to search a specific one in your relation network with BFS
	*
	* Params:
	*		- relationNet, a map representing your personal relation network
	*		- seller, a set containing suitable person name to search
	*
	* Out:
	*		a pair of bool value representing FOUND or NOT, and a string for the person's name if FOUND
	*/


	/* creat a counter */
	std::map < std::string, int> counter;

	std::queue<std::string> search_queue;
	std::vector<std::string>::iterator iter;

	/* add your first layer relationship*/
	for (iter = relationNet["you"].begin(); iter != relationNet["you"].end(); ++iter)
	{
		search_queue.push(*iter);
	}

	/* search */
	bool flag = false;
	std::string person;
	++counter["your"];
	while (!search_queue.empty())
	{
		/* get the first one */
		person = search_queue.front();
		search_queue.pop();

		/* check if trapped in loop */
		if (counter[person])
			continue;

		/* found or not */
		if (seller.find(person) != seller.end())
		{
			flag = true;
			break;
		}
		else
		{
			++counter[person];
			for (iter = relationNet[person].begin(); iter != relationNet[person].end(); ++iter)
				search_queue.push(*iter);
		}
	}

	return std::pair < bool, std::string > {flag, person};
}

// ******************* CHAPTER 7
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

std::pair<std::vector<std::string>, int> GrokkingAlgorithm::Dijkstra_Ch7(std::map<std::string, std::map<std::string, int>> &graph)
{
	/*
	* ========== Dijkstra Algorithm ==============
	*
	* solution to Dijkstra algorithm for the shortest route between two position.
	*
	* Params:
	* 		- graph, a graph contains nodes and neighbors as well as weights
	*
	* Out:
	* 		return a pair, the first points to the route and second points to the cost.
	*
	* Note:
	* 		- Dijkstra can only handle directed acyclic graph (DAG) with non-negative side.
	*/

	/* cost map to update routine */
	std::map<std::string, int> cost;

	/* parent map to store parent node */
	std::map<std::string, std::string> parent;

	/* counter map to record processed node */
	std::map<std::string, int> counter;

	/* result */
	std::pair<std::vector<std::string>, int> ret;

	if (graph.empty())
		return ret;

	std::map<std::string, int > neighbor;
	std::map<std::string, int>::iterator iter_neighbor;

	/* initialize */
	cost["start"] = 0;

	std::map<std::string, int>::iterator iter_minCost;
	iter_minCost = find_lowest_cose_node(cost, counter);

	int costVal, prevCost;
	while (iter_minCost != cost.end())
	{
		neighbor = graph[iter_minCost->first];
		prevCost = iter_minCost->second;

		for (iter_neighbor = neighbor.begin(); iter_neighbor != neighbor.end(); ++iter_neighbor)
		{
			costVal = prevCost + iter_neighbor->second;

			/* update if have none || optimal route found */
			if (cost.find(iter_neighbor->first) == cost.end() || costVal < cost[iter_neighbor->first])
			{
				cost[iter_neighbor->first] = costVal;
				parent[iter_neighbor->first] = iter_minCost->first;
			}
		}

		++counter[iter_minCost->first];

		iter_minCost = find_lowest_cose_node(cost, counter);
	}

	/* return result */
	ret.second = cost["fin"];
	ret.first.push_back("fin");
	while (ret.first.back() != "start")
		ret.first.push_back(parent[ret.first.back()]);

	return ret;
}

// ******************* CHAPTER 8
std::set<std::string> GrokkingAlgorithm::GreedyAlgorithm_Ch8(std::set<std::string> &states_needed, std::map<std::string, std::set<std::string>> &stations)
{
	/*
	* ========== Greedy Algorithm ==============
	*
	* to find a local optimal solution with Greedy Algorithm
	*
	* Params:
	*		- states_needed, a set containing states needed to cover
	*		- stations, a map containing the states each station covers
	*
	* Out:
	*		a set of stations satisfactory the request, empty if no solution
	*/

	std::set<std::string> final_stations;
	std::set<std::string> states_covered, inter_covered;
	std::string best_station;

	std::map<std::string, std::set<std::string>>::iterator iter;
	std::set<std::string>::iterator iter_covered;

	int counter = 0;
	const int MAX_ITERATIONS = 10000;
	while (!states_needed.empty())
	{
		states_covered.clear();

		/* search for local optimal solution */
		for (iter = stations.begin(); iter != stations.end(); ++iter)
		{
			inter_covered.clear();
			std::set_intersection(states_needed.begin(), states_needed.end(), iter->second.begin(), iter->second.end(), std::inserter(inter_covered, inter_covered.begin()));

			if (inter_covered.size() > states_covered.size())
			{
				best_station = iter->first;
				states_covered = inter_covered;
			}
		}

		/* store */
		final_stations.insert(best_station);

		/* remove */
		stations.erase(best_station);
		for (iter_covered = states_covered.begin(); iter_covered != states_covered.end(); ++iter_covered)
		{
			states_needed.erase(*iter_covered); // Even if no this value. It doesn't matter
		}

		++counter;

		if (counter > MAX_ITERATIONS)
			break;
	}

	std::set<std::string> ret;

	if (counter <= MAX_ITERATIONS)
		ret = final_stations;

	return ret;
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

// ******************* CHAPTER 9
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

std::pair<int, std::set<std::string>> GrokkingAlgorithm::KnapsackProblem_Ch9(std::map<std::string, std::pair<int, int>> &info, int wt)
{
	/*
	* ========== Knapsack Problem ==============
	*
	* to find an optimal solution for Knapsack Problem
	*
	* Params:
	*		- info, a set of things' information: name (string), weight (int [0]), and its value (int [1]).
	*		- wt, the whole package weight
	*
	* Out:
	*		a pair of maximum value and its combination
	*/

	int dims = (int)info.size();

	if (dims < 1 || wt < 1)
		return std::pair < int, std::set<std::string> > { 0, std::set < std::string > {} };

	/* preparation */
	int mRows = dims + 1;
	int nCols = wt + 1;
	int i, j;
	int **table = (int **)malloc(mRows * sizeof(int *));
	for (i = 0; i != mRows; ++i)
		table[i] = (int *)malloc(nCols * sizeof(int));

	for (i = 0; i != mRows; ++i)
		for (j = 0; j != nCols; ++j)
			table[i][j] = 0;

	i = 0;
	std::vector<std::string> things(dims);
	for (auto &elem : info)
		things[i++] = elem.first;

	/* run */
	int val, weight0, value0;
	std::vector<std::set<std::string>> prevLine(nCols), currLine(nCols);
	for (i = 1; i != mRows; ++i)
	{
		weight0 = info[things[i - 1]].first;
		value0 = info[things[i - 1]].second;

		for (j = 1; j != weight0; ++j)
		{
			table[i][j] = table[i - 1][j];
			currLine[j] = prevLine[j];
		}

		for (j = weight0; j != nCols; ++j)
		{
			val = value0 + table[i - 1][j - weight0];
			if (val > table[i - 1][j])
			{
				/* update */
				table[i][j] = val;
				currLine[j] = prevLine[j - weight0];
				currLine[j].insert(things[i - 1]);
			}
			else
			{
				table[i][j] = table[i - 1][j];
				currLine[j] = prevLine[j];
			}
		}

		prevLine = currLine;
		for (auto &elem : currLine)
			elem.clear();
	}

	val = table[dims][wt];

	/* free memory */
	for (i = 0; i != dims; ++i)
		free(table[i]);
	free(table);
	
	return{ val, prevLine[wt] };
}

std::pair<int, std::string> GrokkingAlgorithm::LongestCommonSubstring_Ch9(std::string str1, std::string str2)
{
	/*
	* ========== Longest Common Substring ==============
	*
	* solution to find the longest common substring
	*
	* Params:
	*		- str1 | str2, two strings 
	*
	* Out:
	*		a pair of length and the corresponding substring
	*/

	int m = (int)str1.size() + 1, n = (int)str2.size() + 1;

	if (std::min<int>(m, n) < 2)
		return{ 0, "" };

	std::vector<std::vector<int>> table(m, std::vector<int>(n, 0));

	/* construct table */
	int i, j;
	for (i = 1; i != m; ++i)
		for (j = 1; j != n; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
				table[i][j] = table[i - 1][j - 1] + 1;
			else
				table[i][j] = 0;
		}

	/* find maximum */
	int val = 0;
	int pos = 0;
	for (i = 1; i != m; ++i)
		for (j = 1; j != n; ++j)
		{
			if (val < table[i][j])
			{
				val = table[i][j];
				pos = i - 1;
			}
		}

	return{ val, str1.substr(pos - val + 1, val) };
}

int GrokkingAlgorithm::LongestCommonSubsequence_Ch9(std::string str1, std::string str2)
{
	/*
	* ========== Longest Common Subsequence ==============
	*
	* solution to find the length of longest common subsequence
	*
	* Params:
	*		- str1 | str2, two strings
	*
	* Out:
	*		a length of the longest subsequence
	*/

	int m = (int)str1.size() + 1, n = (int)str2.size() + 1;

	if (std::min<int>(m, n) < 2)
		return 0;

	std::vector<std::vector<int>> table(m, std::vector<int>(n, 0));

	/* construct table */
	int i, j;
	for (i = 1; i != m; ++i)
		for (j = 1; j != n; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
				table[i][j] = table[i - 1][j - 1] + 1;
			else
				table[i][j] = std::max<int>(table[i - 1][j], table[i][j - 1]);
		}

	return table[m - 1][n - 1];
}