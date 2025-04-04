#include "TaskManager.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    TaskManager manager;
    manager.loadFromFile("tasks.txt");

    int choice;
    
    do {
        cout << "1. Add new tasks with priority" << endl;
        cout << "2. Remove tasks by ID" << endl;
        cout << "3. Display tasks sorted by priority" << endl;
        cout << "4. Save and load tasks" << endl;
        cout << "5. Quitter" << endl;
        cout << "Enter your choice: ";
        
        while (!(cin >> choice) || choice < 1 || choice > 5) {
            cout << "Invalid choice. Please enter a number between 1 and 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1: {
                int id, prio;
                string desc;
                cout << "Enter task ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter task description: ";
                getline(cin, desc);
                cout << "Enter task priority (1-low, 2-medium, 3-high): ";
                cin >> prio;
                manager.addTask(id, desc, prio);
                break;
            }

            case 2: {
                int id;
                cout << "Enter task ID to remove: ";
                cin >> id;
                manager.removeTaskById(id);
                break;
            }

            case 3:
                manager.displayTasks();
                break;

            case 4: {
                int fileChoice;
                cout << "1. Save tasks to file" << endl;
                cout << "2. Load tasks from file" << endl;
                cout << "Enter your choice: ";
                cin >> fileChoice;
                
                if (fileChoice == 1) {
                    manager.saveToFile("tasks.txt");
                } else if (fileChoice == 2) {
                    manager.loadFromFile("tasks.txt");
                }
                break;
            }

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

