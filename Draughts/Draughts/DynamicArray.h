#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class DynamicArray
{
private:
	
	T* data;
	int currentSize;
	int capacity;

	void Resize();

public:

	DynamicArray();
	~DynamicArray();
	int GetCurrentSize();
	int GetCapacity();
	void Add(T& newData);
	void Shrink();
	T* GetData(int index);
	void DisplayList();
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	currentSize = 0;
	capacity = 1;
	data = new T[capacity];
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
	delete[] data;
}

template<typename T>
inline int DynamicArray<T>::GetCurrentSize()
{
	return currentSize;
}

template<typename T>
inline int DynamicArray<T>::GetCapacity()
{
	return capacity;
}

template<typename T>
inline void DynamicArray<T>::Resize()
{
	capacity *= 2;

	T* tempArray = new T[capacity];

	for (int i = 0; i < currentSize; i++) {
		tempArray[i] = data[i];
	}

	data = tempArray;
}

template<typename T>
inline void DynamicArray<T>::Add(T& newData)
{
	if (currentSize >= capacity) {
		Resize();
	}

	data[currentSize] = newData;
	currentSize++;
}

template<typename T>
inline void DynamicArray<T>::Shrink()
{
	if (currentSize != capacity) {

		T* tempArray = new T[currentSize - 1];

		for (int i = 0; i < currentSize; i++) {
			tempArray[i] = data[i];
		}

		capacity = currentSize;
		data = tempArray;
	}
}

template<typename T>
T* DynamicArray<T>::GetData(int index)
{
	return data[index];
}

template <typename T>
void DynamicArray<T>::DisplayList()
{
	cout << "Generic DisplayList():\n";
}

template<>
inline void DynamicArray<string>::DisplayList()
{
	for (int i = 0; i < currentSize; i++) {
		cout << "- " << data[i] << endl;
	}
	cout << endl;
}