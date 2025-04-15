#include "ToDoList.h"
#include <iostream>
using namespace std;

ToDoList::~ToDoList()
{
	for (Task* task : this->tasks)
	{
		delete task;
	}
}

void ToDoList::addTask(Task* task)
{
	this->tasks.push_back(task);
}

void ToDoList::removeTask(int index)
{
	if (index >= 0 && index < this->tasks.size())
	{
		delete this->tasks[index];
		this->tasks.erase(this->tasks.begin() + index);
	}
}

void ToDoList::markTaskCompleted(int index)
{
	if (index >= 0 && index < this->tasks.size())
	{
		this->tasks[index]->markCompleted();
	}
}

void ToDoList::listTasks() const
{
	for (int i = 0; i < this->tasks.size(); ++i)
	{
		cout << i << ". ";
		this->tasks[i]->print();
	}
}

vector<Task*>& ToDoList::getTaskList()
{
	return this->tasks;
}
