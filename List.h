#include <iostream>
#include <memory>



template <class T>
struct Node
{
	T data{};
	std::shared_ptr<Node<T>> ptrPrev{ nullptr };
	std::shared_ptr<Node<T>> ptrNext{ nullptr };
};



template <class T>
class List
{
private:
	std::shared_ptr<Node<T>> Cell;
	size_t size{ 0 };
	size_t maxSize{ 0 };

public:
	constexpr List() {}
	constexpr List(std::initializer_list<T> firstNodes)
	{
		for(auto _valueToAdd : firstNodes)
		{
			PushBack(_valueToAdd);
		}
	}
	 ~List() { std::cout << "Delete elem" << std::endl; }

	void PushBack(T newData)
	{
		size++; maxSize++;
		if (Cell == nullptr)
		{
			Cell = std::make_shared<Node<T>>();
			Cell->data = newData;
			return;
		}

		std::shared_ptr<Node<T>> _newCell = std::make_shared<Node<T>>();
		std::shared_ptr<Node<T>> _lastCell{ Cell };

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
			Cell = std::make_shared<Node<T>>();
			Cell->data = newData;
			return;
		}

		std::shared_ptr<Node<T>> _newCell = std::make_shared<Node<T>>();

		_newCell->data = newData;
		_newCell->ptrNext = Cell;

		Cell->ptrPrev = _newCell;
		Cell = Cell->ptrPrev;
	}
	decltype(auto) PopBack()
	{
		if (Cell == nullptr)
		{
			return 0;
		}
		size--;
		std::shared_ptr<Node<T>> _tempCell{ Cell };

		if(_tempCell->ptrNext != nullptr)
		{
			while (_tempCell->ptrNext->ptrNext != nullptr)
			{
				_tempCell = _tempCell->ptrNext;
			}
			std::shared_ptr<Node<T>> _lastCell{ _tempCell->ptrNext };

			_tempCell->ptrNext = nullptr;
			_lastCell->ptrPrev = nullptr;

			T _popData{ _lastCell->data };
			// delete _lastCell;
			//_lastCell = nullptr;

			return _popData;
		}
		else
		{
			T _popData{ _tempCell->data };
			//delete _tempCell;
			//_tempCell = nullptr;
			Cell = nullptr;

			return _popData;
		}
	}
	decltype(auto) PopFront()
	{
		if (Cell == nullptr)
		{
			return 0;
		}
		size--;

		if (Cell->ptrNext != nullptr)
		{
			std::shared_ptr<Node<T>> _firstCell{ Cell };
			Cell = Cell->ptrNext;
			Cell->ptrPrev = nullptr;

			T _popData{ _firstCell->data };
			//delete _firstCell;
			return _popData;
		}
		else
		{
			T _popData = Cell->data;
			//delete Cell;
			Cell = nullptr;
			return _popData;
		}
	}

	void Insert(T newData, int index)
	{
		size++; maxSize++;
		std::shared_ptr<Node<T>> _moveCell{ Cell };
		std::shared_ptr<Node<T>> _newCell = std::make_shared<Node<T>>();

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
		std::shared_ptr<Node<T>>  _moveCell{ Cell };

		int i = 0;
		while (_moveCell->ptrNext != nullptr && i < index - 1)
		{
			_moveCell = _moveCell->ptrNext;
			i++;
		}


		if (_moveCell->ptrNext != nullptr)
		{
			std::shared_ptr<Node<T>>  _deleteCell{ _moveCell };

			_moveCell->ptrNext->ptrPrev = _moveCell->ptrPrev;
			_moveCell->ptrPrev->ptrNext = _moveCell->ptrNext;

			//delete _deleteCell;
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
			std::shared_ptr<Node<T>> _deleteCell{ Cell };
			Cell = Cell->ptrNext;
			//delete _deleteCell;
			_deleteCell = nullptr;
			size--;
		}
		maxSize = 0;
	}

	constexpr bool IsEmpty() 
	{
		return Cell == nullptr;
	}
	constexpr size_t Size()
	{
		return size;
	}
	constexpr size_t MaxSize()
	{
		return maxSize;
	}
	constexpr void Print()
	{
		std::shared_ptr<Node<T>> _temp{ Cell };
		while (_temp != nullptr)
		{
			std::cout << _temp->data << ' ';
			_temp = _temp->ptrNext;
		}
	}

	
	decltype(auto) operator[](int index)
	{
		std::shared_ptr<Node<T>> _indexCell{ Cell };
		int i = 0;
		for (i = 0; i < index; i++)
		{
			if (i >= Size())
			{
				std::cerr << "error";
				break;
			}
			_indexCell = _indexCell->ptrNext;
		}
		if (i < Size())
		{
			return _indexCell->data;
		}
	}

	/*std::ostream operator<< (std::ostream& out)
	{
		return out << Cell->data;
	}*/
};