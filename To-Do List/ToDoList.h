#pragma once
#pragma once
#include "Task.h"
#include <vector>
using namespace std;

class ToDoList {
private:
	vector<Task*> tasks;

public:
	~ToDoList();
	void addTask(Task* task);
	void removeTask(int index);
	void markTaskCompleted(int index);
	void listTasks() const;

	vector<Task*>& getTaskList();
};
