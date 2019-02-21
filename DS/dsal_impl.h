#include "dsal.h"

#include <utility>
#include <algorithm>

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
	inline void Algorithm<T>::RightShift(T* arr, int count, int index)
	{
		for (int k = count; k > index; k--)
		{
			arr[k] = arr[k - 1];
		}
	}

	template<typename T>
	inline int Algorithm<T>::BinaryFindIndex(T value, T* arr, int count)
	{

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
				lower = middle + 1;
				middle++;
			}
			else
				upper = middle - 1;
		}

		return middle;
	}

	template<typename T>
	inline void Algorithm<T>::PrintArray(T* arr, int count)
	{
		std::cout << "[";
		for (int i = 0; i < count - 1; i++)
		{
			std::cout << arr[i] << ", ";
		}
		std::cout << arr[count - 1] << "]";
	}

	template <typename T>
	inline void Algorithm<T>::InsertionSort(T* arr, int count)
	{
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
		int index = 0;

		if (count <= 1)
			return;

		T* newArr = new T[count + 1];				//?????????

		for (int i = 0; i < count; i++)
		{
			index = BinaryFindIndex(arr[i], newArr, i);

			if (index < i)
				RightShift(newArr, count, index);

			newArr[index] = arr[i];
		}

		memmove_s(arr, count * sizeof(T), newArr, count * sizeof(T));
		delete[] newArr;
	}

	template<typename T>
	inline void Algorithm<T>::BinaryMergeSort(T* arr, int count, int k)
	{
		int countA = (count + 1) / 2;
		int countB = count / 2;

		if (count <= k)
		{
			InsertionSort(arr, count);
		}
		else
		{
			BinaryMergeSort(&arr[0], countA, k);
			BinaryMergeSort(&arr[countA], countB, k); //ob1?

			T* newArr = new T[count + 1];

			std::inplace_merge(&arr[0], &arr[countA], &arr[count]);
		}
	}

	template<typename T>
	inline void Algorithm<T>::InsertionMergeSort(T* arr, int count, int k)
	{

	}
}
