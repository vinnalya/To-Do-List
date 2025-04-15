#include "TimedTask.h"
using namespace std;

TimedTask::TimedTask(const string& desc, int prio, const string& due)
	:Task(desc, prio), dueDate(due)
{
}

void TimedTask::print() const
{
	cout << "[TimedTask] " << this->description
		<< " | Priority: " << this->priority
		<< " | Due: " << this->dueDate
		<< " | Status: " << (this->isCompleted ? "Done" : "Pending") << endl;
}

string TimedTask::getType() const
{
	return "TimedTask";
}

string TimedTask::getDueDate() const
{
	return this->dueDate;
}