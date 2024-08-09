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
	std::shared_ptr<Node<T>> head;
	std::shared_ptr<Node<T>> tail;

	size_t size{ 0 };
	size_t maxSize{ 0 };

	/*void Swap(std::shared_ptr<Node<T>>& _firstCell, std::shared_ptr<Node<T>>& _secondCell)
	{
		auto temp{ std::move(_firstCell->data) };
		_firstCell->data = std::move(_secondCell->data);
		_secondCell->data = std::move(temp);
	}*/

public:
	constexpr List() {}
	constexpr List(std::initializer_list<T> firstNodes)
	{
		for(auto _valueToAdd : firstNodes)
		{
			PushBack(_valueToAdd);
		}
	}
	~List() { Clear(); /*std::cout << "Delete elem" << std::endl;*/ }

	void PushBack(T newData)
	 {
		size++; maxSize++;
		if (head == nullptr)
		{
			head = std::make_shared<Node<T>>();
			head->data = newData;
			tail = head;
			return;
		}

		std::shared_ptr<Node<T>> _newCell = std::make_shared<Node<T>>();
		std::shared_ptr<Node<T>> _lastCell{ tail };


		_newCell->data = newData;
		_newCell->ptrPrev = _lastCell;

		_lastCell->ptrNext = _newCell;

		tail = _newCell;

		return;

	 }
	void PushFront(T newData)
	{
		size++; maxSize++;
		if (head == nullptr)
		{
			head = std::make_shared<Node<T>>();
			head->data = newData;
			tail = head;
			return;
		}

		std::shared_ptr<Node<T>> _newCell = std::make_shared<Node<T>>();

		_newCell->data = newData;
		_newCell->ptrNext = head;

		head->ptrPrev = _newCell;
		head = _newCell;
	}
	decltype(auto) PopBack()
	{
		if (head == nullptr)
		{
			throw std::out_of_range("List is empty");
		}
		size--;

		T _popData = tail->data;
		if (tail->ptrPrev != nullptr)
		{
			tail = tail->ptrPrev;
			tail->ptrNext = nullptr;
		}
		else
		{
			head = tail = nullptr;
		}
		return _popData;
	}
	decltype(auto) PopFront()
	{
		if (head == nullptr)
		{
			throw std::out_of_range("List is empty");
		}
		size--;

		T _popData{ head->data };
		
		if (head->ptrNext != nullptr)
		{
			head = head->ptrNext;
			head->ptrPrev = nullptr;
		}
		else
		{
			head = tail = nullptr;
		}
		return _popData;
	}

	void Insert(T newData, int index)
	{
		if (index < 0 || index > size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		if (index == 0)
		{
			PushFront(newData);
			return;
		}
		size++; maxSize++;
		std::shared_ptr<Node<T>> _moveCell;
		if (index > size/2)
		{
			_moveCell = tail;
		}
		else
		{
			_moveCell = head;
		}
		std::shared_ptr<Node<T>> _newCell = std::make_shared<Node<T>>();

		if (index <= size / 2)
		{
			int i = 0;
			while (_moveCell->ptrNext != nullptr && i < index-1)
			{
				_moveCell = _moveCell->ptrNext;
				i++;
			}
		}
		else
		{
			int i = size - 1;
			while (_moveCell->ptrPrev != nullptr && i > index)
			{
				_moveCell = _moveCell->ptrPrev;
				i--;
			}
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
		if (index < 0 || index >= size)
		{
			std::cerr << "Index out of bounds" << std::endl;
			return;
		}

		if (index == 0)
		{
			PopFront();
			return;
		}

		std::shared_ptr<Node<T>>  _moveCell;
		if (index > size / 2)
		{
			_moveCell = tail;
		}
		else
		{
			_moveCell = head;
		}
		
		if (index <= size / 2)
		{
			int i = 0;
			while (_moveCell->ptrNext != nullptr && i < index - 1)
			{
				_moveCell = _moveCell->ptrNext;
				i++;
			}
		}
		else
		{
			int i = size-1;
			while (_moveCell->ptrPrev != nullptr && i > index)
			{
				_moveCell = _moveCell->ptrPrev;
				i--;
			}
		}

		if (_moveCell->ptrNext && _moveCell->ptrPrev)
		{
			_moveCell->ptrNext->ptrPrev = _moveCell->ptrPrev;
			_moveCell->ptrPrev->ptrNext = _moveCell->ptrNext;
		}

		if(_moveCell->ptrNext == nullptr)
		{
			PopBack();
			return;
		}
		else
		{
			size--;
		}
	}
	void Clear()
	{
		while (head != nullptr)
		{
			std::shared_ptr<Node<T>> _nextCell = head->ptrNext;
			head->ptrNext = nullptr;
			head->ptrPrev = nullptr;
			head = _nextCell;
		}
		tail = nullptr;
		size = 0;
		maxSize = 0;
	}
	/*void QuickSort(size_t left, size_t right)
	{
		if (left >= right) return;
		
		std::shared_ptr<Node<T>> _startCell{ Cell };
 		std::shared_ptr<Node<T>> _endCell{ Cell };
		
		for (size_t i = 0; i < left; ++i)
		{
			_startCell = _startCell->ptrNext;
		}
		
		for (size_t i = 0; i < right; ++i)
		{
			_endCell = _endCell->ptrNext;
		}

		T pivot{ _startCell->data };

		std::shared_ptr<Node<T>> iCell{ _startCell };
		std::shared_ptr<Node<T>> jCell{ _endCell };

		while (iCell != jCell)
		{
			while (iCell->data < pivot)
			{
				iCell = iCell->ptrNext;
				if (iCell == nullptr) break;
			}
			while (jCell->data > pivot)
			{
				jCell = jCell->ptrPrev;
				if (jCell == nullptr) break;
			}
			if (iCell != nullptr && jCell != nullptr && iCell != jCell)
			{
				Swap(iCell, jCell);
			}
		}

		if (_startCell != jCell)
		{
			QuickSort(left, right - 1); // "Левый кусок"
		}
		if (_endCell != iCell)
		{
			QuickSort(left + 1, right); // "Правый кусок"
		}
	}*/

	constexpr bool IsEmpty() const 
	{
		return head == nullptr;
	}
	constexpr size_t Size() const
	{
		return size;
	}
	constexpr size_t MaxSize() const
	{
		return maxSize;
	}
	constexpr void Print()
	{
		std::shared_ptr<Node<T>> _temp{ head };
		while (_temp != nullptr)
		{
			std::cout << _temp->data << ' ';
			_temp = _temp->ptrNext;
		}
	}

	
	decltype(auto) operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		std::shared_ptr<Node<T>> _indexCell = head;
		for (int i = 0; i < index; i++)
		{
			_indexCell = _indexCell->ptrNext;
		}
		return _indexCell->data;
	}

	friend std::ostream& operator<<(std::ostream& out, List<T>& list)
	{
		for (int i = 0; i< list.Size(); i++)
		{
			out << list[i] << " ";
		}
		return out;
	}
};



template <class T>
class Stack : List<T>
{
public:
	constexpr Stack(std::initializer_list<T> firstNodes)
	{
		for (auto _valueToAdd : firstNodes)
		{
			PushFront(_valueToAdd);
		}
	}
	~Stack() { std::cout << "Delete elem" << std::endl; }

	using List<T>::PushFront;
	using List<T>::PopFront;

	using List<T>::Clear;

	using List<T>::IsEmpty;
	using List<T>::Size;
	using List<T>::MaxSize;
	using List<T>::Print;

	using List<T>::operator[];
};

template <class T>
class Queue : List<T>
{
public:
	constexpr Queue(std::initializer_list<T> firstNodes)
	{
		for (auto _valueToAdd : firstNodes)
		{
			PushBack(_valueToAdd);
		}
	}
	~Queue() { std::cout << "Delete elem" << std::endl; }

	using List<T>::PushBack;
	using List<T>::PopFront;

	using List<T>::Clear;

	using List<T>::IsEmpty;
	using List<T>::Size;
	using List<T>::MaxSize;
	using List<T>::Print;

	using List<T>::operator[];
};