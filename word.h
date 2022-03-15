#pragma once
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

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class word
{
	private:
		string mNumber;
		string mWord;
	public:
		//Constructor & Destructor
		word();
		~word();
		//Accessors
		string getNumber();
		string getWord();
		//Mutators
		void setNumber(string newNumber);
		void setWord(string newWord);
		//Operators
		friend ifstream& operator>>(ifstream& input, word& obj);
		friend bool operator>(word lhs, string rhs);
		friend bool operator>(word lhs, word rhs);
		friend bool operator<(word lhs, word rhs);
		friend bool operator==(word lhs, string rhs);
		friend bool operator==(word lhs, word rhs);
		void operator=(word rhs);
};

