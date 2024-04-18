#pragma once

template <typename T>
class DynamicArray
{
	unsigned long int count;
	const int max_count;
	T Elements[1000];
public:
	DynamicArray();
	bool isEmpty() const;
	bool Add(T& newEntry);
	bool Pick(T& FrontEntry);
	int GetCount() const;
	void print() const;
	~DynamicArray();
};

template<typename T>
DynamicArray<T>::DynamicArray() :max_count(1000)
{
	for (int i = 0; i < max_count; i++)
		Elements[i] = NULL;
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
	if (count < max_count - 1)
	{
		Elements[count++] = newEntry;
		return true;
	}
	else return false;
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
		FrontEntry = Elements[y - 1];
		Elements[y - 1] = Elements[count - 1];
		Elements[count - 1] = NULL;
		count--;
		return true;
	}
}

template<typename T>
void DynamicArray<T>::print() const
{
	if (!count)
	{
		cout << "NO ELEMENTS";
		return;
	}
	for (int i = 0; i < count; i++)
	{
		if (count)
		{
			if (i == count - 1) cout << Elements[i];
			else cout << Elements[i] << ",";
		}
	}
}

template<typename T>
int DynamicArray<T>::GetCount() const
{
	return count;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
}