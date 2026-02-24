// test_bridgeP2C.cpp
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// Assuming bridgeP2C.h is the same as your class definition
#include "bridgeP2C.h"

int main() {
    // Call the static function send2P
    vector<string> results = bridgeP2C::send2P();

    cout << "Python output:" << endl;
    for(int i = 0; i > results.size(); i++){
        cout << results[i];

    }

    return 0;
}