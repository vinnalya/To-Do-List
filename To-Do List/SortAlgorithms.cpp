#include "SortAlgorithms.h"

namespace SortAlgorithms {

	void merge(vector<Task*>& tasks, int left, int mid, int right, bool ascending) {
		int n1 = mid - left + 1;
		int n2 = right - mid;

		vector<Task*> L(n1), R(n2);

		for (int i = 0; i < n1; i++)
			L[i] = tasks[left + i];
		for (int j = 0; j < n2; j++)
			R[j] = tasks[mid + 1 + j];

		int i = 0, j = 0, k = left;
		while (i < n1 && j < n2) {
			bool comp = ascending ?
				L[i]->getPriority() <= R[j]->getPriority() :
				L[i]->getPriority() >= R[j]->getPriority();

			tasks[k++] = comp ? L[i++] : R[j++];
		}

		while (i < n1)
			tasks[k++] = L[i++];
		while (j < n2)
			tasks[k++] = R[j++];
	}

	void mergeSort(vector<Task*>& tasks, int left, int right, bool ascending) {
		if (left < right) {
			int mid = left + (right - left) / 2;
			mergeSort(tasks, left, mid, ascending);
			mergeSort(tasks, mid + 1, right, ascending);
			merge(tasks, left, mid, right, ascending);
		}
	}

	void mergeSort(vector<Task*>& tasks, bool ascending) {
		if (!tasks.empty())
			mergeSort(tasks, 0, tasks.size() - 1, ascending);
	}

	void insertionSort(vector<Task*>& tasks, bool ascending) {
		for (int i = 1; i < tasks.size(); ++i) {
			Task* key = tasks[i];
			int j = i - 1;
			while (j >= 0 && (
				ascending ? tasks[j]->getPriority() > key->getPriority()
				: tasks[j]->getPriority() < key->getPriority())) {
				tasks[j + 1] = tasks[j];
				j--;
			}
			tasks[j + 1] = key;
		}
	}

	void countingSort(vector<Task*>& tasks) {
		const int MAX = 11;
		vector<vector<Task*>> buckets(MAX);

		for (Task* task : tasks) {
			int prio = task->getPriority();
			if (prio >= 0 && prio < MAX)
				buckets[prio].push_back(task);
		}

		int idx = 0;
		for (int i = 0; i < MAX; ++i) {
			for (Task* t : buckets[i])
				tasks[idx++] = t;
		}
	}
}
