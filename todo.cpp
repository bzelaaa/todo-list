#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Task {
    string description;
    bool completed;
};

// NEW: Save tasks to a file
void saveTasks(vector<Task>& tasks) {
    ofstream file("tasks.txt");
    for (int i = 0; i < tasks.size(); i++) {
        file << tasks[i].completed << "\n";
        file << tasks[i].description << "\n";
    }
    file.close();
    cout << "Tasks saved!" << endl;
}

// NEW: Load tasks from a file
void loadTasks(vector<Task>& tasks) {
    ifstream file("tasks.txt");
    if (!file.is_open()) {
        cout << "No saved tasks found. Starting fresh!" << endl;
        return;
    }
    tasks.clear();
    Task t;
    string completedStr;
    while (getline(file, completedStr)) {
        t.completed = (completedStr == "1");
        getline(file, t.description);
        tasks.push_back(t);
    }
    file.close();
    cout << "Tasks loaded!" << endl;
}

void displayTasks(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks yet!" << endl;
        return;
    }
    cout << "\n=== Your To-Do List ===" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        string status = tasks[i].completed ? "[X]" : "[ ]";
        cout << i + 1 << ". " << status << " " << tasks[i].description << endl;
    }
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added!" << endl;
}

void completeTask(vector<Task>& tasks) {
    displayTasks(tasks);
    cout << "Enter task number to mark complete: ";
    int num;
    cin >> num;
    if (num < 1 || num > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }
    tasks[num - 1].completed = true;
    cout << "Task marked as complete!" << endl;
}

void deleteTask(vector<Task>& tasks) {
    displayTasks(tasks);
    cout << "Enter task number to delete: ";
    int num;
    cin >> num;
    if (num < 1 || num > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }
    tasks.erase(tasks.begin() + num - 1);
    cout << "Task deleted!" << endl;
}

int main() {
    vector<Task> tasks;
    int choice;

    cout << "=== To-Do List App ===" << endl;

    // NEW: Load tasks automatically when program starts
    loadTasks(tasks);

    while (true) {
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. View tasks" << endl;
        cout << "2. Add task" << endl;
        cout << "3. Complete task" << endl;
        cout << "4. Delete task" << endl;
        cout << "5. Save tasks" << endl;
        cout << "6. Quit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) displayTasks(tasks);
        else if (choice == 2) addTask(tasks);
        else if (choice == 3) completeTask(tasks);
        else if (choice == 4) deleteTask(tasks);
        else if (choice == 5) saveTasks(tasks);
        else if (choice == 6) {
            saveTasks(tasks); // NEW: auto-save on quit
            cout << "Goodbye!" << endl;
            break;
        }
        else cout << "Invalid choice, try again." << endl;
    }

    return 0;
}