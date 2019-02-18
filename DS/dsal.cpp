#include "stdafx.h"
#include "dsal.h"

#include <utility>

namespace efiilj
{
	template <typename T>
	void Algorithm<T>::Swap(T* a, T* b)
	{
		T temp = std::move(a);
		a = b;
		b = temp;
	}

	template <typename T>
	void Algorithm<T>::InsertionSort(T* first, int count)
	{

	}
}
