#pragma once

namespace efiilj
{
	template <typename T>
	class Algorithm
	{
	private:
		static void Swap(T* a, T* b);
	public:
		static void InsertionSort(T*, int);
		static void BinaryInsertionSort(T* first, int count);
		static void ASort(T* first, int count);
		static void BSort(T* first, int count);
	};
}

