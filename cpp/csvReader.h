#include <fstream>
#include <string>
#include <queue>
#include "task.h"
#include <iostream>
#include <sstream>

using namespace std;





class ReaderCSV {


public:
    static queue<Task> getQueue(string inputFile){
    

    ifstream file(inputFile);
    string line;
    queue<Task> taskQueue;
    string token;
    if (!file.is_open()){
        cerr << "failed to open File:" << inputFile << endl;
        return taskQueue;
    }

    getline(file, line); // Reads the Header of the input.CSV

    while (getline(file, line)){
        stringstream ss(line);
        Task task;
        string token;
        int columnIndex = 0;

        while (getline(ss, token, ',')){
            switch(columnIndex){
                case 0: task.function = token; break;
                case 1: task.a = stod(token); break;
                case 2: task.b = stod(token); break;
                case 3: task.x0 = stod(token); break;
                case 4: task.method = token; break;
                case 5: task.numIterations = stoi(token); break;
            }
            columnIndex++;
        }

        taskQueue.push(task);
    }

    file.close();
    return taskQueue;

    }

};

