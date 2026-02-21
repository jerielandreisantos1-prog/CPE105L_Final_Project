#include <iostream>
#include <queue>

#include "csvReader.h"

using namespace std;

int main(){
    cout << "===== CSV Reader Tester =====" << endl;
    cout << endl;

    // Read CSV file into queue
    queue<Task> taskQueue = ReaderCSV::getQueue("CSV/input.csv");

    // Check if queue is empty
    if (taskQueue.empty()){
        cerr << "Error: Task queue is empty!" << endl;
        return 1;
    }

    cout << "Successfully loaded " << taskQueue.size() << " tasks" << endl;
    cout << endl;

    // Display all tasks
    int taskNumber = 1;
    while (!taskQueue.empty()){
        Task task = taskQueue.front();
        taskQueue.pop();

        cout << "Task #" << taskNumber << ":" << endl;
        cout << "  Function: " << task.function << endl;
        cout << "  a: " << task.a << endl;
        cout << "  b: " << task.b << endl;
        cout << "  x0: " << task.x0 << endl;
        cout << "  Method: " << task.method << endl;
        cout << "  Iterations: " << task.numIterations << endl;
        cout << endl;

        taskNumber++;
    }

    cout << "===== Test Complete =====" << endl;

    return 0;
}
