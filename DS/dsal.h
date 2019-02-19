#pragma once

namespace efiilj
{
	template <typename T>
	class Algorithm
	{
	private:
		static void Swap(T& a, T& b);
	public:
		static int BinarySearch(T value, T* arr, int count);
		static void InsertionSort(T* arr, int count);
		static void BinaryInsertionSort(T* first, int count);
		static void ASort(T* first, int count);
		static void BSort(T* first, int count);
	};
}

#include "dsal_impl.h"

