// Author: Miles Meacham
// Date: 1/10/2016
// Description: This program will read in data from a file and give you the fibonacci value of the numbers

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int fibonacci(double n);

int main()
{
	// declaring variables
	string fileAddress;
	double myData;
	vector<double> numbers;
	char repeat = 'y'; 


	// Variables to be used in the Noncursion form
	double firstNumber;
	double secondNumber;
	double tempNumber;
	int x = 0;

	// This variable will be used to count how many numbers there are in the file (Used on Line 53)
	int i = 0;


	// This enables us to rerun the program if the user wants to
	while (repeat == 'y')
	{
		// Prompt user to choose a file to use
		cout << "Enter the full path of the file you want to read in:" << endl;
		getline(cin, fileAddress);

		// Open the file
		ifstream myFile(fileAddress.c_str());

		// Test to see if the file was able to be opened
		if (!myFile)
		{
			cout << "There was an Error opening this file" << endl;

			system("PAUSE");
			return 1;
		}

		// Read the data from the file and save it into a vector (numbers)
		do
		{
			myFile >> myData;

			if (myFile.good())
			{
				numbers.push_back(myData);
				i++;
			}
			else
			{
				// Skip lines that don't contain just numbers
				myFile.clear();
				myFile.ignore();
			}
		} while (!myFile.eof());


		// Beginning of the Noncursion form
		cout << endl << "Noncursion" << endl;
		cout << setw(10) << left << "N" << setw(10) << left << "Fib(N)" << endl;
		cout << "-------------------" << endl;

		// For loop to iterate through all of the numbers we read in from the data
		for (int n = 0; n < i; n++)
		{
			// Reset 'x' to 0 everytime through the Forloop
			x = 0;
			firstNumber = 0;
			secondNumber = 1;

			// While loop to find the fibinocci number of the nth position
			while (x < numbers[n])
			{
				// Add the first and second number together
				tempNumber = firstNumber + secondNumber;

				// Change the values of first and second number
				firstNumber = secondNumber;
				secondNumber = tempNumber;

				// increment x
				x++;

			}

			// Output the results
			cout << setw(10) << left << numbers[n] << setw(10) << left << firstNumber << endl;

		}

		
		// Beginning of Recursive form
		cout << endl << "Recursion" << endl;
		cout << setw(10) << left << "N" << setw(10) << left << "Fib(N)" << endl;
		cout << "-------------------" << endl;

		// variable to store the results from the resursive function
		int fib;

		// Forloop to iterate through all the numbers from the data
		for (int p = 0; p < i; p++)
		{
			// Call the recursive function
			fib = fibonacci(numbers[p]);

			// Output the results of the recursive function
			cout << setw(10) << left << numbers[p] << setw(10) << left << fib << endl;

		}

		

		// Ask user if he wants to run the program again		
		cout << endl << "Would you like to run the program again? (y/n)" << endl;
		cin >> repeat;

		bool validInput = false;

		// Wait for a correct response to the answer.
		while (validInput == false)
		{
			if (repeat == 'y' || repeat == 'n')
				validInput = true;
			else
			{
				cout << "Invalid response, please enter 'y' or 'n'" << endl;
				cin >> repeat;

			}
			
		}

		// Clear out the cin
		cin.ignore();

	}


	// End Program
	cout << "Thank you for using my program" << endl;
	system("PAUSE");
	return 0;
}


// fibonacci recursive function
// Purpose: find the fibonacci value of position "n"
// Parameter: double
// Return: int
int fibonacci(double n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return (fibonacci(n - 1) + fibonacci(n - 2));

}