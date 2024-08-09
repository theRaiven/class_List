// DataStructures.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "List.h"
#include <utility>
using namespace std;

auto Swap = [](auto x, auto y)
{
	auto temp{ std::move(x) };
	x = std::move(y);
	y = std::move(temp);
};
template<class T>
class Distance
{
private:
	T data;
public:
	decltype(auto) Return()
	{
		return data;
	}
};

template<typename T>
using DistList = List<Distance<T>>;


int main()
{
	/*int a{ 6 };
	int b{ 4 };
	Swap(a, b);
	cout << a << " " << b << endl;*/
	List<int> myList{ 1,3,4,6 };
	
	
	myList.Remove(3);
	myList.Remove(5);
	/*myList.PopFront();
	myList.PopFront();
	myList.PopFront();
	myList.PopFront();*/
	
	myList.PopFront();
	//myList.Print();
	cout << myList;
	myList.Clear();


}
