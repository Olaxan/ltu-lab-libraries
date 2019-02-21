// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "..\DS\sarray.h"
#include "..\UserInput\uinput.h"
#include "..\DS\dsal.h"

#include <chrono>
#include <iostream>
#include <string>
#include <time.h>

using namespace std::chrono;

const int len = 10000;
const int samples = 100;

int bob[len];

std::string sortTypes[5] = { "BINARY INSERTION SORT", "INSERTION SORT", "BINARY MERGE SORT", "INSERTION MERGE SORT", "COMBINED MERGE SORT" };
high_resolution_clock::time_point t1, t2;
microseconds m1, m2;

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{

		m2 = m2.zero();

		std::cout << " === " << sortTypes[i] << " with " << len << " values, " << samples << " samples === \n";

		for (int k = 0; k < samples; k++)
		{
			for (int j = 0; j < len; j++)
			{
				bob[j] = rand() % 5000;
			}

			t1 = high_resolution_clock::now();
			switch (i)
			{
			case 0:
				efiilj::Algorithm<int>::BinaryInsertionSort(bob, len);
				break;
			case 1:
				efiilj::Algorithm<int>::InsertionSort(bob, len);
				break;
			case 2:
				efiilj::Algorithm<int>::BinaryMergeSort(bob, len, 2);
				break;
			case 3:
				efiilj::Algorithm<int>::InsertionMergeSort(bob, len, 2);
				break;
			case 4:
				efiilj::Algorithm<int>::CombinedMergeSort(bob, len, 2);
				break;
			}
			t2 = high_resolution_clock::now();

			m1 = duration_cast<microseconds>(t2 - t1);

			std::cout << " + " << m1.count() << " microseconds\n";

			m2 += m1;
		}

		m2 = m2 / samples;

		std::cout << "\nAverage time (" << samples << " samples, " << len << " values): " << m2.count() << " microseconds.\n\n"; 
	}
}
