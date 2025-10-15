#include <iostream>
using namespace std;

class MyVector
{
	int size;
	int* arr;

public:
	MyVector() :arr(nullptr), size(0) {}
	MyVector(int s) :size(s), arr(new int[size]) {}

	MyVector(const MyVector& obj)
	{
		arr = new int[obj.size];
		for (int i = 0; i < obj.size; i++)
		{
			arr[i] = obj.arr[i];
		}
		size = obj.size;
	}
	MyVector(MyVector&& obj)
	{
		arr = obj.arr;
		obj.arr = nullptr;
		size = obj.size;
		obj.size = 0;
	}
	MyVector& operator=(const MyVector& obj)
	{
		if (obj.arr == arr)
		{
			return *this;
		}
		if (arr != nullptr)
		{
			delete[]arr;
		}
		arr = new int[obj.size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
		size = obj.size;
		return *this;
	}
	MyVector& operator++()
	{
		int* temp = arr;
		arr = new int[size + 1];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
		arr[size] = 0;
		size += 1;
		return *this;
	}
	/*MyVector& operator--()
	{
		size -= 1;
		int* temp = arr;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
		return *this;
	}*/

	MyVector operator++(int)
	{
		MyVector temp = *this;
		int* tempArr = arr;
		arr = new int[size + 1];
		for (int i = 0; i < size; i++)
		{
			arr[i] = tempArr[i];
		}
		arr[size] = 0;
		size += 1;
		return temp;
	}
	MyVector operator--(int)
	{
		MyVector temp = *this;
		size -= 1;
		int* tempArr = arr;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = tempArr[i];
		}
		return temp;
	}


	void Init()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 50;
		}
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << "\t";
		}
		cout << endl;
	}
	~MyVector()
	{
		delete[]arr;
		size = 0;
	}

	int GetSize()const
	{
		return size;
	}
	void SetSize(int a)
	{
		size = a;
	}
	int operator[](int index)
	{
		if (index >= 0 && index < size)
		{
			return arr[index];
		}
		return -1;
	}

	operator int()
	{
		return size;
	}
	void operator() ()
	{
		Print();
	}

	MyVector& operator+=(int num)
	{
		int* temp = arr;
		arr = new int[size + num];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
		for (int i = size; i < size + num; i++)
		{
			arr[i] = 0;
		}
		size += num;
		return *this;
	}
	MyVector& operator-=(int num)
	{
		size -= num;
		int* temp = arr;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
		return *this;
	}
	MyVector& operator*=(int num)
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] *= num;
		}
		return *this;
	}

	MyVector& operator=(MyVector&& obj)
	{
		arr = obj.arr;
		obj.arr = nullptr;
		size = obj.size;
		obj.size = 0;
	}

	void SetElement(int i, int a)
	{
		arr[i] = a;
	}
	void Allocation(int size)
	{
		arr = new int[size];
	}
};

MyVector operator+(int a, MyVector& b)
{
	MyVector res(b.GetSize());
	for (int i = 0; i < b.GetSize(); i++)
	{
		res.SetElement(i, b[i] + a);
	}
	return res;
}
MyVector& operator--(MyVector& a)
{
	int* temp = new int[a.GetSize()];
	for (int i = 0; i < a.GetSize(); i++)
	{
		temp[i] = a[i];
	}
	a.SetSize(a.GetSize() - 1);
	a.Allocation(a.GetSize());
	for (int i = 0; i < a.GetSize(); i++)
	{
		a.SetElement(i, temp[i + 1]);
	}
	return a;
}

istream& operator>>(istream& is, MyVector& obj)
{
	int s;
	cout << "Enter size: ";
	is >> s;
	obj.SetSize(s);
	obj.Allocation(s);
	for (int i = 0; i < s; i++)
	{
		int e;
		cout << "Enter element: ";
		is >> e;
		obj.SetElement(i, e);
	}
	return is;
}

ostream& operator<<(ostream& os, MyVector& obj)
{
	for (int i = 0; i < obj.GetSize(); i++)
	{
		os << obj[i] << "\t";
	}
	return os;
}

int main()
{
	srand(unsigned(time(0)));

	MyVector vec1(10);
	cin >> vec1;
	cout << vec1;
}