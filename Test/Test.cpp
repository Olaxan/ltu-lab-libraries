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

enum TestSettings
{
	Insertion
};

bool DoTest(TestSettings data)
{
	if (data == Insertion)
		std::cout << "HELLO YOU FUCK";
	return true;
}

int main()
{
	srand(time(NULL));

	efiilj::Menu<TestSettings> main = efiilj::Menu<TestSettings>(" === MAIN MENU ===");
	main.AddItem("Start non-recursive test", DoTest, Insertion);
	main.Show();
}