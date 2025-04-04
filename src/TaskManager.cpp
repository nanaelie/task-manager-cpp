#include <iostream>
#include "TaskManager.h"

void TaskManager::addTask(int id, std::string desc, int prio) {
    tasks.push_back(Task(id, desc, prio));
}

void TaskManager::displayTasks() const {
    std::vector<Task> sortedTasks = tasks;
    std::sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& a, const Task& b) {
        return a.getPriority() < b.getPriority();
    });

    for (const auto& task : sortedTasks) {
        task.display();
    }
}

void TaskManager::removeTaskById(int id) {
    auto it = std::remove_if(tasks.begin(), tasks.end(), [id](const Task& task) {
        return task.getId() == id;
    });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        std::cout << "Task with ID " << id << " has been removed." << std::endl;
    } else {
        std::cout << "No task found with ID " << id << std::endl;
    }
}

void TaskManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& task : tasks) {
            file << task.getId() << "\n" << task.getDescription() << "\n" << task.getPriority() << "\n";
        }
        file.close();
        std::cout << "Tasks have been saved to " << filename << std::endl;
    } else {
        std::cerr << "Failed to open file for saving!" << std::endl;
    }
}

void TaskManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        int id, prio;
        std::string desc;
        while (file >> id) {
            file.ignore();
            std::getline(file, desc);
            file >> prio;
            addTask(id, desc, prio);
            file.ignore();
        }
        file.close();
        std::cout << "Tasks have been loaded from " << filename << std::endl;
    } else {
        std::cerr << "Failed to open file for loading!" << std::endl;
    }
}

