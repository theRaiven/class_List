// DataStructures.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "List.h"

int main()
{
	
	List<int> list1 = 1;
	
	list1.PushBack(2);
	list1.PushBack(4);
	list1.PushBack(5);
	list1.PushFront(1);
	//list1.Clear();
	list1.Print();
	list1.Empty();

}
