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

	~LinkedList() { delete[] _array; }

	void Add(const T &element)
	{
		if (_maxSize == _counter)
			Expand();
		_array[_counter++] = element;
	}

	T *Remove()
	{
		if (isEmpty())
			return nullptr;
		return &_array[_counter--];
	}

	void Expand()
	{
		_maxSize *= 2;
		T *t = new T[_maxSize];
		for (int i = 0; i < _counter; i++)
			t[i] = _array[i];
		delete _array;
		_array = t;
	}

	bool isEmpty()
	{
		if (_counter == 0)
			return true;
		return false;
	}

	friend ostream &operator<<(ostream &cout, const LinkedList<T> &linkedList) {
		for (int i = linkedList._counter - 1; i >= 0; i--)
			cout << linkedList._array[i] << endl;
		return cout;
	}
};

int main()
{
	LinkedList<int> linkedList;
	linkedList.Add(5);
	linkedList.Add(4);
	linkedList.Add(3);
	linkedList.Add(2);
	linkedList.Add(1);
	linkedList.Add(0);
	linkedList.Remove();
	linkedList.Remove();
	linkedList.Remove();

	cout << linkedList << endl;

	system("PAUSE>0");
}