#include "ToDoList.h"
#include "TimedTask.h"
#include "SortAlgorithms.h"
#include "SearchAlgorithms.h"
#include <iostream>
using namespace std;

void printMenu() {
	cout << "\n===== TO-DO LIST MENU =====\n";
	cout << "1. Add a new task\n";
	cout << "2. Show all tasks\n";
	cout << "3. Mark a task as completed\n";
	cout << "4. Remove a task\n";
	cout << "5. Sort tasks by priority (MergeSort)\n";
	cout << "6. Search for a task by description (Linear Search)\n";
	cout << "0. Exit\n";
	cout << "Enter your choice: ";
}

int main() {
	ToDoList list;
	int choice;

	while (true) {
		printMenu();
		cin >> choice;

		if (choice == 0) {
			cout << "Goodbye!\n";
			break;
		}

		switch (choice) {
		case 1: {
			string desc, due;
			int prio;
			cout << "Enter task description: ";
			cin.ignore();
			getline(cin, desc);
			cout << "Enter priority (0-10): ";
			cin >> prio;
			cout << "Enter due date (e.g., 2025-04-30): ";
			cin >> due;
			list.addTask(new TimedTask(desc, prio, due));
			cout << "Task added successfully.\n";
			break;
		}
		case 2:
			cout << "\n--- Task List ---\n";
			list.listTasks();
			break;
		case 3: {
			int id;
			cout << "Enter task ID to mark as completed: ";
			cin >> id;
			list.markTaskCompleted(id);
			cout << "Task marked as completed.\n";
			break;
		}
		case 4: {
			int id;
			cout << "Enter task ID to remove: ";
			cin >> id;
			list.removeTask(id);
			cout << "Task removed.\n";
			break;
		}
		case 5:
			SortAlgorithms::mergeSort(list.getTaskList());
			cout << "Tasks sorted by priority.\n";
			break;
		case 6: {
			string keyword;
			cout << "Enter description to search: ";
			cin.ignore();
			getline(cin, keyword);
			int index = SearchAlgorithms::linearSearchByDescription(list.getTaskList(), keyword);
			if (index != -1) {
				cout << "Task found at index " << index << ":\n";
				list.getTaskList()[index]->print();
			}
			else {
				cout << "Task not found.\n";
			}
			break;
		}
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	}

	return 0;
}
