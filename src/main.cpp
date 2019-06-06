#include <chrono>
#include <iostream>
#include <sstream>
#include <string>
#include "sort/Sort.hpp"
#include "stack/Stack.hpp"

using std::cout;
using std::endl;
using std::stringstream;

using namespace std::chrono;

void callQuickSort(int paramsLen, char *params[]);
int *getValues(char *orderType, int size);
void printValues(stringstream *ss, int *values, int length);

void prepareQuickSortTest(char *method, char *orderType, int size, bool showValues);
void callQuickSort(char *method, int *values, int size);

extern unsigned long long comparisons;
extern unsigned long long swaps;

string QC = "QC";
string QM3 = "QM3";
string QPE = "QPE";
string QI1 = "QI1";
string QI5 = "QI5";
string QI10 = "QI10";
string QNR = "QNR";

string ALE = "Ale";
string ORDC = "OrdC";
string ORDD = "OrdD";

int main(int paramsLen, char *params[]) {
	// if (paramsLen < 4) {
	// 	return 0;
	// }
	bool showValues = false;
	if(paramsLen > 4) {
		showValues = true;
	}
	int size = atoi(params[3]);
	if(size < 1) {
		return 0;
	}
	cout << params[1] << " " << params[2] << " " << params[3] << " ";
	prepareQuickSortTest(params[1], params[2], size, showValues);
	// callQuickSort(paramsLen, params);
	int a[10] = {10, 3, 9, 4, 8, 2, 7, 6, 5, 1};
	// iterativeQuickSort(a, 9);
	// quickSort(0, 9, a);
	// quickSort1stElem(0, 9, a);
	// cout << endl;
	// for(int i =0; i<10; i++) {
	// 	cout << a[i] << " ";
	// }
	return 0;
}

void callQuickSort(char *method, int *values, int size) {
	if(QC.compare(method) == 0) {
		quickSort(0, size-1, values);
		return;
	}
	if(QM3.compare(method) == 0) {
		quickSort3Median(0, size-1, values);
		return;
	}
	if(QPE.compare(method) == 0) {
		quickSort1stElem(0, size-1, values);
		return;
	}
	if(QI1.compare(method) == 0) {
		quickSortInsert1(0, size-1, values, size);
		return;
	}
	if(QI5.compare(method) == 0) {
		quickSortInsert5(0, size-1, values, size);
		return;
	}
	if(QI10.compare(method) == 0) {
		quickSortInsert10(0, size-1, values, size);
		return;
	}
	if(QNR.compare(method) == 0) {
		iterativeQuickSort(values, size-1);
	}
}

void prepareQuickSortTest(char *method, char *arrayOrder, int size, bool showValues) {
	int *values;
	double times[20];
	stringstream testValues;
	for(int i=0; i<20; i++) {
		values = getValues(arrayOrder, size);
		if(values == nullptr) {
			return;
		}
		cout << "COMP " << comparisons << endl;
		printValues(&testValues, values, size);
		high_resolution_clock::time_point startTime = high_resolution_clock::now();
		callQuickSort(method, values, size);
		high_resolution_clock::time_point endTime = high_resolution_clock::now();
		duration<double, std::micro> elapsedTime = duration_cast<duration<double>>(endTime - startTime);
		times[i] = elapsedTime.count();
		delete values;
	}
	selectSort(times, 20);
	cout << comparisons/20 << " " << swaps/20 << " " << (times[9]+times[10])/2 << endl;
	if(showValues) {
		cout << testValues.str();
	}
}

int *getValues(char *orderType, int size) {
	int *values = new int[size];
	if(ALE.compare(orderType) == 0) {
		for(int i=0; i<size; i++) {
			values[i] = rand();
		}
		return values;
	}
	if(ORDC.compare(orderType) == 0) {
		for(int i=0; i<size; i++) {
			values[i] = i;
		}
		return values;
	}
	if(ORDD.compare(orderType) == 0) {
		for(int i=size; i>=0; i--) {
			values[i] = i;
		}
		return values;
	}
	return nullptr;
}

void printValues(stringstream *ss, int *values, int length) {
	for(int i=0; i<length; i++) {
		*ss << values[i] << "  ";
	}
	*ss << endl;
}