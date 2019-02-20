// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "..\DS\sarray.h"
#include "..\UserInput\uinput.h"
#include "..\DS\dsal.h"

#include <iostream>



int main()
{
	int bob[] = { 5, 7, 8, 9, 33, 7, 3, 987, 482, 1, 72, 383, 7, 6325, 2 };
	int len = sizeof(bob) / sizeof(int);

	std::cout << "UNSORTED: ";
	efiilj::Algorithm<int>::PrintArray(bob, len);

	//efiilj::Algorithm<int>::BinaryInsertionSort(bob, len);
	//efiilj::Algorithm<int>::InsertionSort(bob, len);
	efiilj::Algorithm<int>::BinaryMergeSort(bob, len, 2);

	std::cout << "  SORTED: ";
	efiilj::Algorithm<int>::PrintArray(bob, len);
}
