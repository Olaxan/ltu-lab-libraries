#include "dsal.h"

#include <utility>
#include <algorithm>

namespace efiilj
{
	template <typename T>
	inline void Algorithm<T>::Swap(T& a, T& b)
	{
		/// Swaps two values using references.

		T temp = std::move(a);
		a = b;
		b = temp;
	}

	template<typename T>
	inline void Algorithm<T>::RightShift(T* arr, int count, int index)
	{
		/// Right-shifts elements in an array 1 step.
		/// Worst case running time is O(n).

		for (int k = count - 1; k > index; k--)
		{
			arr[k] = arr[k - 1];
		}
	}

	template<typename T>
	inline void Algorithm<T>::PrintArray(T* arr, int count)
	{
		/// Prints the contents of an array in a formatted manner.

		std::cout << "[";
		for (int i = 0; i < count - 1; i++)
		{
			std::cout << arr[i] << ", ";
		}
		std::cout << arr[count - 1] << "]";
	}

	template<typename T>
	inline int Algorithm<T>::BinaryFindIndex(T value, T* arr, int count)
	{
		/// A variant on Binary Search that returns a suitable index for insertion into a ascending sorted array.
		/// Worst-case running time is O(n*log(n)).

		int upper = count - 1;
		int middle = 0;
		int lower = 0;

		while (lower <= upper)
		{
			middle = (lower + upper) / 2;

			if (arr[middle] == value)
				break;

			if (value > arr[middle])
			{
				lower = middle + 1;		// Increase lower bound if value is greater than current middle.
				middle++;				// Increase 'middle' by one, to ensure values stay within input range.
			}
			else
				upper = middle - 1;		// Decrease upper bound if value is smaller than current middle.
		}

		return middle;					// Returns the index of a found value, or an index where such a value could be inserted.
	}

	template <typename T>
	inline void Algorithm<T>::InsertionSort(T* arr, int count)
	{
		/// A simple insertion sort algorithm.
		/// Iterates repeatedly through the array to find a suitable location for insertion.
		/// Runs in n2 worst-case time.

		if (count <= 1)
			return;

		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count - i - 1; j++)
			{
				if (arr[j + 1] < arr[j])
					Swap(arr[j + 1], arr[j]);
			}
		}
	}

	template <typename T>
	inline void Algorithm<T>::BinaryInsertionSort(T* arr, int count)
	{
		///A not-in-place sorting algorithm using binary searching to insert values in secondary array.
		///Not currently guaranteed to be ordered. Runs in XXX time.

		int index = 0;

		if (count <= 1)
			return;

		T* newArr = new T[count];

		for (int i = 0; i < count; i++)
		{
			index = BinaryFindIndex(arr[i], newArr, i);		// Find free place to insert value in secondary array.

			if (index < i)									// If index is less than the amount of currently sorted values...
				RightShift(newArr, count, index);			// Right shift array values in secondary array.

			newArr[index] = arr[i];							// Insert value in secondary array.
		}

		memmove_s(arr, count * sizeof(T), newArr, count * sizeof(T));		// Move values from secondary array back to original.
		delete[] newArr;
	}

	template<typename T>
	inline void Algorithm<T>::BinaryMergeSort(T* arr, int count, int k)
	{
		/// A merge sort implementation using Binary Insertion Sort when subproblems become sufficiently small.
		/// Not guaranteed to be ordered. Runs in XXX time.

		int countA = (count + 1) / 2;
		int countB = count / 2;

		if (count <= k)
		{
			InsertionSort(arr, count);
		}
		else
		{
			BinaryMergeSort(&arr[0], countA, k);			// Recursively sort A and B half of array using Binary Insertion Sort.
			BinaryMergeSort(&arr[countA], countB, k);

			std::inplace_merge(&arr[0], &arr[countA], &arr[count]);		// Merge subarrays using standard merging algorithm.
		}
	}

	template<typename T>
	inline void Algorithm<T>::InsertionMergeSort(T* arr, int count, int k)
	{
		/// A merge sort implementation using Insertion Sort when subproblems become sufficiently small.

		int countA = (count + 1) / 2;
		int countB = count / 2;

		if (count <= k)
		{
			BinaryInsertionSort(arr, count);
		}
		else
		{
			InsertionMergeSort(&arr[0], countA, k);			// Recursively sort A and B half of array using Insertion Sort.
			InsertionMergeSort(&arr[countA], countB, k);

			std::inplace_merge(&arr[0], &arr[countA], &arr[count]);		// Merge subarrays using standard merging algorithm.
		}
	}

	template<typename T>
	inline void Algorithm<T>::CombinedMergeSort(T* arr, int count, int k)
	{
		/// A merge sort implementation using Insertion Sort AND Binary Insertion sort when subproblems become sufficiently small.

		int countA = (count + 1) / 2;
		int countB = count / 2;

		if (count <= k)
		{
			BinaryInsertionSort(arr, count);
		}
		else
		{
			InsertionMergeSort(&arr[0], countA, k);			// Recursively sort A and B half of array using Insertion Sort.
			BinaryMergeSort(&arr[countA], countB, k);

			std::inplace_merge(&arr[0], &arr[countA], &arr[count]);		// Merge subarrays using standard merging algorithm.
		}
	}
}
