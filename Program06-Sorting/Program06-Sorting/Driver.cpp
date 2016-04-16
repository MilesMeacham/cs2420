// Author: Miles Meacham
// Date: 04/05/2016
// Contents: AVL Tree


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <dos.h>

using namespace std;

// Global variable to count which file is being
int fileCount = 1;

// InsertionSort function
// Purpose: Sort an array using insertionshort algorithm
// Parameter: none
// Return: void
int * InsertionSort(int* arr, int size)
{
	// Variables
	int x;
	int temp;


	for (int i = 0; i < size; i++)
	{
		x = i;

		// while you haven't reached the beginning of the array and the right value is less than the left
		while (x > 0 && arr[x] < arr[x - 1])
		{
			// swap the two values
			temp = arr[x];
			arr[x] = arr[x - 1];
			arr[x - 1] = temp;
			x--;
		}


	}

	return arr;

}

// ShellSort function
// Purpose: Sort an array using shellsort algorithm
// Parameter: none
// Return: void
int * ShellSort(int* arr, int size)
{
	// Variables
	int x;
	int temp;
	int increment = size;
	bool flag = true;

	// If flag is false or increment is less than one stop
	while (flag || increment > 1)
	{
		// change the increment and set flag to false
		increment = (increment / 3) + 1;
		flag = false;

		
		for (int i = 0; i < size - increment; i++)
		{
			// if the right value is less than the left value swap them
			if (arr[i + increment] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[i + increment];
				arr[i + increment] = temp;
				i += increment;

				// Set flag to true because something changed
				flag = true;
			}
		}
	}

	return arr;
}

// quicksortHelper function
// Purpose: Picks a pivot and puts everything smaller than the pivot below and everything bigger above
// Parameter: int*, int, int
// Return: int
int quicksortHelper(int *arr, const int left, const int right) {

	// Variables
	const int mid = left + (right - left) / 2;
	const int pivot = arr[mid];

	// Swap the pivot with the first value in the array
	swap(arr[mid], arr[left]);

	// increment the left so it doesn't equal the pivot
	int x = left + 1;
	int y = right;

	// while the left is less than or equal to the right side
	// this is not the value in the array but the address
	while (x <= y) 
	{
		// if left = the right side stop
		// if the value in the address of the left is greater than the pivot stop
		while (x <= y && arr[x] <= pivot) 
			x++;
		
		// if right = the left side stop
		// if the value in the address of the right is less than the pivot stop
		while (x <= y && arr[y] > pivot)
			y--;
		
		// if the left side is bigger than the right side, swap them
		if (x < y)
			swap(arr[x], arr[y]);

	}

	// after everything is done, put the pivot inbetween the two sides
	swap(arr[x - 1], arr[left]);

	// return the pivot
	return x - 1;
}

// quicksort function
// Purpose: Use the quicksort algorithm to sort the array
// Parameter: int*, int, int, int
// Return: int*
int * quicksort(int* arr, const int left, const int right, const int size)
{
	// If the left and the right are the same then you have reached the end
	if (left >= right)
		return arr;

	// Call the quicksortHelper function
	int partition = quicksortHelper(arr, left, right);
	
	// Call quicksort recursively for the left and right sides of the pivot
	quicksort(arr, left, partition - 1, size);
	quicksort(arr, partition + 1, right, size);

	return arr;
}

// countDataInFile function
// Purpose: Counts how many elements are in the file
// Parameter: string
// Return: int
int countDataInFile(string filePath)
{
	// Variables
	int data;
	int size;

	// Open the file
	ifstream myFileSize(filePath.c_str());

	// Test to see if the file was able to be opened
	if (!myFileSize)
	{
		cout << "There was an Error opening file :" << filePath << endl;

		system("PAUSE");
		return -1;
	}

	myFileSize >> data;
	size = 0;

	// For each peice of data in the file
	while (!myFileSize.eof())
	{
		size++;				// Increment the count
		myFileSize >> data; // grab the next piece of data
	}
	myFileSize.close();  // Close the file

	return size;
}

// sort function
// Purpose: Passes the arrays to each of the sort functions and then outputs the results
// Parameter: int*, int
// Return: void
void sort(int* arrayToSort, int size)
{
	// Variables
	clock_t start;
	clock_t end;
	clock_t elapsed_clock;
	clock_t elapsed_time;
	char fileName[64];
	ofstream outFile;

	// Get initial tick
	start = clock();

	// call the insertionSort function
	int * insertionArray = InsertionSort(arrayToSort, size);

	// Get ending tick
	end = clock();

	// Figure out the time it took.
	elapsed_clock = end - start;
	elapsed_time = ((end - start) / CLK_TCK);


	// Create out file name
	sprintf_s(fileName, "I%d.txt", fileCount);

	// Open the file to output the data
	outFile.open(fileName);

	// Save the data to the file
	for (int y = 0; y < size; y++)
		outFile << insertionArray[y] << endl;
	
	// Close the file
	outFile.close();

	// Print the info out
	cout << setw(10) << left << "Insertion" <<
		setw(8) << left << fileCount <<
		setw(15) << left << size <<
		setw(15) << left << elapsed_clock <<
		setw(15) << left << elapsed_time <<
		setw(15) << left << fileName << endl;


	// Get initial tick
	start = clock();

	// Call the shellSort function
	int * shellSortArray = ShellSort(arrayToSort, size);

	// Get ending tick
	end = clock();

	// Figure out time it took
	elapsed_clock = end - start;
	elapsed_time = ((end - start) / CLK_TCK);

	// Create new out file name
	sprintf_s(fileName, "S%d.txt", fileCount);

	// Open out file
	outFile.open(fileName);

	// Save data to file
	for (int y = 0; y < size; y++)
		outFile << shellSortArray[y] << endl;

	// Close outfile
	outFile.close();

	// print out the data.
	cout << setw(10) << left << "Shellsort" <<
		setw(8) << left << fileCount <<
		setw(15) << left << size <<
		setw(15) << left << elapsed_clock <<
		setw(15) << left << elapsed_time <<
		setw(15) << left << fileName << endl;



	// Get initial tick
	start = clock();

	// Call quicksort function
	int * quicksortedArray = quicksort(arrayToSort, 0, size - 1, size);

	// Get ending tick
	end = clock();

	// Figure out the time it took to run function
	elapsed_clock = end - start;
	elapsed_time = ((end - start) / CLK_TCK);

	// Create new out file name
	sprintf_s(fileName, "Q%d.txt", fileCount);

	// open the outfile
	outFile.open(fileName);

	// save data to file
	for (int y = 0; y < size; y++)
		outFile << quicksortedArray[y] << endl;
	
	// Close file
	outFile.close();

	// Output the info
	cout << setw(10) << left << "QuickSort" <<
		setw(8) << left << fileCount <<
		setw(15) << left << size <<
		setw(15) << left << elapsed_clock <<
		setw(15) << left << elapsed_time <<
		setw(15) << left << fileName << endl;

	cout << endl;

	// Increment global file count
	fileCount++;

}

// sortFile function
// Purpose: makes an array with the data from the file and sends it to the sort function
// Parameter: string (filePath)
// Return: void
void sortFile(string filePath)
{
	int data;

	// Get the size that the array will need to be
	int size = countDataInFile(filePath);
	
	// Declare a new array with the size
	int *myArray = new int[size];

	// Open the file
	ifstream myFile(filePath.c_str());

	// Test to see if the file was able to be opened
	if (!myFile)
	{
		cout << "There was an Error opening file " << filePath << endl;

		system("PAUSE");
		return;
	}

	myFile >> data;
	int n = 0;

	// For each peice of data in the file
	while (!myFile.eof())
	{
		myArray[n] = data;
		myFile >> data; // grab the next piece of data

		n++;
	}

	myFile.close();  // Close the file

	// Send the array to the sort function
	sort(myArray, size);

	return;
}

int main()
{
	// Variables
	string fileAddress1;
	string fileAddress2;
	string fileAddress3;
	int data;
	int size = 0;

	// Printing my name and the class
	cout << "Miles Meacham" << endl;
	cout << "CS 2420" << endl;
	cout << "Program 6 - Sorting" << endl << endl;
	
	// Prompt user to choose a file to use
	cout << "Enter 3 full file paths:" << endl;
	cout << "File #1 - ";
	getline(cin, fileAddress1);
	cout << "\nFile #2 - ";
	getline(cin, fileAddress2);
	cout << "\nFile #3 - ";
	getline(cin, fileAddress3);

	// Print the header for the info
	cout << setw(10) << left << "SORT" << 
		setw(8) << left << "FILE" << 
		setw(15) << left << "NUMBER ITEMS" << 
		setw(15) << left << "ELAPSED CLOCK" <<
		setw(15) << left << "ELAPSED TIME" << 
		setw(15) << left << "SORTED FILE NAME" << endl;

	cout << "------------------------------------------------------------------------------" << endl;

	// Call the sort file for each of the files.
	sortFile(fileAddress1);
	sortFile(fileAddress2);
	sortFile(fileAddress3);


	system("PAUSE");

	return 0;


}


