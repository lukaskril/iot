#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/// <summary>
/// Funkce která otevøe daný textový soubor a každý øádek (namìøenou hodnotu IoT senzoru) zapíše do vectoru typu string.
/// </summary>
/// <param name="fileName"> Parametr ve kterém je uložen název souboru, používám ho k doplnìní cesty k souboru a pro jeho následné otevøení. </param>
/// <returns> Funkce vrací vector typu string ve kterém jsou uloženy hodnoty mìøení IoT senzoru. </returns>
vector<string> OpenSensorData(string fileName) {

	ifstream OpenedDataFile;
	string path = "..\\Data\\" + fileName;
	string dataBatch;
	vector<string> timeStamps;
	int numOfLines = 0;
	OpenedDataFile.open(path);
	
	if (OpenedDataFile.is_open()) {
		while (!OpenedDataFile.eof()) {
			getline(OpenedDataFile, dataBatch);
			if (OpenedDataFile.fail()) {
				continue;
			}
			timeStamps.push_back(dataBatch);
			numOfLines++;
		}
	}
	else {
		cout << "Soubor se nepodaøilo naèíst" << endl;
	}
	
	OpenedDataFile.close();

	cout << timeStamps.size() << endl;
	cout << endl;
	return timeStamps;
}

/*void selectSortVect(vector<string>& vektor) {
	int filesize = vektor.size();
	for (int i = 0; i < filesize - 2; i++) {
		int min = i;
		for (int j = i; j < filesize - 1; j++) {
			if (vektor[j] < vektor[min]) {
				min = j;
			}
		}
		swap(vektor[i], vektor[min]);
	}
}*/

/// <summary>
/// 
/// </summary>
/// <param name="arr"></param>
/// <param name="low"></param>
/// <param name="high"></param>
/// <returns></returns>

int partition(vector<string>& arr, int low, int high) {
	string pivot = arr[high]; // Choose the rightmost element as the pivot  
	int i = (low - 1);        // Initialize the index of the smaller element  

	for (int j = low; j < high; j++) {
		// If the current element is smaller than or equal to the pivot  
		if (arr[j] <= pivot) {
			i++; // Increment the index of the smaller element  
			swap(arr[i], arr[j]);
		}
	}

	// Swap the pivot element with the element at index i+1  
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

/// <summary>
/// 
/// </summary>
/// <param name="arr"></param>
/// <param name="low"></param>
/// <param name="high"></param>

void quickSort(vector<string>& arr, int low, int high) {
	if (low < high) {
		// Find pivot such that elements smaller than pivot are on the left  
		// and elements greater than pivot are on the right  
		int pi = partition(arr, low, high);

		// Recursively sort the elements before and after partition  
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

