#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#pragma once

vector<string> OpenSensorData(string nazev);

//void selectSortVect(vector<string>& vektor);

int partition(vector<string>& arr, int low, int high);

void quickSort(vector<string>& arr, int low, int high);


