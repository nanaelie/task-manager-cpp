#include "Task.h"

Task::Task(int _id, const std::string& _desc, int _prio)
    : id(_id), description(_desc), priority(_prio) {}

int Task::getId() const {
    return id;
}

std::string Task::getDescription() const {
    return description;
}

int Task::getPriority() const {
    return priority;
}

void Task::display() const {
    std::cout << "ID: " << id << " | " 
              << "Description: " << description << " | "
              << "Priority: " << (priority == 1 ? "Low" : (priority == 2 ? "Medium" : "High")) << std::endl;
}

