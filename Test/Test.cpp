// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "..\DS\sarray.h"
#include "..\UserInput\uinput.h"
#include "..\DS\dsal.h"

#include <iostream>

int main()
{
	//efiilj::SortedArray<int> list{ 0, 5, 3, 1, 2 };
	int bob[] = { 5, 4, 1, 2, 6 };
	efiilj::Algorithm<int>::InsertionSort(bob, 5);

	for (int i = 0; i < sizeof(bob) / sizeof(int); i++)
	{
		std::cout << bob[i] << ", ";
	}
	std::cout << std::endl;
}
