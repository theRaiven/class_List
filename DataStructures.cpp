// DataStructures.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "List.h"
#include <utility>
#include <chrono>
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
	setlocale(LC_ALL, "rus");
	List<int> myList{ 9,8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8,9 };
	//myList.Print();

	cout << endl;
	myList.Swap(myList(2), myList(3));

	//myList.Print();
	cout << endl;
	auto start{ chrono::high_resolution_clock::now()};
	myList.Sort(0, myList.Size());
	auto end{ chrono::high_resolution_clock::now() };
	chrono::duration<double> direction{ end - start };
	cout << "Сортровка работара: " << direction.count() << " секунд." << endl;

	myList.Print();
	myList.Clear();


}
