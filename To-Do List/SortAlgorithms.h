#pragma once
#include "Task.h"
#include <vector>
using namespace std;

namespace SortAlgorithms {
	void mergeSort(vector<Task*>& tasks, bool ascending = true);
	void insertionSort(vector<Task*>& tasks, bool ascending = true);
	void countingSort(vector<Task*>& tasks); 
}
