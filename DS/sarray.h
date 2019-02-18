#pragma once

#include <string>
#include <initializer_list>

namespace efiilj
{

	template <typename T>
	class SortedArray
	{
	private:
		T* _items;
		int _count;

		void InsertAt(int index, T value);
		void RemoveAt(int index);
		T GetAt(int index) const;

		void Resize(int newSize);

	public:

		SortedArray();
		SortedArray(std::initializer_list<T> il)
		{
			_count = il.size();
			_items = new T[_count];
			memcpy_s(_items, _count * sizeof(T), il.begin(), _count * sizeof(T));
		}

		//Comparator determines manner of sorting the array.
		//Should return 'true' if left-hand is greater than right-hand.
		//Use for data types where custom comparison is necessary.
		bool(*Comparator)(T a, T b) = [](T a, T b) -> bool { return a > b; };
		enum Algorithm { A_SORT, B_SORT };

		//Default: false - items in ascending order.
		bool descending = false;

		int	Find(T value) const;
		bool Exists(T value) const;
		void Insert(T value);
		void Remove(T value);

		std::string ToString() const;
		int Count() const;

		T operator [] (int index) const { return GetAt(index); }

		~SortedArray() { delete[] _items; }

	};

}

//Include template implementation file (for organization purposes).
#include "sarray_impl.h"

