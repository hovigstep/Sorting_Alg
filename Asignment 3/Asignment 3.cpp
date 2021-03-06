#include "stdafx.h"
#include <stdio.h>    
#include <stdlib.h>    
#include <time.h>    
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

void printFunc(int[]);
void fillFunc(int[]);
void insertionSort(int[], int);
void bubbleSort(int[], int n);
int shellSort(int[], int n);
void radixsort(int [], int n);
void quickSort(int [], int low, int high);
void mergeSort(int arr[], int l, int r);
void heapSort(int arr[], int n);

int main()
{
	int Choice;
	int MaxChoices;

	MaxChoices = 10;
	Choice = 0;

	int random[21]; //0-20 is 21 remembe array indeices
	int n = sizeof(random) / sizeof(random[0]);

	srand((unsigned)time(NULL));
	fillFunc(random);
	


	while (Choice < MaxChoices)
	{
		printf("%s\n", "************** MAIN MENU ****************");
		printf("%s\n\n", "Below Is A Randomly Generated Array of 20 Numbers");
		printFunc(random);
		printf("%s\n\n", "");
		printf("%s\n", "Please Enter one of the following Choices to Sort the Numbers");
		printf("%s\n\n", "************** MAIN MENU ****************");
		printf("%s\n\n", "1 - Insertion Sort");
		printf("%s\n\n", "2 - Bubble Sort ");
		printf("%s\n\n", "3 - Tag Sort");
		printf("%s\n\n", "4 - Shell Sort");
		printf("%s\n\n", "5 - Index Sort");
		printf("%s\n\n", "6 - Bucket Sort");
		printf("%s\n\n", "7 - Quick Sort");
		printf("%s\n\n", "8 - Merge Sort");
		printf("%s\n\n", "9 - Heap Sort ");
		printf("%s\n\n", "10: Exit The Program");
		// Print Your choices here
		scanf_s("%d", &Choice);
		switch (Choice)
		{
		case 1:
			printf("%s\n\n", " Insertion Sort In Action ");
			insertionSort(random, n);
			printFunc(random);
			printf("%s\n", "");
			break;

		case 2:
			printf("%s\n\n", " Bubble Sort In Action ");
			bubbleSort(random, n);
			printFunc(random);
			printf("%s\n", "");
			break;

		case 3:


			break;

		case 4:
			printf("%s\n\n", " Shell Sort In Action ");
			shellSort(random, n);
			printFunc(random);
			printf("%s\n", "");
			break;

		case 5:

			break;
		case 6:
			printf("%s\n\n", " Bucket Sort In Action ");
			radixsort(random, n);
			printFunc(random);
			printf("%s\n", "");
			break;
		case 7:
			printf("%s\n\n", " Not so Quicksort, Sort In Action ");
			quickSort(random, 0, n - 1);
			printFunc(random);
			printf("%s\n", "");
			break;
		case 8:
			printf("%s\n\n", " MergeSort, Sort In Action ");
			mergeSort(random, 0, n - 1);
			printFunc(random);
			printf("%s\n", "");
			break;
		case 9:
			printf("%s\n\n", " Heap Sort In Action ");
			heapSort(random, n);
			printFunc(random);
			printf("%s\n", "");
			break;

		case 10:
			return 0;
		}
	}
}


void fillFunc(int arr[])
	{
			for (int i = 1; i < 21; i++)
			{
					arr[i] = 1 + rand() % 10;
			}

	}

void printFunc(int arr[])
{
		for (int i = 1; i < 21; i++)
		{
				cout << arr[i];
		}
}

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

int shellSort(int arr[], int n)
{
	
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
	
		for (int i = gap; i < n; i += 1)
		{
			
			int temp = arr[i];

			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			arr[j] = temp;
		}
	}
	return 0;
}

int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}
void countSort(int arr[], int n, int exp)
{
	
	int i, count[10] = { 0 };
	

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

}


void radixsort(int arr[], int n)
{
	int m = getMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

void swap1(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;    
			swap1(&arr[i], &arr[j]);
		}
	}
	swap1(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

	}
}
void heapify(int arr[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1;  
	int r = 2 * i + 2; 
					
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}