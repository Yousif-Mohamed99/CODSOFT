#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Task 
{
  public:
  string name;
  bool isCompleted;

  Task()
  {
    name = "";
    isCompleted = false;
  }

  Task(string name)
  {
    this->name = name;
    isCompleted = false;
  }
};


class ToDoList
{
  vector<Task> TaskList;

public:
  ToDoList(){}

  void AddTask()
  {
    string TaskName;
    int choice;

    while(true)
    {
      cout << "Enter Task Name: ";
      getline(cin, TaskName);

      if(TaskName.empty())
      {
        cout << "\nTask can't be empty, Please Enter A Valid Name.";
        continue;
      }

      bool isDuplicate = false;
      for (const Task& task : TaskList)
      {
        if (TaskName == task.name)
        {
          cout << "Task Name is Duplicated! Please Enter a new name.\n";
          isDuplicate = true;
          break;
        }
      }

      if(!isDuplicate)
      {
        TaskList.push_back(Task(TaskName));
        cout << "\n" << TaskName << " is added Sucessfully\n";
        break;
      }
    }
  }

  void RemoveTask()
  {
    string removetask;

    while(true)
    {
      cout << "Enter The Task you want to delete: ";
      getline(cin, removetask);

      auto it = find_if(TaskList.begin(), TaskList.end(), [&removetask](const Task& task)
      {
          return task.name == removetask; // Compare task name
      });

      if (it != TaskList.end()) 
      {
        TaskList.erase(it); // Remove the task
        cout << removetask << " Is removed from the list.\n";
        break;
      }
      else
      cout << "Task not found. Please check the name and try again.\n";
    }
  }


  void CompletedTask()
  {
    string TaskName;
    cout << "Enter Task Name to Mark as Completed: ";
    getline(cin, TaskName);

    for (Task& task : TaskList) 
    {
      if (task.name == TaskName) 
      {
        task.isCompleted = true;
        cout << TaskName << " Is marked as completed.\n";
        return; 
        }
    }

    cout << "\nTask not found. Please check the name and try again.\n";
  }

  void DisplayTasks()
  {
    if (TaskList.empty())
    {
      cout << "\nNo tasks available.\n";
      return;
    }

    cout << "\n-------------------------";
    cout << "\nTasks       :      Status\n";
    cout << "---------------------------\n";

    for (const Task& task : TaskList) 
    { 
        cout << task.name  << (task.isCompleted ? "             Completed" : "              Pending") << endl;
    }
}
};


int main() 
{
  ToDoList myList;
  int choice;

  cout << "\t\t\t\t\tTO-DO LIST\t\t\t\n";
  cout <<"\t\t\t------------------------------------------\t\n\n";
  do 
  {
    cout << "\n------------------";
    cout << "\n1. Add Task\n";
    cout << "\n2. Remove Task\n";
    cout << "\n3. Mark Task as Completed\n";
    cout << "\n4. View Tasks\n";
    cout << "\n5. Exit\n";
    cout << "------------------\n";
    cout << "\nEnter your choice: ";
    cin >> choice;
    cin.ignore();

  switch (choice) 
  {
    case 1:
      myList.AddTask();
      break;
    case 2:
        myList.RemoveTask();
        break;
    case 3:
        myList.CompletedTask();
        break;
    case 4:
        myList.DisplayTasks();
        break;
    case 5:
        cout << "Exiting...\n";
        break;
    default:
        cout << "Invalid choice! Please try again.\n";
  }
  } while (choice != 5);

  system("pause");
  return 0;
}