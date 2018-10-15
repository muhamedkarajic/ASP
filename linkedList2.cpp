#include <iostream>
using namespace std;

const char *crt = "\n- - - - - - - - - - - - - - - - - - - - \n";


template <class T>
class Node {
	T _info;
	Node *_link;
public:

	T getInfo() const { return _info; }
	Node *getLink() const { return _link; }
	void setLink(Node *link = nullptr) { _link = link; }
	void addLink(const T& element) { _link = new Node(element,nullptr); }

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
	Node<T> *_node;
public:
	bool isEmpty()
	{
		if (_node == nullptr)
			return true;
		return false;
	}

	void RemoveFirst()
	{
		if (_node == nullptr)
			return;

		Node<T> *temp = _node;
		_node = _node->getLink();
		//temp->setLink(nullptr);

		delete temp;
	}

	void RemoveLast()
	{
		if (_node == nullptr)
			return;

		Node<T> *before = nullptr;
		Node<T> *counter = _node;
		while (counter->getLink() != nullptr)
		{
			before = counter;
			counter = counter->getLink();
		}

		if (before != nullptr)
			before->setLink();
		else
			_node = nullptr;

		delete counter;
		
	}

	LinkedList() { _node = nullptr; }
	
	void AddFirst(const T& element)
	{
		Node<T> *t = new Node<T>(element, _node);
		_node = t;
	}

	void AddLast(const T& element)
	{
		if (_node == nullptr)
		{
			AddFirst(element);
			return;
		}

		Node<T> *t = _node;
		while (t->getLink() != nullptr)
			t = t->getLink();

		t->addLink(element);
	}

	friend ostream &operator<<(ostream &cout, const LinkedList<T> &linkedList) {
		cout << linkedList._node;
		return cout;
	}

};


int main()
{
	LinkedList<int> linkedList;
	linkedList.AddFirst(3);
	linkedList.AddFirst(2);
	linkedList.AddFirst(1);
	linkedList.AddLast(8);
	linkedList.AddLast(7);

	cout << linkedList << crt;
	linkedList.RemoveFirst();
	linkedList.RemoveLast();
	cout << linkedList << endl;

	system("PAUSE>0");
}