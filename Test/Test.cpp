// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "..\DS\sarray.h"
#include "..\UserInput\uinput.h"
#include "..\DS\dsal.h"

#include <iostream>

int main()
{
	int bob[] = { 5, 4, 1, 2, 6 };
	efiilj::SortedArray<int> list{ 0, 5, 3, 1, 2 };
	std::cout << list.ToString();
}
