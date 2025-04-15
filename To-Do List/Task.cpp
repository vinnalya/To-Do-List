#include "Task.h"
#include <iostream>

Task::Task(const string& desc, int prio)
	:description(desc), priority(prio), isCompleted(false)
{
}

Task::~Task()
{
}

void Task::markCompleted()
{
	this->isCompleted = true;
}

void Task::markIncomplete()
{
	this->isCompleted = false;
}

int Task::getPriority() const
{
	return this->priority;
}

string Task::getDescription() const
{
	return this->description;
}

bool Task::getStatus() const
{
	return this->isCompleted;
}
