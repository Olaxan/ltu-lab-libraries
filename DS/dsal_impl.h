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
	inline void Algorithm<T>::Merge(T* arr1, int len1, T* arr2, int len2)
	{
		for (int i = len2 - 1; i >= 0; i--)
		{

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
		std::cout << arr[count - 1] << "]\n";
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
			{
				for (int k = count; k > index; k--)
				{
					newArr[k] = newArr[k - 1];
				} 
			}

			newArr[index] = arr[i];
		}

		memmove_s(arr, count * sizeof(T), newArr, count * sizeof(T));
		delete[] newArr;
	}

	template<typename T>
	inline void Algorithm<T>::BinaryMergeSort(T* arr, int count, int k)
	{
		int lowerMid = (count + 1) / 2;
		int upperMid = count / 2;

		/*int lowerMid = count / 2;
		int upperMid = (count + 1) / 2;*/

		if (count <= k)
		{
			InsertionSort(arr, count);
		}
		else
		{
			BinaryMergeSort(&arr[0], lowerMid, k);
			BinaryMergeSort(&arr[upperMid], count - upperMid, k); //ob1?

			/*T* newArr = new T[count + 1];
			std::merge(arr, arr + lowerMid - 1, arr + upperMid, arr + count - 1, newArr);
			memmove_s(arr, count * sizeof(T), newArr, count * sizeof(T));
			delete[] newArr;*/
			
			//Merge(&arr[0], lowerMid, &arr[upperMid], count - upperMid);
		}
	}

	template<typename T>
	inline void Algorithm<T>::InsertionMergeSort(T* arr, int count, int k)
	{

	}
}
