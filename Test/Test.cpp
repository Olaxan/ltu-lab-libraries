// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "..\DS\sarray.h"
#include "..\UserInput\uinput.h"
#include "..\DS\dsal.h"

#include <iostream>
#include <cmath>

int main()
{
	int bob[] = { 6, 4, 2, 67, 3, 2, 7, 2, 7, 26666 };
	int len = sizeof(bob) / sizeof(int);

	//std::cout << efiilj::Algorithm<int>::BinarySearch(0, bob, len) << std::endl;

	efiilj::Algorithm<int>::BinaryInsertionSort(bob, len);

	for (int i = 0; i < len; i++)
	{
		std::cout << std::string(i, ' ') << bob[i] << "\n";
	}

	std::cout << "\nOH YEAH";
}
