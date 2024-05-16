#pragma once

template <typename T>
class DynamicArray
{
	enum { MAX_SIZE = 1000 };
private:
	int count;
	T* arr;
public:
	DynamicArray();
	bool isEmpty() const;
	bool Add(T& newEntry);
	bool Pick(T& Entry);
	bool Peek(T& Entry) const;
	int GetCount() const;
	void print() const;
	~DynamicArray();
};

template<typename T>
DynamicArray<T>::DynamicArray()
{
	arr = new T[MAX_SIZE];
	count = 0;
}

template<typename T>
bool DynamicArray<T>::isEmpty() const
{
	return (count == 0);
}

template<typename T>
bool DynamicArray<T>::Add(T& newEntry)
{
	if (count < MAX_SIZE)
	{
		arr[count++] = newEntry;
		return true;
	}
	else return false;
}

template<typename T>
bool DynamicArray<T>::Peek(T& Entry) const
{
	if (count)
	{
		int y = 1 + rand() % (count);
		Entry = arr[y - 1];
		return true;
	}
	else 
	{
		Entry = nullptr;
		return false;
	}
}

template<typename T>
bool DynamicArray<T>::Pick(T& FrontEntry)
{
	if (!count)
	{
		FrontEntry = NULL;
		return false;
	}
	else
	{
		int y = 1 + rand() % (count);
		FrontEntry = arr[y - 1];
		arr[y - 1] = arr[count - 1];
		arr[count - 1] = NULL;
		count--;
		return true;
	}
}

template<typename T>
void DynamicArray<T>::print() const
{
	cout << "[";
	if (!count)
	{
		cout << "]";
		return;
	}
	for (int i = 0; i < count; i++)
	{
		if (count)
		{
			if (i == count - 1) cout << arr[i];
			else cout << arr[i] << " ,";
		}
	}
	cout << "]";
}

template<typename T>
int DynamicArray<T>::GetCount() const
{
	return count;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] arr;
}