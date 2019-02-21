#pragma once

namespace efiilj
{
	template <typename T>
	class Algorithm
	{
	private:
		static void Swap(T& a, T& b);
		static void RightShift(T* arr, int count, int index);
	public:
		static int BinaryFindIndex(T value, T* arr, int count);
		static void PrintArray(T* arr, int count);
		static void InsertionSort(T* arr, int count);
		static void BinaryInsertionSort(T* first, int count);
		static void BinaryMergeSort(T* first, int count, int k);
		static void InsertionMergeSort(T* first, int count, int k);
	};
}

#include "dsal_impl.h"

