// Author: Miles Meacham
// Date: 02/12/2016
// Contents: Stacks and Queues



#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// Enum for available commands for the stack and queue
enum commands {
	Push,
	Pop,
	Append,
	Serve,
	Garbage,
};

// StringCommand Function
// Purpose: Parse the string read in from the file
// Parameter: string
// Return: commands (enum)
commands StringCommand(string const& inString);


int main()
{
	// Declaring Variabless
	Queue myQueue;
	Stack myStack;
	string fileAddress;
	string command;
	string stackOrQueue;
	int result;
	string resultString;
	int myData;

	// Printing my name and the class
	cout << "Miles Meacham" << endl;
	cout << "CS 2420" << endl;
	cout << "Program 2 - Linked Lists" << endl << endl;

	

	// Prompt user to choose a file to use
	cout << "Enter the full path of the file you want to read in:" << endl;
	getline(cin, fileAddress);

	// Print out the Heading for the output
	cout << endl <<
			setw(10) << "Operation" <<
			setw(10) << "Stack" <<
			setw(10) << "Value" <<
			setw(10) << "Result" << endl;
	cout << "-----------------------------------------------" << endl;

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
		myFile >> command;
		myData = NULL;

		if (myFile.good())
		{

			// Swith Statement to run the command
			switch (StringCommand(command))  // Call StringCommand to parse the data
			{
			case Push:
				myFile >> myData;				// Pushing requires data, the file should have data after push
				stackOrQueue = "Stack";			// Push is for Stack, assign variable to reflect this
				result = myStack.Push(myData);	// Push reurns and ErrorCode, assign errorcode to result
				break;
			case Pop:
				stackOrQueue = "Stack";
				result = myStack.Pop();
				break;
			case Append:
				myFile >> myData;
				stackOrQueue = "Queue";
				result = myQueue.Append(myData);
				break;
			case Serve:
				stackOrQueue = "Queue";
				result = myQueue.Serve();
				break;
			case Garbage:
				stackOrQueue = "None";
				result = 4;
				break;
			default:
				resultString = "Invalid Command";

			}

			// We want to output the ErrorCode as a string and not an int.
			// Here I convert the int to the appropriate string
			if (result == 0)
				resultString = "Success";
			else if (result == 1)
				resultString = "Overflow";
			else if (result == 2)
				resultString = "Underflow";
			else
				resultString = "Invalid Command";

			// Output the results of everything
			cout << setw(10) << command <<
					setw(10) << stackOrQueue;

			// If data is "NULL" the professor wanted us to output "---" instead of "0"
			if (myData == NULL)
				cout << setw(10) << "---";
			else
				cout << setw(10) << myData;

			// Output the ErrorCode string here
			cout << setw(10) << resultString << endl;

		}
		else
		{
			// Skip lines that don't contain just numbers
			myFile.clear();
			myFile.ignore();
		}
	} while (!myFile.eof());

	


	cout << endl;

	system("PAUSE");
	return 0;
}


commands StringCommand(string const& inString)
{
	// Just return the equivalent to the string
	if (inString == "push") return Push;
	if (inString == "pop") return Pop;
	if (inString == "append") return Append;
	if (inString == "serve") return Serve;
	
	// If string doesn't match anything above, return Garbage
	return Garbage;


}



