#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "deklaraceFunkce.h"
using namespace std;

int main()
{
    vector<string> timeStamps = OpenSensorData("IoTSensorData2.txt");
    
    quickSort(timeStamps, 0, timeStamps.size()-1);
    
    for (int i = 0; i < timeStamps.size(); i++) {
        cout << timeStamps[i] << endl;
    }

    return 0;
}