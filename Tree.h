//#include <iostream>
//#include <memory>
//using namespace std;
//
//template <class T>
//struct Node
//{
//	T data;
//	std::unique_ptr<Node<T>> leftChild{ nullptr };
//	std::unique_ptr<Node<T>> rightChild{ nullptr };
//
//	Node()
//	{
//		leftChild = std::make_unique<Node<T>>();
//		rightChild = std::make_unique<Node<T>>();
//	}
//};
//
//template <class T>
//class Tree
//{
//private:
//	std::unique_ptr<Node<T>> Cell;
//	size_t size;
//	size_t maxSize;
//public:
//	Tree() {}
//	Tree(T newData) { Cell->data(newData); }
//
//	decltype(auto) Insert(T newData)
//	{
//		if (Cell == nullptr)
//		{
//			Cell = std::make_unique<Node<T>>();
//			Cell.data;
//		}
//		if (Cell != nullptr)
//		{
//			if (newData < Cell.data)
//			{
//				if (Cell.leftChild == nullptr)
//				{
//					Cell.leftChild = std::make_unique<Node<T>>();
//					Cell.leftChild = new Tree(newData);
//				}
//				else
//				{
//					Cell.leftChild.Insert(newData);
//				}
//			}
//			if (newData >= Cell.data)
//			{
//				if (Cell.rightChild == nullptr)
//				{
//					Cell.rightChild = std::make_unique<Node<T>>();
//					Cell.rightChild = new Tree(newData);
//				}
//				else
//				{
//					Cell.rightChild.Insert(newData);
//				}
//			}
//		}
//	}
//};;