// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\DS\sarray.h"
#include "..\UserInput\uinput.h"
#include "..\UserInput\menu.h"
#include "..\DS\dsal.h"

#include <chrono>
#include <iostream>
#include <string>
#include <time.h>

using namespace std::chrono;

int SIZE = 10000;
int SAMPLES = 5;
int SUBSIZE = 2;

enum TestSettings
{
	Insertion = 1, BinaryInsertion = 2, InsertionMerge = 4, BinaryInsertionMerge = 8, CombinedMerge = 16
};

void Scramble(int* arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		arr[i] = rand() % count;
	}
}

int TestMicro(TestSettings set, int* arr, int count, int k)
{
	high_resolution_clock::time_point t1, t2;
	microseconds ms;

	Scramble(arr, count);

	t1 = high_resolution_clock::now();
	switch (set)
	{
	case Insertion:
		efiilj::Algorithm<int>::InsertionSort(arr, count);
		break;
	case BinaryInsertion:
		efiilj::Algorithm<int>::BinaryInsertionSort(arr, count);
		break;
	case InsertionMerge:
		efiilj::Algorithm<int>::InsertionMergeSort(arr, count, k);
		break;
	case BinaryInsertionMerge:
		efiilj::Algorithm<int>::BinaryMergeSort(arr, count, k);
		break;
	case CombinedMerge:
		efiilj::Algorithm<int>::CombinedMergeSort(arr, count, k);
		break;
	default:
		break;
	}
	t2 = high_resolution_clock::now();

	return (duration_cast<microseconds>(t2 - t1).count());
}

int TestMicroAverage(TestSettings set, int samples, int* arr, int count, int k)
{
	int sum = 0;

	for (int i = 0; i < samples; i++)
	{
		sum += TestMicro(set, arr, count, k);
	}

	return (sum / samples);
}

bool DoChangeSamples()
{
	efiilj::UserInput<int> input = efiilj::UserInput<int>("Current sample size is " + std::to_string(SAMPLES) + ".\nEnter new value:", "> ", 1);
	if (input.Show())
		SAMPLES = input.Value();

	return false;
}

bool DoChangeSize()
{
	efiilj::UserInput<int> input = efiilj::UserInput<int>("Current default array size is " + std::to_string(SIZE) + ".\nEnter new value:", "> ", 1);
	if (input.Show())
		SIZE = input.Value();

	return false;
}

bool DoChangeSubsize()
{
	efiilj::UserInput<int> input = efiilj::UserInput<int>("Current subproblem size is " + std::to_string(SUBSIZE) + ".\nEnter new value:", "> ", 1, SIZE);
	if (input.Show())
		SUBSIZE = input.Value();

	return false;
}

bool DoFindK(TestSettings data)
{
	int* arr = new int[SIZE];

	std::cout << "Finding k-value for array of size " << SIZE << ".\n";
	
	int avg = 0;
	int k = 1;
	int test;
	int bestTime = INT_MAX;

	for (int i = 0; i < SAMPLES; i++)
	{
		while (true)
		{
			k++;
			test = TestMicroAverage(data, SAMPLES, arr, SIZE, k);
			if (test < bestTime)
				bestTime = test;
			else break;
		}

		avg += k;
		k = 1;

		std::cout << "\rTest: " << i + 1 << "/" << SAMPLES;
	}

	avg = round(float(avg) / float(SAMPLES));

	std::cout << "\nOptimal k-value for array is " << avg << ".\n";

	delete[] arr;
	return false;
}

bool DoFindKGood(TestSettings data)
{
	int* arr = new int[SIZE];

	std::cout << "K-values for array of size " << SIZE << " (" << SAMPLES << " samples):\n";

	int test;
	int bestTime = INT_MAX;
	int bestK = 2;

	for (int k = 1; k < SIZE; k *= 2)
	{
		test = TestMicroAverage(data, SAMPLES, arr, SIZE, k);
		if (test < bestTime)
		{
			bestTime = test;
			bestK = k;
		}

		std::cout << "\nK = " << k << ": " << test << " microseconds.";
	}

	std::cout << "\n\nOptimal k-value for array is " << bestK << ".\n";

	delete[] arr;
	return false;
}

bool DoTest(TestSettings data)
{
	int* arr = new int[SIZE];

	std::cout << "\nAverage time (" << SAMPLES << " samples): " << TestMicroAverage(data, SAMPLES, arr, SIZE, SUBSIZE) << " microseconds.\n";

	delete[] arr;
	return false;
}

int main()
{
	srand(time(NULL));

	efiilj::Menu<TestSettings> main = efiilj::Menu<TestSettings>(" === MAIN MENU === ");
	efiilj::Menu<TestSettings> set = efiilj::Menu<TestSettings>(" === SETTINGS === ");
	efiilj::Menu<TestSettings> tests = efiilj::Menu<TestSettings>(" === ALGORITHM TESTS === ");
	efiilj::Menu<TestSettings> sub = efiilj::Menu<TestSettings>(" === SUBPROBLEM SIZE TESTS === ");
	efiilj::Menu<TestSettings> subLin = efiilj::Menu<TestSettings>(" === LINEAR SUBPROBLEM SIZE TESTS === ");
	efiilj::Menu<TestSettings> subQuad = efiilj::Menu<TestSettings>(" === EXP. SUBPROBLEM SIZE TESTS === ");
	
	main.AddItem("Subproblem size tests", &sub);
	main.AddItem("Standard tests", &tests);
	main.AddItem("Settings", &set);

	sub.AddItem("Linear tests", &subLin);
	sub.AddItem("Exponential tests", &subQuad);

	subLin.AddItem("Insertion merge sort", DoFindK, InsertionMerge);
	subLin.AddItem("Binary insertion merge sort", DoFindK, BinaryInsertionMerge);
	subLin.AddItem("Combined merge sort", DoFindK, CombinedMerge);

	subQuad.AddItem("Insertion merge sort", DoFindKGood, InsertionMerge);
	subQuad.AddItem("Binary insertion merge sort", DoFindKGood, BinaryInsertionMerge);
	subQuad.AddItem("Combined merge sort", DoFindKGood, CombinedMerge);

	set.AddItem("Change sample size", DoChangeSamples);
	set.AddItem("Change default array size", DoChangeSize);
	set.AddItem("Change default subproblem size", DoChangeSubsize);

	tests.AddItem("Insertion sort", DoTest, Insertion);
	tests.AddItem("Binary insertion sort", DoTest, BinaryInsertion);
	tests.AddItem("Insertion merge sort", DoTest, InsertionMerge);
	tests.AddItem("Binary insertion merge sort", DoTest, BinaryInsertionMerge);
	tests.AddItem("Combined merge sort", DoTest, CombinedMerge);

	main.Show();
}