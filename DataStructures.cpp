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

	constexpr int x1{ 1 };
	List<int> list { x1, 2, 3 };

	list.PushBack(4);
	
	for(int i = 0; i < 4; i++)
	{
		cout << list[i] << " ";
	}
	list.Clear();
}
