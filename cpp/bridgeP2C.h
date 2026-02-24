#include </usr/include/python3.12/Python.h> // 
#include "csvReader.h"
#include <string> 
#include "task.h"
using namespace std;

class bridgeP2C {
    public:
    const string inputFile = "input.csv";// Change later const for testing purposes
     
    
    static void send2P(){
        queue<Task> taskQueue = ReaderCSV::getQueue("input.csv");
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

        PyObject* Py_Tuple_Args = PyTuple_Pack(5,
            PyUnicode_FromString(currentTask.function.c_str()),
            PyFloat_FromDouble(currentTask.a),
            PyFloat_FromDouble(currentTask.b),
            PyFloat_FromDouble(currentTask.x0),
            PyLong_FromLong(currentTask.numIterations)); // Creating Passable Args (function,a,b,x0,max_iterations)
            //refer to solver.py


            // How to call a function and return an array of strings and parse them back into a C variables

      



        }
        

        

        
    }
    




};
