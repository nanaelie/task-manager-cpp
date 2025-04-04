#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

class Task {
  private:
    int id;
    std::string description;
    int priority;

  public:
    Task(int _id, const std::string& _desc, int _prio); // Constructeur

    int getId() const;           // Déclaration de getId()
    std::string getDescription() const;  // Déclaration de getDescription()
    int getPriority() const;     // Déclaration de getPriority()

    void display() const;        // Déclaration de display()
};

#endif

