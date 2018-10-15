#include <iostream>
using namespace std;

template <class T>
class Node {
	T _info;
	Node *_link;
public:

	T getInfo() const { return _info; }
	Node *getLink() const { return _link; }
	void setLink(Node *link = nullptr) { _link = link; }
	void addLink(const T& element) { _link = new Node(element, nullptr); }

	Node() { _link = nullptr; }

	Node(const T &info, Node *link) {
		_info = info;
		_link = link;
	}

	~Node() { _link = nullptr; }

	friend ostream &operator<<(ostream &cout, const Node<T> *node) {
		if (node != nullptr)
		{
			cout << node->_info << endl;
			if (node->_link != nullptr)
				cout << node->_link << endl;
			return cout;
		}
		else
		{
			cout << "List is empty." << endl;
			return cout;
		}
	}

};

template <class T>
class LinkedList {
	int _maxSize;
	T *_array;
	int _counter;

public:
	LinkedList()
	{
		_maxSize = 20;
		_array = new T[_maxSize];
		_counter = 0;
	}

	~LinkedList()
	{
		delete[] _array;
	}


	void AddFirst(const T &element)
	{
		if (_counter == _maxSize)
			Expand();
		for (int i = _counter; i >= 1; i--)
			_array[i] = _array[i - 1];
		_array[0] = element;
		_counter++;
	}

	void RemoveFirst()
	{
		for (int i = 0; i < _counter; i++)
			_array[i - 1] = _array[i];
		--_counter;
	}

	void AddLast(const T &element)
	{
		if (_counter == _maxSize)
			Expand();
		_array[_counter++] = element;
	}

	void RemoveLast(const T &element)
	{
		if (_array == nullptr)
			return;

		_counter--;
	}
	
	void Expand()
	{
		_maxSize *= 2;
		T * t = new T[_maxSize];
		for (int i = 0; i < _counter; i++)
			t[i] = _array[i];
		delete[] _array;

		t = _array;
	}

	friend ostream &operator<<(ostream &cout, const LinkedList<T> &linkedList) {
		cout << "[ ";
		for (int i = 0; i < linkedList._counter; i++)
			cout << linkedList._array[i] << ", ";
		cout << "]";
		return cout;
	}
};

int main()
{
	LinkedList<int> linkedList;
	linkedList.AddFirst(5);
	linkedList.AddFirst(4);
	linkedList.AddFirst(3);
	linkedList.AddFirst(2);
	linkedList.AddFirst(1);
	
	cout << linkedList << endl;

	system("PAUSE>0");
}