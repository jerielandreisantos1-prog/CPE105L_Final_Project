#include <C:\Program Files\Python314\include\Python.h> 
#include "csvReader.h"
#include <string> 
#include "task.h"
using namespace std;

class bridgeP2C {
    public:
    const string inputFile = "input.csv";// Change later const for testing purposes
    const queue<Task> taskQueue = ReaderCSV::getQueue(inputFile); 
    




};
