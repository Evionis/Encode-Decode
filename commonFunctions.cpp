/*
Author: Noah Anderson
Class : CSI - 281 - 01 : Data Structures & Algorithms
Assignment : Final Project
Assigned: 11 / 17 / 19
Due Date : 12 / 05 / 19 by 11:00 AM
Description : A program to use a codebook to decode files.

Certification of Authenticity : I certify that this is entirely my own work, except where I have given fully - documented
references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the
assessor of this assignment may, for the purpose of assessing this assignment :

-Reproduce  this  assignment  and  provide  a  copy  to  another  member  of academic staff; and/or

-Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment
on its database for the purpose of future plagiarism checking)
*/

#include "commonFunctions.h"

/*
Pre: An ifstream is open and a list of avl trees exists
Post: The contents of an encoded file have been decoded and sent to a file
Purpose: To decode an encoded file and send the results to a seperate file
*/
void decodeFile(ifstream& encodedFile, AVL<word> forest[])
{
	string decodedFilePath, tmp;
	ofstream decodedFile;
	bool valid = false;
	while (!valid)
	{
		cout << "Enter file path for decoded file: ";
		//enter path, not just file name if you want to put it in a folder
		cin >> decodedFilePath;
		decodedFile.open(decodedFilePath, ios::app);
		if (!decodedFile.fail())
		{
			valid = true;
		}
		else
		{
			cout << "Invalid Path." << endl;
			decodedFile.close();
		}
	}
	int index = 0;
	word found;
	double timeDecode;
	TimerSystem timer;
	timer.startClock();
	//Get a number from the encoded file
	encodedFile >> tmp;
	while (!encodedFile.eof())
	{
		//Based on the first 4 digits of the encoded word, find the avl tree that the word should be in
		index = getIndex(tmp);
		//Find the word
		found = forest[index].search(tmp);
		//print word to file
		decodedFile << found.getWord() << " ";
		encodedFile >> tmp;
	}
	decodedFile.close();
	timeDecode = timer.getTime();
	//Print time
	cout << "Decode Time: " << timeDecode << endl;
}

/*
Pre: A string exists
Post: The proper index has been returned
Purpose: To return an index based on the first 4 digits of a given string
*/
int getIndex(string tmp)
{
	//Return the index based on the first 4 digits of the string
	int index = (tmp[0] - '0') * 1000 + (tmp[1] - '0') * 100 + (tmp[2] - '0') * 10 + (tmp[3] - '0');
	return index;
}

/*
Pre: N/A
Post: The program has run
Purpose: To form the platform for the rest of the code to run and to facilitate human -> computer interactions
*/
void menu()
{
	ifstream codeBook;
	//check for codes.txt file
	codeBook.open("data/codes.txt");
	if (codeBook.fail())
	{
		cout << "Please place codes.txt in the data folder. Exiting." << endl;
		return;
	}
	//create array of 10000 avl trees
	AVL<word> forest[10000];
	word tmp;
	int index;
	TimerSystem timer;
	double timeStore;
	timer.startClock();
	//collect data from codes.txt
	while (!codeBook.eof())
	{
		codeBook >> tmp;
		index = getIndex(tmp.getNumber());
		forest[index].insert(tmp);
	}
	codeBook.close();
	//report storage time
	timeStore = timer.getTime();
	cout << "Storage Time: " << timeStore << endl;

	int choice = 0;
	//menu system
	while (choice != 2)
	{
		cout << "1: Decode New File" << endl;
		cout << "2: Exit" << endl;
		cout << "Input Choice: ";
		cin >> choice;

		if (choice == 1)
		{
			string filePath;
			cout << "Input path to file to decode: ";
			cin >> filePath;
			ifstream encodedFile;
			encodedFile.open(filePath);
			//check for successful opening of encoded file
			if (!encodedFile.fail())
			{
				//decode file
				decodeFile(encodedFile, forest);
				encodedFile.close();
			}
			else
			{
				cout << "Invalid File Path." << endl;
			}
		}
		else if (choice == 2)
		{
			cout << "Exiting" << endl;
		}
		else
		{
			cout << "Invalid Input" << endl;
		}
	}
}