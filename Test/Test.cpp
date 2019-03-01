// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "..\DS\sarray.h"
#include "..\UserInput\uinput.h"
#include "..\UserInput\menu.h"
#include "..\DS\dsal.h"

#include <chrono>
#include <iostream>
#include <string>
#include <time.h>

using namespace std::chrono;

int samples = 5;

enum TestSettings
{
	Insertion = 1, BinaryInsertion = 2, InsertionMerge = 4, BinaryInsertionMerge = 8, CombinedMerge = 16
};

void Scramble(int* arr, int count)
{
	srand(time(NULL));

	for (int i = 0; i < count; i++)
	{
		arr[i] = rand() % count;
	}
}

bool DoChangeSamples()
{
	efiilj::UserInput<int> input = efiilj::UserInput<int>("Current sample size is " + std::to_string(samples) + ".\nEnter new value:", "> ", 1);
	if (input.Show())
		samples = input.Value();

	return false;
}

bool DoFindK()
{
	return false;
}

bool DoTest(TestSettings data)
{
	high_resolution_clock::time_point t1, t2;
	microseconds ms;
	int size = 10;

	efiilj::UserInput<int> input = efiilj::UserInput<int>("Enter array size:", "> ", 1);
	if (!input.Show())
		return false;
	
	size = input.Value();
	int* arr = new int[size];

	ms = ms.zero();

	for (int i = 0; i < samples; i++)
	{
		Scramble(arr, size);

		t1 = high_resolution_clock::now();
		efiilj::Algorithm<int>::BinaryMergeSort(arr, size, 2);
		t2 = high_resolution_clock::now();

		ms += duration_cast<microseconds>(t2 - t1);
	}

	ms = ms / samples;

	std::cout << "\nAverage time (" << samples << " samples): " << ms.count() << " microseconds.\n";

	return false;
}

int main()
{
	efiilj::Menu<TestSettings> main = efiilj::Menu<TestSettings>(" === MAIN MENU === ");
	efiilj::Menu<TestSettings> tests = efiilj::Menu<TestSettings>(" === ALGORITHM TESTS === ");
	efiilj::Menu<TestSettings> set = efiilj::Menu<TestSettings>(" === SETTINGS === ");

	main.AddItem("Find optimal subproblem size", DoFindK);
	main.AddItem("Standard tests", &tests);
	main.AddItem("Settings", &set);

	set.AddItem("Change sample size", DoChangeSamples);

	tests.AddItem("Insertion sort", DoTest, Insertion);
	tests.AddItem("Binary insertion sort", DoTest, BinaryInsertion);
	tests.AddItem("Insertion merge sort", DoTest, InsertionMerge);
	tests.AddItem("Binary insertion merge sort", DoTest, BinaryInsertionMerge);
	tests.AddItem("Combined merge sort", DoTest, CombinedMerge);

	main.Show();
}