#include <iostream>
#include <vector>
using namespace std;

void displayMenu() {
    cout << "\nWelcome to the To-Do-List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Delete Task\n";
    cout << "5. Exit\n";
    cout << "Enter option: ";
}

int main() {
    int option, index;
    string Task;
    vector<string> Tasks;

    while (true) {  // Infinite loop until user chooses to exit
        displayMenu();
        cin >> option;
        cin.ignore(); // Clear newline character from input buffer

        if (option == 1) {
            // Add Task
            cout << "Enter Task: ";
            getline(cin, Task);
            Tasks.push_back(Task);
            cout << "Task added successfully!\n";
        }
        else if (option == 2) {
            // View Tasks
            if (Tasks.empty()) {
                cout << "Your to-do list is empty.\n";
            } else {
                cout << "Your Tasks:\n";
                for (int i = 0; i < Tasks.size(); i++) {
                    cout << i + 1 << ". " << Tasks[i] << endl;
                }
            }
        }
        else if (option == 3) {
            // Mark Task as Completed (removes task)
            if (Tasks.empty()) {
                cout << "No tasks to mark as completed.\n";
            } else {
                cout << "Enter task number to mark as completed: ";
                cin >> index;
                if (index > 0 && index <= Tasks.size()) {
                    cout << "Task \"" << Tasks[index - 1] << "\" completed!\n";
                    Tasks.erase(Tasks.begin() + index - 1);
                } else {
                    cout << "Invalid task number.\n";
                }
            }
        }
        else if (option == 4) {
            // Delete Task
            if (Tasks.empty()) {
                cout << "No tasks to delete.\n";
            } else {
                cout << "Enter task number to delete: ";
                cin >> index;
                if (index > 0 && index <= Tasks.size()) {
                    cout << "Task \"" << Tasks[index - 1] << "\" deleted!\n";
                    Tasks.erase(Tasks.begin() + index - 1);
                } else {
                    cout << "Invalid task number.\n";
                }
            }
        }
        else if (option == 5) {
            // Exit program
            cout << "Goodbye! Your tasks will be lost since we don't save them yet.\n";
            break;
        }
        else {
            cout << "Invalid option! Please choose a valid number (1-5).\n";
        }
    }

    return 0;
}
