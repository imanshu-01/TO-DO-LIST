#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task {
public:
    string name;

    Task(const string& name) : name(name) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask() {
        string taskName;
        cout << "Enter task name: ";
        cin.ignore();
        getline(cin, taskName);
        tasks.emplace_back(taskName);
        cout << "Task added successfully!" << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks available!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].name << endl;
        }
    }

    void deleteTask() {
        if (tasks.empty()) {
            cout << "No tasks to delete!" << endl;
            return;
        }
        viewTasks();
        cout << "Enter the task number to delete: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted successfully!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }

    void displayMenu() {
        cout << "\n---------- To-Do List Menu -----------\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "-----------------------------------------\n";
    }

    void run() {
        int choice;
        do {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                cout << "Exiting program. Bye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!" << endl;
            }
        } while (choice != 4);
    }
};

int main() {
    ToDoList toDoList;
    toDoList.run();
    return 0;
}