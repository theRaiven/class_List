#include <iostream>

template <class T>
struct Node
{
	T data;
	Node* ptrNext;
	Node* ptrPrev;
	Node()
	{
		data = {};
		ptrNext = nullptr;
		ptrPrev = nullptr;
	}
};

template <class T>
class List
{
private:
	Node<T>* Cell;
	size_t size = 0;
	size_t maxSize = 0;
public:
	List() {}
	List(T newData)
	{
		Cell = new Node<T>;
		Cell->data = newData;
		size++;
		maxSize++;
	}

	void PushBack(T newData)
	{
		size++; maxSize++;
		if (Cell == nullptr)
		{
			Cell = new Node<T>;
			Cell->data = newData;
			return;
		}

		Node<T>* _newCell = new Node<T>;
		Node<T>* _lastCell = Cell;

		while (_lastCell->ptrNext != nullptr)
		{
			_lastCell = _lastCell->ptrNext;
		}

		_newCell->data = newData;
		_newCell->ptrPrev = _lastCell;

		_lastCell->ptrNext = _newCell;

		return;

	}
	void PushFront(T newData)
	{
		size++; maxSize++;
		if (Cell == nullptr)
		{
			Cell = new Node<T>;
			Cell->data = newData;
			return;
		}

		Node<T>* _newCell = new Node<T>;

		_newCell->data = newData;
		_newCell->ptrNext = Cell;

		Cell->ptrPrev = _newCell;
		Cell = Cell->ptrPrev;
	}
	decltype(auto) PopBack()
	{
		size--;
		if (Cell == nullptr)
		{
			return NULL;
		}
		Node<T>* _tempCell = Cell;
		while (_tempCell->ptrNext->ptrNext != nullptr)
		{
			_tempCell = _tempCell->ptrNext;
		}
		Node<T>* _lastCell = _tempCell->ptrNext;

		_tempCell->ptrNext = nullptr;
		_lastCell->ptrPrev = nullptr;

		T _popData = _lastCell->data;
		delete _lastCell;

		return _popData;
	}
	decltype(auto) PopFront()
	{
		size--;
		if (Cell == nullptr)
		{
			return NULL;
		}

		Node<T>* _firstCell = Cell;
		Cell = Cell->ptrNext;
		Cell->ptrPrev = nullptr;

		T _popData = _firstCell->data;
		delete _firstCell;
		return _popData;
	}

	void Insert(T newData, int index)
	{
		size++; maxSize++;
		Node<T>* _moveCell = Cell;
		Node<T>* _newCell = new Node<T>;

		int i = 1;
		while (_moveCell->ptrNext != nullptr && i < index - 1)
		{
			_moveCell = _moveCell->ptrNext;
			i++;
		}

		_newCell->data = newData;
		_newCell->ptrNext = _moveCell->ptrNext;
		_newCell->ptrPrev = _moveCell;

		if (_moveCell->ptrNext != nullptr)
		{
			_moveCell->ptrNext->ptrPrev = _newCell;
		}
		_moveCell->ptrNext = _newCell;
	}
	void Remove(int index)
	{
		size--;
		Node<T>* _moveCell = Cell;

		int i = 0;
		while (_moveCell->ptrNext != nullptr && i < index - 1)
		{
			_moveCell = _moveCell->ptrNext;
			i++;
		}


		if (_moveCell->ptrNext != nullptr)
		{
			Node<T>* _deleteCell = _moveCell;

			_moveCell->ptrNext->ptrPrev = _moveCell->ptrPrev;
			_moveCell->ptrPrev->ptrNext = _moveCell->ptrNext;

			delete _deleteCell;
		}
		else
		{
			PopBack();
		}
	}
	void Clear()
	{
		while (size != 0)
		{
			Node<T>* _deleteCell = Cell;
			Cell = Cell->ptrNext;
			delete _deleteCell;
			_deleteCell = nullptr;
			size--;
		}
	}

	bool Empty() const
	{
		if (Cell != nullptr)
		{
			return false;
		}
		return true;
	}
	int Size()
	{
		return size;
	}
	int MaxSize()
	{
		return maxSize;
	}
	void Print()
	{
		Node<T>* _temp = Cell;
		while (_temp != nullptr)
		{
			std::cout << _temp->data << ' ';
			_temp = _temp->ptrNext;
		}
	}
};