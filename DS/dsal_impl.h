#include "dsal.h"

#include <utility>

namespace efiilj
{
	template <typename T>
	inline void Algorithm<T>::Swap(T& a, T& b)
	{
		T temp = std::move(a);
		a = b;
		b = temp;
	}



	template<typename T>
	inline int Algorithm<T>::BinarySearch(T value, T* arr, int count)
	{
		int upper = count - 1;
		int middle = 0;
		int lower = 0;

		while (lower < upper)
		{
			middle = (lower + upper) / 2;

			if (arr[middle] == value)
				return middle;

			if (value > arr[middle])
				lower = middle + 1;
			else
				upper = middle - 1;
		}

		return middle;
	}

	template <typename T>
	inline void Algorithm<T>::InsertionSort(T* arr, int count)
	{
		if (count <= 1)
			return;

		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count - i; j++)
			{
				if (arr[j + 1] > arr[j])
					Swap(arr[j + 1], arr[j]);
			}
		}
	}

	template <typename T>
	inline void Algorithm<T>::BinaryInsertionSort(T* arr, int count)
	{
		int index = 0;

		if (count <= 1)
			return;

		int newArr = new int[count];

		for (int i = 0; i < count; i++)
		{
			index = BinarySearch(newArr[i], arr, i);
			if (index < i)
				memmove_s(newArr + index + 1, (count - index) * sizeof(T), newArr + index, (count - index) * sizeof(T));
				
			newArr[index] = arr[i];
		}

		memmove_s(arr, count * sizeof(T), newArr, count * sizeof(T));
		delete[] newArr;
	}
}
