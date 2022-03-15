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

#include "word.h"

/*
Pre: N/A
Post: An empty word object has been created
Purpose: To create an empty word object
*/
word::word()
{
	mNumber = "";
	mWord = "";
}

/*
Pre: A word object exists
Post: The word object has been destroyed
Purpose: To destroy a word object
*/
word::~word()
{
	
}

/*
Pre: A word object exists
Post: The mNumber has been returned
Purpose: To return the mNumber of a word object
*/
string word::getNumber()
{
	return mNumber;
}

/*
Pre: A word object exists
Post: The mWord has been returned
Purpose: To return the mWord of a word object
*/
string word::getWord()
{
	return mWord;
}

/*
Pre: A word object exists and there is a string, newNumber
Post: The mNumber has been set
Purpose: To set the mNumber of a word object
*/
void word::setNumber(string newNumber)
{
	mNumber = newNumber;
}

/*
Pre: A word object exists and there is a string, newWord
Post: The mWord has been set
Purpose: To set the mWord of a word object
*/
void word::setWord(string newWord)
{
	mWord = newWord;
}

/*
Pre: An ifstream is open and a word object exists
Post: The value of the word object has been set
Purpose: To collect information from a file and add it to a word object
*/
ifstream& operator>>(ifstream& input, word& obj)
{
	input >> obj.mWord >> obj.mNumber;
	return input;
}


/*
Pre: A word object exists and there is a string to compare it to
Post: The result of lhs.mNumber > rhs has been returned
Purpose: To check if a word object is larger than a specified string
*/
bool operator>(word lhs, string rhs)
{
	return lhs.mNumber > rhs;
}

/*
Pre: Two word objects exists
Post: The result of lhs.mNumber > rhs.mNumber has been returned
Purpose: To check if a word object is larger than another word object
*/
bool operator>(word lhs, word rhs)
{
	return lhs.mNumber > rhs.mNumber;
}

/*
Pre: Two word objects exists
Post: The result of lhs.mNumber < rhs.mNumber has been returned
Purpose: To check if a word object is smaller than another word object
*/
bool operator<(word lhs, word rhs)
{
	return lhs.mNumber < rhs.mNumber;
}

/*
Pre: A word object exists and there is a string to compare it to
Post: The result of lhs.mNumber == rhs has been returned
Purpose: To check if a word object is equal to a specified string
*/
bool operator==(word lhs, string rhs)
{
	return lhs.mNumber == rhs;
}

/*
Pre: Two word objects exists
Post: The result of lhs.mNumber == rhs.mNumber has been returned
Purpose: To check if a word object is equal to another word object
*/
bool operator==(word lhs, word rhs)
{
	return lhs.mNumber == rhs.mNumber;
}

/*
Pre: Two word objects exists
Post: The value of one word has been set to the value of another word
Purpose: To set the value of a word to be equal to the value of another word
*/
void word::operator=(word rhs)
{
	mWord = rhs.mWord;
	mNumber = rhs.mNumber;
}