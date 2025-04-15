#include "SearchAlgorithms.h"
#include <algorithm> 


string toLower(const string& str) {
	string result = str;
	transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}

namespace SearchAlgorithms {

	int binarySearchByDescription(const vector<Task*>& tasks, const string& desc) {
		int left = 0, right = tasks.size() - 1;
		string target = toLower(desc);
		while (left <= right) {
			int mid = left + (right - left) / 2;
			string current = toLower(tasks[mid]->getDescription());

			if (current == target)
				return mid;
			else if (current < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}

	int linearSearchByDescription(const vector<Task*>& tasks, const string& desc) {
		string target = toLower(desc);
		for (int i = 0; i < tasks.size(); ++i) {
			string current = toLower(tasks[i]->getDescription());
			if (current.find(target) != string::npos) // partial + insensitive
				return i;
		}
		return -1;
	}
}
