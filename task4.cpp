#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure to hold task details
struct Task {
    string name;
    bool completed;
};

class TodoList {
private:
    vector<Task> tasks;

public:
    // Function to add a new task
    void addTask(const string& taskName) {
        Task newTask;
        newTask.name = taskName;
        newTask.completed = false;
        tasks.push_back(newTask);
    }

    // Function to mark a task as completed
    void completeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    // Function to remove a task
    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    // Function to display all tasks
    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].name;
                if (tasks[i].completed) {
                    cout << " (Completed)";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    TodoList todoList;
    int choice;

    do {
        cout << "\nTodo List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Complete Task\n";
        cout << "3. Remove Task\n";
        cout << "4. Display Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskName;
                cout << "Enter task name: ";
                cin.ignore();
                getline(cin, taskName);
                todoList.addTask(taskName);
                break;
            }
            case 2: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todoList.completeTask(index - 1);
                break;
            }
            case 3: {
                int index;
                cout << "Enter task index to remove: ";
                cin >> index;
                todoList.removeTask(index - 1);
                break;
            }
            case 4:
                todoList.displayTasks();
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
