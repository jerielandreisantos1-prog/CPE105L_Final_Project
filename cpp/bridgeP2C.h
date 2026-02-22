#include <C:\Program Files\Python314\include\Python.h> 
#include "csvReader.h"
#include <string> 
#include "task.h"
using namespace std;

class bridgeP2C {
    public:
    const string inputFile = "input.csv";// Change later const for testing purposes
    const queue<Task> taskQueue = ReaderCSV::getQueue(inputFile);
    
    static void send2P(){
        Py_Initialize();
        PyObject* pName = PyUnicode_FromString("numericalMethod");
        PyObject* pModule = PyImport_Import(pName);
        Py_DECREF(pName);

        PyObject* pClass = PyObject_GetAttrString(pModule, "numericalMethod");

        

        

        
    }
    




};
