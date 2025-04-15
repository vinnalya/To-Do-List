#pragma once
#include "Task.h"
#include <iostream>
using namespace std;
class TimedTask : public Task {
private:
	string dueDate;

public:
	TimedTask(const string& desc, int prio, const string& due);
	void print() const override;
	string getType() const override;
	string getDueDate() const;
};
