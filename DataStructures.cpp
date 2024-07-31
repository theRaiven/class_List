// DataStructures.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "List.h"
using namespace std;

auto Max = [](auto x, auto y)
{
	return x < y;
};


int main()
{
	int x1 = 1;
	int x2 = 2;
	int x3 = 3;
	int x4 = 4;
	List<int> list { x1, x2, x3 };

	list.PushBack(x4);
	
	for(int i = 0; i < 7; i++)
	{
		cout << list.PopBack() << " ";
	}
}
