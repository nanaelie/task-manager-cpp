#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <vector>
#include <algorithm>
#include <fstream>

class TaskManager {
  private:
    std::vector<Task> tasks;

  public:
    void addTask(int id, std::string desc, int prio);
    void displayTasks() const;
    void removeTaskById(int id);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif

