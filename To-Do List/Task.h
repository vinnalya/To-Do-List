#pragma once
#include <string>

using namespace std;

class Task
{
protected:
	string description;
	int priority;
	bool isCompleted;

public:
	Task(const string& desc, int prio);
	virtual ~Task();

	void markCompleted();
	void markIncomplete();

	int getPriority() const;
	string getDescription() const;
	bool getStatus() const;

	virtual void print() const = 0;
	virtual string getType() const = 0;
};