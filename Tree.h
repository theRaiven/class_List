#include <iostream>
#include <memory>

template <class T>
struct Node {
	T data;
	std::unique_ptr<Node<T>> leftChild{ nullptr };
	std::unique_ptr<Node<T>> rightChild{ nullptr };
};

template <class T>
class Tree
{
private:
	std::unique_ptr<Node<T>> Cell;
	size_t size;
	size_t maxSize;
public:
	decltype(auto) Insert(T newData)
	{
		if (Cell == nullptr)
		{
			Cell->data
		}
	}
};