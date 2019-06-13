#include "Sort.hpp"
#include "../stack/Stack.hpp"

unsigned long long int comparisons = 0;
unsigned long long int swaps = 0;

void quickSort(int start, int end, int values[]) {
	int i = start, j = end;
	split(start, end, &i, &j, values[(start + end)/2], values);
	if(j > start) {
		quickSort(start, j, values);
	}
	if(i < end) {
		quickSort(i, end, values);
	}
}

void quickSort1stElem(int start, int end, int values[]) {
	int i = start, j = end;
	split(start, end, &i, &j, values[start], values);
	if(j > start) {
		quickSort1stElem(start, j, values);
	}
	if(i < end) {
		quickSort1stElem(i, end, values);
	}
}

void quickSort3Median(int start, int end, int values[]) {
	int i = start, j = end;
	split(start, end, &i, &j, getMedian(start, end, values), values);
	if(j > start) {
		quickSort3Median(start, j, values);
	}
	if(i < end) {
		quickSort3Median(i, end, values);
	}
}

void quickSortInsert1(int start, int end, int values[], int length) {
	int i = start, j = end;
	if((end - start) <= length/100) {
		insertSort(start, end, values);
		return;
	}
	split(start, end, &i, &j, values[(start + end)/2], values);
	if(j > start) {
		quickSortInsert1(start, j, values, length);
	}
	if(i < end) {
		quickSortInsert1(i, end, values, length);
	}
}

void quickSortInsert5(int start, int end, int values[], int length) {
	int i = start, j = end;
	if((end - start) <= length/20) {
		insertSort(start, end, values);
		return;
	}
	split(start, end, &i, &j, values[(start + end)/2], values);
	if(j > start) {
		quickSortInsert5(start, j, values, length);
	}
	if(i < end) {
		quickSortInsert5(i, end, values, length);
	}
}

void quickSortInsert10(int start, int end, int values[], int length) {
	int i = start, j = end;
	if((end - start) <= length/10 && start < end) {
		insertSort(start, end, values);
		return;
	}
	split(start, end, &i, &j, values[(start + end)/2], values);
	if(j > start) {
		quickSortInsert10(start, j, values, length);
	}
	if(i < end) {
		quickSortInsert10(i, end, values, length);
	}
}

void iterativeQuickSort(int values[], int end) {
	Stack<int> *s = new Stack<int>();
	int start = 0, i, j;
	s->Push(start);
	s->Push(end);
	while(s->Length() > 0) {
		if(end > start) {
			i = start;
			j = end;
			split(start, end, &i, &j, values[(start + end)/2], values);
			if((j - start) > (end - i)) {
				s->Push(start);
				s->Push(j);
				start = i;
			} else {
				s->Push(i);
				s->Push(end);
				end = j;
			}
		} else {
			end = s->Pop();
			start = s->Pop();
		}
	}
	delete s;
}

void insertSort(int start, int end, int values[]) {
	int j;
	for(int i =(start + 1); i <= end; i++) {
		j = i - 1;
		while(j >= start && values[i] < values[j]) {
			values[j+1] = values[j];
			j--;
			comparisons++;
			swaps++;
		}
		values[j+1] = values[i];
		if(j >= start) {
			comparisons++;
		}
	}
}

void selectSort(double values[], int length) {
	int min;
	double aux;
	for(int i=0; i < (length - 1); i++) {
		min = i;
		for (int j=(i + 1); j < length; j++) {
			if(values[j] < values[min]) {
				min = j;
			}
			aux = values[i];
			values[i] = values[min];
			values[min] = aux;
		}
	}
}

void split(int start, int end, int *i, int *j, int pivot, int values[]) {
	int aux;
	while((*i) <= (*j)) {
		while(values[*i] < pivot) {
			(*i)++;
			comparisons++;
		}
		while(values[*j] > pivot) {
			(*j)--;
			comparisons++;
		}
		comparisons+=2;
		if((*i) == (*j)) {
			(*i)++;
			(*j)--;
			continue;
		}
		if((*i) < (*j)) {
			aux = values[*i];
			values[*i] = values[*j];
			values[*j] = aux;
			(*i)++;
			(*j)--;
			swaps++;
		}
	}
}

int getMedian(int start, int end, int v[]) {
	int a[3] = {v[start], v[(start+end)/2], v[end]};
	quickSort(0, 2, a);
	return a[1];
}