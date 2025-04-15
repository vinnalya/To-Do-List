#pragma once
#include "Task.h"
#include <vector>
#include <string>
using namespace std;

namespace SearchAlgorithms {
	int binarySearchByDescription(const vector<Task*>& tasks, const string& desc);
	int linearSearchByDescription(const vector<Task*>& tasks, const string& desc);
}
