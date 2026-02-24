#include </usr/include/python3.12/Python.h> // 
#include "csvReader.h"
#include <string> 
#include <vector>
using namespace std;

class bridgeP2C {
    public:
    const string inputFile = "input.csv";// Change later const for testing purposes
     
    
    static vector<string> send2P(){
        queue<Task> taskQueue = ReaderCSV::getQueue("input.csv");
        vector<string> cStringOutput;
        cStringOutput.reserve(7);
        Py_Initialize();
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append('../Py')");
        PyObject *moduleName = PyUnicode_FromString("solver");
        PyObject *pythonModule = PyImport_Import(moduleName);
        Py_DECREF(moduleName);

        

        while(!taskQueue.empty()){
        Task currentTask = taskQueue.front();
        taskQueue.pop();
        PyObject *methodObject = PyObject_GetAttrString(pythonModule, currentTask.function.c_str());
        //imports the file solver.py and the necessary method used

        
        PyObject* result = PyObject_CallMethod(
            pythonModule,
            currentTask.method.c_str(), 
            currentTask.function.c_str(),
            currentTask.a, 
            currentTask.b, 
            currentTask.x0, 
            currentTask.numIterations);
        

        for(int i = 0; i < 7; i++){
            PyObject *item = PyList_GetItem(result, i);
            if(PyUnicode_Check(item)){
                cStringOutput.push_back(PyUnicode_AsUTF8(item)); 
            } else{
                cStringOutput.push_back("Error: Not UniCode");
            }
        }

        
            
        }
        return cStringOutput;
         
    }


};
