#ifndef SORT_H
#define SORT_H

#include<iostream>

using std::cout;
using std::endl;

void quickSort(int start, int end, int values[]);
void quickSort1stElem(int start, int end, int values[]);
void quickSort3Median(int start, int end, int values[]);
void quickSortInsert1(int start, int end, int values[], int length);
void quickSortInsert5(int start, int end, int values[], int length);
void quickSortInsert10(int start, int end, int values[], int length);
void iterativeQuickSort(int values[], int end);
void insertSort(int values[], int length);
void selectSort(double values[], int length);
void split(int start, int end, int *i, int *j, int pivot, int values[]);
int getMedian(int start, int end, int v[]);

#endif