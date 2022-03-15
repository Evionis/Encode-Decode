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
#include "commonFunctions.h"
#include "timerSystem.h"

int main()
{
	//Set precision to 4 decimals, scientific form
	std::cout.setf(std::ios::scientific | std::ios::showpoint);
	std::cout.precision(4);
	menu();
	system("pause");
	return 0;
}